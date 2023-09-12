// RedSquare.qml

import QtQuick
import QtQuick.Controls
Rectangle {
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