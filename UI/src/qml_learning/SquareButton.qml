import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    visible:true
    color: "red"
    signal activated(xPosition: real, yPosition: real)
        signal deactivated

    property int side: 100
    width: side; height: side

    MouseArea {
        anchors.fill: parent
        onReleased: root.deactivated()
        onPressed: (mouse)=> root.activated(mouse.x, mouse.y)
    }
}