import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 400; height: 400
    visible: true

    Rectangle {
        id: root
        width: 100; height: 100
        visible: true
        color: "red"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("Click!")
            }

        }
    }
}