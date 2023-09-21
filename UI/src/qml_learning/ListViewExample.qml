import QtQuick 2.0
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "List Example"
    ListView {
        width: 180; height: 200

        model: ListExample {
        }
        delegate: Text {
            text: name + ": " + number
        }
    }
}