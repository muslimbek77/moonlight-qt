#!/usr/bin/env qml
import QtQuick 2.9
import QtQuick.Controls 2.2
import CloudPlayAPI 1.0

ApplicationWindow {
    id: window
    title: "Moonlight CloudPlay Test"
    width: 600
    height: 400
    visible: true

    CloudPlayAPI {
        id: cloudPlayAPI
        
        Component.onCompleted: {
            console.log("CloudPlay API initialized successfully!")
            console.log("Base URL:", baseUrl())
            setBaseUrl("https://ctrl.cloudplay.uz/api/")
            console.log("Updated Base URL:", baseUrl())
        }
        
        onLoginSuccess: function(token, username) {
            statusLabel.text = "Muvaffaqiyatli login: " + username
            statusLabel.color = "green"
            console.log("Login successful:", username, token)
        }
        
        onLoginFailed: function(error) {
            statusLabel.text = "Login xatosi: " + error  
            statusLabel.color = "red"
            console.log("Login failed:", error)
        }
        
        onAvailableComputersReceived: function(computers) {
            statusLabel.text = "Kompyuterlar soni: " + computers.length
            statusLabel.color = "blue"
            console.log("Computers received:", computers.length)
        }
        
        onApiError: function(error) {
            statusLabel.text = "API xatosi: " + error
            statusLabel.color = "red"
            console.log("API error:", error)
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width - 40

        Text {
            text: "Moonlight CloudPlay Integration Test"
            font.pointSize: 18
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: parent.width
            height: 200
            color: "#f0f0f0"
            border.color: "#ccc"
            radius: 5

            Column {
                anchors.centerIn: parent
                spacing: 15

                Row {
                    spacing: 10
                    Text { text: "Username:"; width: 100 }
                    TextField {
                        id: usernameField
                        placeholderText: "Username kiriting"
                        width: 200
                    }
                }

                Row {
                    spacing: 10
                    Text { text: "Password:"; width: 100 }
                    TextField {
                        id: passwordField
                        placeholderText: "Password kiriting"
                        echoMode: TextInput.Password
                        width: 200
                    }
                }

                Row {
                    spacing: 10
                    Button {
                        text: "Login"
                        onClicked: {
                            if (usernameField.text && passwordField.text) {
                                statusLabel.text = "Login qilinmoqda..."
                                statusLabel.color = "orange"
                                cloudPlayAPI.loginUser(usernameField.text, passwordField.text)
                            } else {
                                statusLabel.text = "Username va password kiriting!"
                                statusLabel.color = "red"
                            }
                        }
                    }

                    Button {
                        text: "Kompyuterlarni olish"
                        onClicked: {
                            statusLabel.text = "Kompyuterlar yuklanmoqda..."
                            statusLabel.color = "orange"
                            cloudPlayAPI.getAvailableComputers()
                        }
                    }
                }
            }
        }

        Text {
            id: statusLabel
            text: "CloudPlay API tayyor"
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            width: parent.width
        }

        Text {
            text: "CloudPlay API muvaffaqiyatli integratsiya qilindi!\n" +
                  "API Base URL: " + cloudPlayAPI.baseUrl() + "\n" +
                  "Authentication holati: " + (cloudPlayAPI.isAuthenticated() ? "Autentifikatsiya qilingan" : "Autentifikatsiya qilinmagan")
            font.pointSize: 10
            color: "#666"
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            width: parent.width
        }
    }
}