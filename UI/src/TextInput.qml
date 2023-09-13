import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "inputText"
    id: root
    Column {
        id: col
        anchors.right: parent.right
        anchors.margins: 0
        width: 200; height: 200

        TextInput{id: myTextInput;  text: "Hello World"}
        Text {
            id: txt
            text: myTextInput.text
            property string nextText: "abba"
        }
    }
    Rectangle {
        Rectangle {
            visible: true
            id: sonRect
            color: "red"

        }
        visible: true
        id: rect
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 20 }
        width: col.width / 2; height: 200
        color: "red"
        property color previousColor: "black"
        property color nextColor
        property alias qm: sonRect.color
        nextColor: "blue"

        property var someList: [1, 2, "three", "four"]
        onNextColorChanged: console.log("the next color will be: " + nextColor.toString())
    }
}
