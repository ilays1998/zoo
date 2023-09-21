
    BlueBox {
        id: wrapper

        required property int index
        property real rotX: PathView.itemAngle

        visible: PathView.onPath

        width: 64
        height: 64
        scale: PathView.itemScale
        z: PathView.itemZ

        antialiasing: true

        gradient: Gradient {
            GradientStop { position: 0.0; color: "#2ed5fa" }
            GradientStop { position: 1.0; color: "#2467ec" }
        }

        transform: Rotation {
            axis { x: 1; y: 0; z: 0 }
            angle: wrapper.rotX
            origin { x: 32; y: 32; }
        }

        text: wrapper.index
    }