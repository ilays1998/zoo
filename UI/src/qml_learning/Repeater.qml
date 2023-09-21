import QtQuick


import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Repeater Example"

    Column {
        width: parent.width
        height: parent.height
        spacing: 2

        Repeater {
            model: ["Enterprise", "Columbia", "Challenger", "Discovery", "Endeavour", "Atlantis"]

            delegate: Rectangle {
                //id: index
                width: 100
                height: 30
                color: "lightblue"
                border.color: "blue"
                Text {
                    anchors.centerIn: parent
                    text: modelData + index
                }
            }
        }
    }
}