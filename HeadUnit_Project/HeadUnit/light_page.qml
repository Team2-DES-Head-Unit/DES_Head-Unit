import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Rectangle{
    id: light_window
    visible: true
    width: 413
    height: 445
    color: "transparent"
    //flags: Qt.FramelessWindowHint


    Image {
        id: light_close_button
        x: 350
        y: 6
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                light_window.visible = false;
                display_selected.visible = false;
            }
        }
        Connections {
            target: display_selected
        }
    }

}
