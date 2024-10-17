import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.mirroring 1.0

Window{
    id: mirror_window
    visible: true
    width: 618
    height: 480
    color: "transparent"
    flags: Qt.FramelessWindowHint

    onActiveChanged: {
        console.log("Complete!")
        mirrorProvider.init(base_window);
    }



    Image {
        id: base_window
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        source: "HU_Assets/Background/basic_window.png"

        MirrorProvider{
            id: mirrorProvider
        }

        Rectangle{
            anchors.fill: parent
            visible: !mirrorProvider.isLoaded
            Text {
                id: name
                text: qsTr("Video is not found")
            }
        }
    }

    Image {
        id: window_close_button
        x: 550
        y: 20
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                mirror_window.visible = false;
                icon_line.x = 138;
            }
        }
    }

}
