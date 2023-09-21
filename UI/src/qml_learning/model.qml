import QtQuick
import QtQuick 2.15
import QtQuick.Controls 2.15
ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Application Window"
    ListView {
        // using a integer as model
        model: 5
        delegate: Text {
            text: 'index: ' + index
        }


    }
}

// ListView {
//     // using a JS array as model
//     model: ['A', 'B', 'C', 'D', 'E']
//     delegate: Text { 'Char['+ index +']: ' + modelData }
// }
//
// ListView {
//     // using a dynamic QML ListModel as model
//     model: ListModel {
//         ListElement { char: 'A' }
//         ListElement { char: 'B' }
//         ListElement { char: 'C' }
//         ListElement { char: 'D' }
//         ListElement { char: 'E' }
//     }
//     delegate: Text { 'Char['+ index +']: ' + model.char }
// }