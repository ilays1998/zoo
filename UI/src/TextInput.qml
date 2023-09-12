import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "inputText"

    Column {
        width: 200; height: 200

        TextInput{id: myTextInput;  text: "Hello World"}
        Text { text: myTextInput.text}
    }
}
