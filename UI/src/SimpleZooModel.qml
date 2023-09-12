import QtQuick
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts


ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "List Example"
    Component{
        id:animal
        ColumnLayout{
            required property var animal;

            Text {
                text: animal.food
            }
            Text {
                text: animal.weight
            }
            Text {
                text: animal.age
            }
        }
        
    }
    
    ListView {
        id: view
        anchors.fill: parent
        model: zooModel;
        delegate: Text {
            required property var model;
            text: model.index + "  " + model.food
        }
    }
}