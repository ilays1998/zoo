import QtQuick


import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Repeater Example"
    Rectangle {
        id: root
        width: 200
        height: 200
        color: "#ea2525"
        border.color: Qt.lighter(color)
        Text {
            id: messageText
            anchors.centerIn: parent
            text: "snake"
            font.pixelSize: 12
        }
        Button {
            id: button
            text: "get details"
            anchors {
                bottom: parent.bottom
                horizontalCenter: parent.horizontalCenter
                bottomMargin: 20
            }
            onClicked: {
                button.visible = false
                messageText.text = "amount: 5"
            }
        }

    }
    }