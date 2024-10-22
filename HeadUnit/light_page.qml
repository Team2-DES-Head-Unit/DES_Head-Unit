import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window{
    id: light_window
    visible: true
    width: 413
    height: 445
    color: "transparent"
    flags: Qt.FramelessWindowHint


    Image {
        id: light_close_button
        x: 350
        y: 6
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: clickNotifier.clicked ? "HU_Assets/light/Icons/close_icon_l.png" : "HU_Assets/Icons/tap_close_button.png"

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

    Rectangle {
        id: light_mode
        width: parent.width / 2
        height: 380
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.left: parent.left
        color: "blue"

        Text {
            id: light_txt
            font.bold: true
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Light")
            color: "red"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickNotifier.setTrue() // 첫 번째 MouseArea에서 true 설정
            }
        }

    }
    Rectangle {
        id: dark_mode
        width: parent.width / 2
        height: 380
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.right: parent.right
        color: "red"

        Text {
            id: dark_txt
            font.bold: true
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Dark")
            color: "blue"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickNotifier.setFalse() // 두 번째 MouseArea에서 false 설정
            }
        }
    }

}
