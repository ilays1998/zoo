import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 400; height: 400
    visible: true
    SquareButton {
        onDeactivated: console.log("Deactivated!")
        onActivated: (xPosition, yPosition) => console.log("Activated at " + xPosition + "," + yPosition)
    }
}