import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.mirroring 1.0

Window{
    id: mirror_window
    visible: true
    color: "transparent"
    width: 618
    height: 480
    flags: Qt.FramelessWindowHint

    property bool isInitialized: false

    Component.onDestruction: {
        mirrorProvider.end();
    }

    onVisibleChanged: {
        if (!isInitialized && mirror_window.visible){
            mirrorProvider.init(mirror_window); // Initialize mirrorProvider with baseItem
        }
    }

    Image {
        fillMode: Image.PreserveAspectFit
        source: "HU_Assets/Background/basic_window.png"
        id: base_window
        z : 0

        MirrorProvider{
            id: mirrorProvider
        }
        Rectangle{
            z: 1
            anchors.centerIn: parent
            visible: !mirrorProvider.isLoaded
            color: "transparent"
            Column{
                anchors.centerIn: parent
                Text{
                    text: "Not Connected"
                    color: "white"
                    font.pointSize: 25
                }
                Text{
                    text: "Please check the connection or \n check if it is connected properly."
                    color: "white"
                }
                Rectangle{
                    width: 120
                    height: 50
                    color: "green"
                    Text{
                        anchors.centerIn: parent
                        text: "RECONNECT"
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            mirrorProvider.end();
                            mirrorProvider.init(mirror_window);
                        }
                    }
                }
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
                mirrorProvider.end();
                isInitialized = false;
                mirror_window.visible = false;
                icon_line.x = 138;
            }
        }
        z: 2
    }

}
