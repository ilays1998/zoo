import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Controls.Material

//import QtQuickImage
//import QtQuick.Controls.Styles 2.0
ApplicationWindow { id:root
    width: 500; height: 400
    visible: true
    StackView {
        id: stack
        initialItem: splash_screen
        anchors.fill: parent

    }
    Component {
        id: splash_screen;
        Item {
            Image {
                id: imageZoo
                anchors.fill: parent;
                source: "pictures/zooImage.png"
                visible: true
            }

            TapHandler {
                onTapped: stack.push(animals_list)
            }
        }
    }
    Component {
        id: animals_list
        ListView {
            id: view
            implicitHeight: parent.height;
            implicitWidth: parent.width;


            model: zooModel

            delegate: Animal {
                width: ListView.view.width;
                height: 200;
                required property var model;
                animal: model.animal
                color: (model.animal.name === "t") ? "red" : "yellow"
                textTxt: model.animal.name + "\nage: " + model.animal.age + "\nfamily: " +
                    model.animal.metadata.family
                src: model.animal.image
                image: true
                Button {
                    text: "Delete animal"
                    onClicked: {
                        zooModel.deleteAnimal(model.animal.name);
                        //zooModel.foo();
                    }


                }
            }

        }
    }
}









        //
        // Rectangle {
        //     id: rectChicken
        //
        //     width: 50; height: 50
        //     anchors.left: rectSnake.right;
        //     anchors.top: rectSnake.bottom
        //     color: "blue"
        //     Text {
        //         anchors.centerIn: parent
        //         text:"chicken"
        //         //visible:true
        //     }
        //     visible: true
        //     z: 1
        // }
        //
        // Rectangle {
        //     id: rectLion
        //
        //     width: 50; height: 50
        //     anchors.bottom: rectChicken.top
        //     anchors.left: rectSnake.right;
        //     color: "yellow"
        //     Text {
        //         anchors.centerIn: parent
        //         text:"lion"
        //         //visible:true
        //     }
        //     visible: true
        //     z: 1
        // }
        //
        // Rectangle {
        //     id: rectElephant
        //
        //     width: 70; height: 50
        //     anchors.top: rectSnake.bottom
        //     anchors.right: rectChicken.left;
        //     color: "pink"
        //     Text {
        //         anchors.centerIn: parent
        //         text:"elephant"
        //         //visible:true
        //     }
        //     visible: true
        //     z: 1
        // }








