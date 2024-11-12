import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.mirroring 1.0

Rectangle{
    id: mirror_window
    visible: true
    color: "transparent"
    width: 618
    height: 480
//    flags: Qt.FramelessWindowHint

    property bool isInitialized: false

//    onActiveFocusItemChanged: {
//        if(!activeFocusItem){
//            visible = false;
//        }
//    }

    Component.onDestruction: {
        mirrorProvider.end();
    }

    onVisibleChanged: {
        if (!isInitialized && mirror_window.visible){
            mirror_window.x = main_window.x + 393;
            mirror_window.y = main_window.y + 40;
            mirrorProvider.init(mirror_window); // Initialize mirrorProvider with baseItem
            isInitialized = true;
        }
    }

    Image {
        fillMode: Image.PreserveAspectFit
//        source: "HU_Assets/Background/basic_window.png"
        source: clickNotifier.clicked ? "HU_Assets/light/Background/basic_window_l.png" : "HU_Assets/Background/basic_window.png"
        id: base_window
        z : 0
        visible: !mirrorProvider.isLoaded

        MirrorProvider{
            id: mirrorProvider
        }
        Rectangle{
            z: 1
            anchors.centerIn: parent
            color: "transparent"
            Column{
                anchors.centerIn: parent
                Text{
                    text: "Not Connected"
//                    color: "white"
                    color: clickNotifier.clicked ? "#414141" : "#ffffff"
                    font.pointSize: 25
                }
                Text{
                    text: "Please check the connection or \n check if it is connected properly."
                    color: clickNotifier.clicked ? "#414141" : "#ffffff"
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
                            mirror_window.visible = false;
                            isInitialized = false;
                            mirror_window.visible = true;
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
                mirrorQmlLoader.active = false;
                icon_line.x = 138;
            }
        }
        z: 2
    }

}
