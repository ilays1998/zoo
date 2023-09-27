import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Controls.Material
import GraphQL.Zoo.Qu
import GraphQL.Zoo.RemoveAnimalByName

//import QtQuickImage
//import QtQuick.Controls.Styles 2.0

ApplicationWindow { id:root
    width: 500; height: 400
    visible: true
    Material.theme: Material.Dark
    Material.accent: Material.Pink
    UseQu{id: animals_query;

    }
    Component.onCompleted: {
        animals_query.fetch();
    }


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



            model: animals_query.data?.animals;

            delegate: Animal {
                id:animal_delegate
                width: ListView.view.width;
                height: 200;
                required property var model;
                animal: model.data;
                color: (model.index % 2 === 0) ? "red" : "yellow"
                textTxt: animal.name + "\nage: " + animal.age + "\nfamily: " +
                    animal.metadata.family
                src: animal.image
                image: true
                UseRemoveAnimalByName{
                    id: remove_animal_mutaiton;
                    onCompletedChanged: {
                        animals_query.refetch();
                    }
                    onError:{
                        console.log("")
                    }

                }
                Button {
                    text: "Delete animal"
                    onClicked: {
                        Backend.remove_animal(remove_animal_mutaiton, animal.name);
                        deleteAnimal.fetch();
                        console.log(root.deleteAnimal?.data.error);
                    }

                }
            }

        }
    }
}






















// ApplicationWindow {id:root
//     width: 500;
//     height: 400;
//     visible: true;
//     Material.theme: Material.Dark
//     Material.accent: Material.Orange
//     property var continent: query?.data?.continent;
//
//     ListView{id: countries_view
//         anchors.fill: parent;
//         model: root.continent?.countries;
//         header:Rectangle{
//             color: Material.color(Material.Indigo)
//             width: ListView.view.width;
//             height: 50;
//             Label{
//                 anchors.centerIn: parent;
//                 text: `Countries in Continent ${root.continent?.name} (${countries_view.count}):`
//             }
//         }
//         delegate: Rectangle{
//             id: country_delegate
//             required property var model;
//             color: (model.index % 2 == 0)? Material.color(Material.Grey):  Material.color(Material.BlueGrey)
//             property var view: ListView.view;
//             width: view.width;
//             height: 50;
//             Label{
//                 anchors.left: parent.left;
//                 property var country: country_delegate.model.data;
//                 text: `${country_delegate.model.index + 1}:  ${country.emoji} capital: ${country.capital}`
//             }
//         }
//     }
// }
