import QtQuick 2.9
import QtQuick.Controls 2.2
import CloudPlayAPI 1.0

ApplicationWindow {
    id: window
    title: "CloudPlay API Test"
    width: 400
    height: 300
    visible: true

    CloudPlayAPI {
        id: cloudPlayAPI
        
        onAuthenticationSuccess: {
            console.log("Authentication successful!")
            statusText.text = "Authentication successful!"
        }
        
        onAuthenticationError: function(error) {
            console.log("Authentication failed:", error)
            statusText.text = "Authentication failed: " + error
        }
        
        onComputersReceived: function(computers) {
            console.log("Received computers:", computers)
            statusText.text = "Received " + computers.length + " computers"
        }
        
        onApiError: function(error) {
            console.log("API Error:", error)
            statusText.text = "API Error: " + error
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "CloudPlay API Test"
            font.pointSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Column {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Row {
                spacing: 10
                TextField {
                    id: usernameField
                    placeholderText: "Username"
                    width: 150
                }
                TextField {
                    id: passwordField
                    placeholderText: "Password"
                    echoMode: TextInput.Password
                    width: 150
                }
            }

            Button {
                text: "Login"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    if (usernameField.text && passwordField.text) {
                        cloudPlayAPI.authenticate(usernameField.text, passwordField.text)
                        statusText.text = "Authenticating..."
                    } else {
                        statusText.text = "Please enter username and password"
                    }
                }
            }

            Button {
                text: "Get Computers"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    cloudPlayAPI.getComputers()
                    statusText.text = "Getting computers..."
                }
            }
        }

        Text {
            id: statusText
            text: "Ready"
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            width: parent.parent.width - 40
        }
    }
}