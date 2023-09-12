// main.qml

import QtQuick
import QtQuick.Controls

Window {
    id: root
    visible: true
    width: 1000
    height: 800
    title: "QML Tutorial"

    Repeater{
        z: 2

    }
    RedSquare {
        z:1
    }
    Rectangle {
        width: parent.width
        height: parent.height

        Text {
            id: messageText
            anchors.centerIn: parent
            text: "Hello, QML!"
            font.pixelSize: 24
        }
        Button {
            text: "Change Text"
            anchors {
                bottom: parent.bottom
                horizontalCenter: parent.horizontalCenter
                bottomMargin: 20
            }
            onClicked: {
                messageText.text = "Text Changed!"
            }
        }

        z:0
    }
}