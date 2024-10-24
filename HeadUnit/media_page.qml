import QtQuick 2.12
import QtQuick.Window 2.12

Window{
    id: media_window
    visible: true
    width: 618
    height: 480
    color: "transparent"
    flags: Qt.FramelessWindowHint

    Image {
        id: base_window
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        source: clickNotifier.clicked ? "HU_Assets/light/Background/basic_window_l.png" : "HU_Assets/Background/basic_window.png"
    }

    Image {
        id: window_close_button
        x: 550
        y: 20
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: clickNotifier.clicked ? "HU_Assets/light/Icons/close_icon_l.png" : "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                media_window.visible = false;
                icon_line.x = 138;
            }
        }
    }
}
