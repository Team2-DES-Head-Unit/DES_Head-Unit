import QtQuick 2.12
import QtQuick.Window 2.12
//import com.DESInstrumentClusterTeam7.speedometer 1.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: bg_window
    visible: true
    width: 1280
    height:400
    color: "#28282c"
    title: qsTr("Instrument Cluster")
    flags: Qt.FramelessWindowHint

    property int angle: 0
    property int currentSpeed: 0
    property int targetSpeed: 0
    property int currentrpm: 0
    property int targetrpm: 0

    Image{
        id: bg_car
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.topMargin: 30
        source: "/IC Assets/background_car.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: speed_dial
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        source: "/IC Assets/speedometer.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: rpm_dial
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        source: "/IC Assets/speedometer.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: topbar
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        source: "/IC Assets/top_bar.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: topbar_menu
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        source: "/IC Assets/top_bar_menu.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: speed_needle
        anchors.right: speed_dial.horizontalCenter
        anchors.bottom: speed_dial.verticalCenter
        source: "/IC Assets/needle.png"
        fillMode: Image.PreserveAspectFit
        transformOrigin: Item.BottomRight
        rotation: bg_window.angle /*(Receiver.speedKmh * 2.5 + 210)*/

        Behavior on rotation{
            NumberAnimation{
                duration: 50
                easing.type: Easing.InOutQuad
            }
        }
//         Connections{
//             target: Receiver
//             onSpeedChanged: needle.angle = (Receiver.speedKmh * 2.5 + 210)
//         }
    }

    Image{
        id: speed_inner
        anchors.centerIn: speed_dial
        source: "/IC Assets/inner_circle.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: rpm_needle
        anchors.right: rpm_dial.horizontalCenter
        anchors.bottom: rpm_dial.verticalCenter
        source: "/IC Assets/needle.png"
        fillMode: Image.PreserveAspectFit
        transformOrigin: Item.BottomRight
        rotation: bg_window.angle /*(((Receiver.speedKmh) / (2 * 3.14 * 3.3)) * 60)*/
        Behavior on rotation{
            NumberAnimation{
                duration: 50
                easing.type: Easing.InOutQuad
            }
        }
//         Connections{
//             target: Receiver
//             onSpeedChanged: needle.angle = (((Receiver.speedKmh) / (2 * 3.14 * 3.3)) * 60)
//         }
    }

    Image{
        id: rpm_inner
        anchors.centerIn: rpm_dial
        source: "/IC Assets/inner_circle.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: left
        anchors.right: parent.horizontalCenter
        anchors.bottom: parent.verticalCenter
        anchors.rightMargin: 104
        anchors.bottomMargin: 65
        source: "/IC Assets/left_dark.png"
        fillMode: Image.PreserveAspectFit
    }

    Image{
        id: right
        anchors.left: parent.horizontalCenter
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: 96
        anchors.bottomMargin:65
        source: "/IC Assets/right_dark.png"
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: speed_text
        text: qsTr("Speed") /*Receiver.speedKmh.toFixed(0)*/
        anchors.centerIn: speed_dial
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        font.pixelSize: 30
        color: "white"
        font.bold: true

//         NumberAnimation{
//             id: speedAnimation
//             target: speedTextComponent
//             property: "currentSpeed"
//             to: targetSpeed
//             duration: 800
//             easing.type: Easing.InOutQuad
//         }
    }
//     Connections{
//            target: Receiver
//            onSpeedChanged: {
//                speedTextComponent.targetSpeed = Receiver.speedKmh
//                speedAnimation.start()
//            }
//     }

    Text {
        id: cm_s
        text: qsTr("CM/S")
        anchors.top: speed_text.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter:speed_dial.horizontalCenter
        font.pixelSize: 15
        color: "#939395"
    }

    Text {
        id: rpm_text
        text: qsTr("RPM") //Receiver.RPM.toFixed(0) (RPM은 따로 만들어야 함)
        anchors.centerIn: rpm_dial
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        font.pixelSize: 30
        color: "white"
        font.bold: true

        // NumberAnimation{
        //     id: rpmAnimation
        //     target: rpmTextComponent
        //     property: "currentrpm"
        //     to: targetrpm
        //     duration: 800
        //     easing.type: Easing.InOutQuad
        // }
    }
    // Connections{
    //        target: Receiver
    //        onSpeedChanged: {
    //            rpmTextComponent.targetrpm = Receiver.RPM
    //            rpmAnimation.start()
    //        }
    // }


    Text {
        id: x1000prm
        text: qsTr("X1000PRM")
        anchors.top: rpm_text.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter:rpm_dial.horizontalCenter
        font.pixelSize: 15
        color: "#939395"
    }

    Image{
        id: battery
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        width: 20
        height: 20
        source: "/IC Assets/battery.png"
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: battery_text
        text: qsTr("battery") /*battery_value + "%"*/
        anchors.right: battery.left
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 2
        font.pixelSize: 11
        color: "white"
    }

    Image{
        id: bottombar
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "/IC Assets/bottom_bar.png"
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: time_text
        text: Clock.currentTime
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 55
        font.pixelSize: 25
        color: "white"
        font.bold: true
    }
     Connections{
         target: Clock
         onTimeChanged: time_text.text = Clock.currentTime
     }

    Text {
        id: day_text
        text: Date.currentDate
        anchors.right: time_text.left
        anchors.rightMargin: 90
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 45
        font.pixelSize: 20
        color: "#939395"
    }
    Connections{
        target: Date
        onDateChanged: day_text.text = Date.currentDate
    }

    Text {
        id: temperature_text
        text: Weather.temperature
        anchors.left: time_text.right
        anchors.leftMargin: 90
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 45
        font.pixelSize: 20
        color: "#939395"
    }
    Connections{
        target: Weather
        onWeatherUpdated: temperature_text.text = Weather.temperature
    }

    Text {
        id: distance_text
        text: qsTr("Distance")
        anchors.horizontalCenter: speed_dial.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        font.pixelSize: 30
        color: "#87F1D0"
    }

    Text {
        id: gear_text
        text: qsTr("Gear")
        anchors.horizontalCenter: rpm_dial.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        font.pixelSize: 30
        color: "#87F1D0"
    }


}
