import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3

import CloudPlayAPI 1.0

Item {
    id: dashboard
    
    property var cloudPlayAPI: CloudPlayAPI
    
    Component.onCompleted: {
        // Connect CloudPlayAPI signals
        cloudPlayAPI.loginSuccess.connect(function(userData) {
            console.log("CloudPlay login successful:", userData.username)
            userInfo.text = "Welcome, " + userData.username
            balanceText.text = "Balance: $" + userData.balance
            loadDashboardData()
        })
        
        cloudPlayAPI.loginError.connect(function(error) {
            console.log("CloudPlay login error:", error)
            errorText.text = "Login failed: " + error
        })
    }
        
        onLoginError: function(error) {
            console.log("CloudPlay login error:", error)
            errorDialog.text = "Login Error: " + error
            errorDialog.open()
        }
        
        onComputersReceived: function(computers) {
            console.log("Computers received:", JSON.stringify(computers))
            updateComputerList(computers)
        }
        
        onIpAddressesReceived: function(addresses) {
            console.log("IP addresses received:", JSON.stringify(addresses))
            updateIPList(addresses)
        }
    }
    
    function loadDashboardData() {
        cloudPlayAPI.getAvailableComputers()
        cloudPlayAPI.getIPAddresses()
    }
    
    function updateComputerList(computers) {
        computerModel.clear()
        if (computers.success && computers.result) {
            for (var i = 0; i < computers.result.length; i++) {
                var comp = computers.result[i]
                computerModel.append({
                    "computerNumber": comp.computer_number || (i + 1),
                    "status": comp.status || "Available",
                    "ipAddress": comp.ip_address || "Not assigned",
                    "user": comp.assigned_user || "None"
                })
            }
        }
    }
    
    function updateIPList(addresses) {
        ipModel.clear()
        if (addresses && addresses.length > 0) {
            for (var i = 0; i < addresses.length; i++) {
                var addr = addresses[i]
                ipModel.append({
                    "id": addr.id || i,
                    "address": addr.address || addr,
                    "status": addr.active ? "Active" : "Inactive",
                    "created": addr.created_at || "Unknown"
                })
            }
        }
    }
    
    Rectangle {
        anchors.fill: parent
        color: Material.backgroundColor
        
        ScrollView {
            anchors.fill: parent
            anchors.margins: 20
            
            ColumnLayout {
                width: parent.width
                spacing: 20
                
                // Header Section
                Rectangle {
                    Layout.fillWidth: true
                    height: 80
                    color: Material.primary
                    radius: 8
                    
                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        
                        Column {
                            Layout.fillWidth: true
                            
                            Text {
                                id: userInfo
                                text: "CloudPlay Dashboard"
                                font.pixelSize: 24
                                font.bold: true
                                color: "white"
                            }
                            
                            Text {
                                id: balanceText
                                text: "Please login to continue"
                                font.pixelSize: 14
                                color: "white"
                                opacity: 0.8
                            }
                        }
                        
                        RowLayout {
                            spacing: 10
                            
                            Button {
                                id: loginButton
                                text: cloudPlayAPI.authenticated ? "Logout" : "Login"
                            Material.background: Material.accent
                            
                            onClicked: {
                                if (cloudPlayAPI.authenticated) {
                                    cloudPlayAPI.logout()
                                    userInfo.text = "CloudPlay Dashboard"
                                    balanceText.text = "Please login to continue"
                                } else {
                                    loginDialog.open()
                                }
                            }
                            }
                            
                            Button {
                                text: "Sync with Moonlight"
                                enabled: cloudPlayAPI.authenticated
                                Material.background: Material.Teal
                                
                                onClicked: {
                                    cloudPlayAPI.syncProfilesWithMoonlight()
                                }
                            }
                            
                            Button {
                                text: "Add IPs to Moonlight"
                                enabled: cloudPlayAPI.authenticated
                                Material.background: Material.Blue
                                
                                onClicked: {
                                    cloudPlayAPI.addCloudPlayIPsToMoonlight()
                                }
                            }
                        }
                    }
                }
                
                // Computer Management Section
                GroupBox {
                    Layout.fillWidth: true
                    title: "Available Computers"
                    Material.foreground: Material.primary
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        RowLayout {
                            Layout.fillWidth: true
                            
                            Button {
                                text: "Refresh"
                                onClicked: cloudPlayAPI.getAvailableComputers()
                            }
                            
                            Button {
                                text: "Auto Assign"
                                onClicked: cloudPlayAPI.assignComputerData(1)
                            }
                            
                            Item { Layout.fillWidth: true }
                        }
                        
                        ListView {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 200
                            model: ListModel { id: computerModel }
                            
                            delegate: Rectangle {
                                width: parent.width
                                height: 60
                                color: index % 2 == 0 ? Material.backgroundColor : Qt.darker(Material.backgroundColor, 1.1)
                                border.color: Material.dividerColor
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    
                                    Text {
                                        text: "Computer " + computerNumber
                                        font.bold: true
                                        color: Material.foreground
                                    }
                                    
                                    Text {
                                        text: "IP: " + ipAddress
                                        color: Material.foreground
                                    }
                                    
                                    Text {
                                        text: "Status: " + status
                                        color: status === "Available" ? Material.Green : Material.Orange
                                    }
                                    
                                    Item { Layout.fillWidth: true }
                                    
                                    Button {
                                        text: "Connect"
                                        enabled: status === "Available"
                                        Material.background: Material.Green
                                        
                                        onClicked: {
                                            // Connect to this computer via Moonlight
                                            cloudPlayAPI.autoConnectToCloudPlay(ipAddress)
                                            console.log("Connecting to computer", computerNumber, "at", ipAddress)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                // IP Address Management Section
                GroupBox {
                    Layout.fillWidth: true
                    title: "IP Address Management"
                    Material.foreground: Material.primary
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        RowLayout {
                            Layout.fillWidth: true
                            
                            TextField {
                                id: newIPField
                                Layout.fillWidth: true
                                placeholderText: "Enter new IP address (e.g. 192.168.1.100)"
                            }
                            
                            Button {
                                text: "Add IP"
                                onClicked: {
                                    if (newIPField.text.length > 0) {
                                        cloudPlayAPI.createIPAddress(newIPField.text)
                                        newIPField.text = ""
                                    }
                                }
                            }
                            
                            Button {
                                text: "Refresh"
                                onClicked: cloudPlayAPI.getIPAddresses()
                            }
                        }
                        
                        ListView {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 150
                            model: ListModel { id: ipModel }
                            
                            delegate: Rectangle {
                                width: parent.width
                                height: 50
                                color: index % 2 == 0 ? Material.backgroundColor : Qt.darker(Material.backgroundColor, 1.1)
                                border.color: Material.dividerColor
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    
                                    Text {
                                        text: address
                                        font.bold: true
                                        color: Material.foreground
                                    }
                                    
                                    Text {
                                        text: status
                                        color: status === "Active" ? Material.Green : Material.Red
                                    }
                                    
                                    Item { Layout.fillWidth: true }
                                    
                                    Button {
                                        text: status === "Active" ? "Deactivate" : "Activate"
                                        Material.background: status === "Active" ? Material.Red : Material.Green
                                        
                                        onClicked: {
                                            cloudPlayAPI.toggleIPActive(id.toString())
                                        }
                                    }
                                    
                                    Button {
                                        text: "Delete"
                                        Material.background: Material.Red
                                        
                                        onClicked: {
                                            cloudPlayAPI.deleteIPAddress(id.toString())
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                // Gaming Profile Management Section
                GroupBox {
                    title: "Gaming Profiles"
                    Layout.fillWidth: true
                    visible: cloudPlayAPI.authenticated
                    Material.theme: Material.Dark
                    
                    ColumnLayout {
                        anchors.fill: parent
                        
                        RowLayout {
                            spacing: 10
                            
                            Button {
                                text: "Load Profiles"
                                Material.background: Material.Blue
                                
                                onClicked: {
                                    cloudPlayAPI.getGamingProfiles()
                                }
                            }
                            
                            Button {
                                text: "Create New Profile"
                                Material.background: Material.Green
                                
                                onClicked: {
                                    createProfileDialog.open()
                                }
                            }
                            
                            Item { Layout.fillWidth: true }
                        }
                        
                        ListView {
                            id: profileListView
                            Layout.fillWidth: true
                            Layout.preferredHeight: 200
                            
                            model: ListModel {
                                id: profileModel
                            }
                            
                            delegate: Rectangle {
                                width: parent.width
                                height: 80
                                color: Material.backgroundColor
                                border.color: Material.dividerColor
                                border.width: 1
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    
                                    Column {
                                        Layout.fillWidth: true
                                        
                                        Text {
                                            text: name || "Unnamed Profile"
                                            font.bold: true
                                            color: Material.foreground
                                        }
                                        
                                        Text {
                                            text: "Game ID: " + (game_id || "N/A")
                                            color: Material.foreground
                                            opacity: 0.7
                                        }
                                        
                                        Text {
                                            text: "Created: " + (created_at || "Unknown")
                                            color: Material.foreground
                                            opacity: 0.5
                                        }
                                    }
                                    
                                    Button {
                                        text: "Start Session"
                                        Material.background: Material.Teal
                                        
                                        onClicked: {
                                            // Start gaming session with this profile
                                            cloudPlayAPI.startGamingSession(id, "192.168.1.100")
                                        }
                                    }
                                    
                                    Button {
                                        text: "Edit"
                                        Material.background: Material.Orange
                                        
                                        onClicked: {
                                            // Open edit dialog
                                            editProfileDialog.currentProfile = model
                                            editProfileDialog.open()
                                        }
                                    }
                                    
                                    Button {
                                        text: "Delete"
                                        Material.background: Material.Red
                                        
                                        onClicked: {
                                            cloudPlayAPI.deleteGamingProfile(id)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                Item { Layout.fillHeight: true }
            }
        }
    }
    
    // Login Dialog
    Dialog {
        id: loginDialog
        title: "CloudPlay Login"
        modal: true
        anchors.centerIn: parent
        width: 400
        height: 300
        
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            
            TextField {
                id: usernameField
                Layout.fillWidth: true
                placeholderText: "Username"
                text: "muslimuz"
            }
            
            TextField {
                id: passwordField
                Layout.fillWidth: true
                placeholderText: "Password"
                echoMode: TextInput.Password
                text: "Muslim123@"
            }
            
            RowLayout {
                Layout.fillWidth: true
                
                Button {
                    text: "Cancel"
                    onClicked: loginDialog.close()
                }
                
                Item { Layout.fillWidth: true }
                
                Button {
                    text: "Login"
                    Material.background: Material.primary
                    
                    onClicked: {
                        if (usernameField.text && passwordField.text) {
                            cloudPlayAPI.loginUser(usernameField.text, passwordField.text)
                            loginDialog.close()
                        }
                    }
                }
            }
        }
    }
    
    // Error Dialog
    Dialog {
        id: errorDialog
        property alias text: errorText.text
        title: "Error"
        modal: true
        anchors.centerIn: parent
        
        Text {
            id: errorText
            color: Material.foreground
        }
        
        Button {
            text: "OK"
            onClicked: errorDialog.close()
        }
    }
    
    // Create Gaming Profile Dialog
    Dialog {
        id: createProfileDialog
        title: "Create Gaming Profile"
        modal: true
        anchors.centerIn: parent
        width: 400
        height: 300
        
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            
            TextField {
                id: profileNameField
                Layout.fillWidth: true
                placeholderText: "Profile Name"
            }
            
            TextField {
                id: gameIdField
                Layout.fillWidth: true
                placeholderText: "Game ID"
            }
            
            RowLayout {
                Layout.fillWidth: true
                
                Button {
                    text: "Create"
                    Material.background: Material.Green
                    
                    onClicked: {
                        cloudPlayAPI.createGamingProfile(profileNameField.text, gameIdField.text)
                        createProfileDialog.close()
                        profileNameField.text = ""
                        gameIdField.text = ""
                    }
                }
                
                Button {
                    text: "Cancel"
                    onClicked: {
                        createProfileDialog.close()
                        profileNameField.text = ""
                        gameIdField.text = ""
                    }
                }
            }
        }
    }
    
    // Edit Gaming Profile Dialog
    Dialog {
        id: editProfileDialog
        property var currentProfile: null
        title: "Edit Gaming Profile"
        modal: true
        anchors.centerIn: parent
        width: 400
        height: 300
        
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            
            TextField {
                id: editProfileNameField
                Layout.fillWidth: true
                placeholderText: "Profile Name"
                text: editProfileDialog.currentProfile ? editProfileDialog.currentProfile.name : ""
            }
            
            TextField {
                id: editGameIdField
                Layout.fillWidth: true
                placeholderText: "Game ID"
                text: editProfileDialog.currentProfile ? editProfileDialog.currentProfile.game_id : ""
            }
            
            RowLayout {
                Layout.fillWidth: true
                
                Button {
                    text: "Update"
                    Material.background: Material.Orange
                    
                    onClicked: {
                        if (editProfileDialog.currentProfile) {
                            var settings = {
                                "name": editProfileNameField.text,
                                "game_id": editGameIdField.text
                            }
                            cloudPlayAPI.updateGamingProfile(editProfileDialog.currentProfile.id, settings)
                        }
                        editProfileDialog.close()
                    }
                }
                
                Button {
                    text: "Cancel"
                    onClicked: editProfileDialog.close()
                }
            }
        }
    }
    
    // CloudPlay API Signal Connections
    Connections {
        target: cloudApi
        
        function onCloudPlayIPsAdded(count) {
            console.log("Added " + count + " CloudPlay IPs to Moonlight")
        }
        
        function onProfilesSynced(success) {
            console.log("Profiles synced with Moonlight:", success)
        }
        
        function onAutoConnectionResult(success, message) {
            console.log("Auto-connection result:", success, message)
        }
        
        // Gaming Profile Signal Handlers
        function onGamingProfilesReceived(profiles) {
            console.log("Gaming profiles received:", profiles.length)
            profileModel.clear()
            for (var i = 0; i < profiles.length; i++) {
                profileModel.append(profiles[i])
            }
        }
        
        function onGamingProfileCreated(profile) {
            console.log("Gaming profile created:", profile.name)
            profileModel.append(profile)
        }
        
        function onGamingProfileUpdated(profileId) {
            console.log("Gaming profile updated:", profileId)
            // Refresh the profiles list
            cloudPlayAPI.getGamingProfiles()
        }
        
        function onGamingProfileDeleted(profileId) {
            console.log("Gaming profile deleted:", profileId)
            // Remove from model
            for (var i = 0; i < profileModel.count; i++) {
                if (profileModel.get(i).id === profileId) {
                    profileModel.remove(i)
                    break
                }
            }
        }
        
        function onGamingSessionStarted(sessionId, streamUrl) {
            console.log("Gaming session started:", sessionId, "URL:", streamUrl)
            // Here we could launch Moonlight with the stream URL
        }
    }
    
    Component.onCompleted: {
        console.log("CloudPlay Dashboard loaded")
        // Auto-login with CloudPlay credentials
        cloudPlayAPI.loginUser("muslimuz", "Muslim123@")
    }
}