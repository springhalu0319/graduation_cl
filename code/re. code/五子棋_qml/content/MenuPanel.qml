import Qt 4.7

Item {
    id: menuPanel
    width: parent.width
    height: parent.height

    property bool fluid3D: switch3D.on

    Item {
        id: minimizeButton
        width: 80
        height: 80
        anchors.top: parent.top
        anchors.left: parent.left
        Image {
            source: "images/minimize.png"
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                mainWidget.minimizeWindow();
            }
        }
    }

    Item {
        id: exitButton
        width: 80
        height: 80
        anchors.top: parent.top
        anchors.right: parent.right

        Image {
            source: "images/close.png"
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                mainWidget.exitApplication()
            }
        }
    }

    Frame {
        id: menuPanelFrame
        width: 540
        height: 370
        anchors.centerIn: parent

        Image {
            id: gameLogo
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            source: "images/tile_button1.png"
            Text {
                anchors.centerIn: parent
                font.family: "Helvetica"
                font.pointSize: 28
                smooth: true
                color: "white"
                style: Text.Outline
                styleColor: "black"
                text: qsTr("5-in-a-row")
            }
        }
        Row {
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.top: gameLogo.bottom
            anchors.margins: 10
            spacing: 10

            Frame {
                id: aboutArea
                height: 270
                width: 290
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#ffffff" }
                    GradientStop { position: 1.0; color: "#eeeeee" }
                }

                Flickable {
                    id: aboutAreaFlickable
                    anchors.fill: parent
                    contentWidth: aboutArea.width
                    contentHeight: aboutAreaText.height + aboutAreaLogo.height + 20
                    flickableDirection: Flickable.VerticalFlick
                    clip: true
                    Text {
                        id: aboutAreaText
                        width: parent.width - 20
                        anchors.horizontalCenter: parent.horizontalCenter
                        wrapMode: Text.WordWrap
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "Helvetica"
                        font.pointSize: 15
                        text: qsTr("\nGame logic is implemented with Qt C++ and the UI with QML Declarative UI.\n")
                    }
                    Image {
                        id: aboutAreaLogo
                        source: "images/quit.png"
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: aboutAreaText.bottom
                        anchors.topMargin: 10
                    }
                }
            }

            Column {
                width: parent.width - aboutArea.width - 10
                spacing: 10

                Button {
                    id: button1PlayerGame
                    text: qsTr("1 Player Game")
                    disabled: true
                    onClicked: {
                        // TODO: Implement 1 player game
                    }
                }
                Button {
                    id: button2PlayerGame
                    text: qsTr("2 Players Game")
                    onClicked: {
                        gameData.resetGame()
                        gameView.centerBoard()
                        menuPanel.state = "hide"
                        gameData.pauseGame(false)
                    }
                }
                Switch {
                    id: switch3D
                    textOff: "2D"
                    textOn: "3D"
                }

                Button {
                    id: buttonContinue
                    text: qsTr("Continue Game")
                    // "Continue" button is enabled only when game is on
                    disabled: {
                        if (!gameData.gameOn)
                            return true
                        else
                            return false
                    }
                    onClicked: {
                        menuPanel.state = "hide"
                        gameData.pauseGame(false)
                    }
                }
            }
        }
    }

    states: [
    State {
        name: "hide"
        PropertyChanges {
            target: menuPanel
            opacity: 0.0
            y: -menuPanelFrame.height
        }
    }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity, y"
            duration: 400
        }
    }

}
