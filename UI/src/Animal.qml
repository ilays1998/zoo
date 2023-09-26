import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Rectangle {
    id: root
    required property QtObject animal;
    property alias textTxt: txt.text
    property alias src: image.source
    property alias image: image.visible

    Text {
        id: txt
        anchors.centerIn: parent
        text: textTxt
    }
    Image {
        id: image
        anchors.fill: parent
        source: src
        visible:true
        z: 0
    }
    TapHandler{

        onTapped: {
            console.log("tapped");

            image.visible = !image.visible;
        }
    }


}