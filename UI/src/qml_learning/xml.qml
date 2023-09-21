import QtQuick
import QtQml.XmlListModel
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Application Window"

    Component {
        id: imageDelegate

        Rectangle {
            id: wrapper

            required property string title
            required property string imageSource

            width: listView.width
            height: 220
            color: '#333'

            Column {
                Text {
                    text: wrapper.title
                    color: '#e0e0e0'
                }
                Image {
                    width: listView.width
                    height: 200
                    fillMode: Image.PreserveAspectCrop
                    source: wrapper.imageSource
                }
            }
        }
    }

    XmlListModel {
        id: imageModel

        source: "https://www.nasa.gov/rss/dyn/image_of_the_day.rss"
        query: "/rss/channel/item"

        XmlListModelRole { name: "title"; elementName: "title" }
        XmlListModelRole { name: "imageSource"; elementName: "enclosure"; attributeName: "url"; }
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: imageModel
        delegate: imageDelegate
    }
}