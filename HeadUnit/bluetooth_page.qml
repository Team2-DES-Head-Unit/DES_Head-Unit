import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window{
    id: bluetooth_window
    visible: true
    width: 413
    height: 445
    color: "transparent"
    flags: Qt.FramelessWindowHint

    property bool isSearching: false  // 검색 상태를 추적하는 변수
    property bool isStopped: true

    Image {
        id: bluetooth_close_button
        x: 350
        y: 6
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                bluetooth_window.visible = false;
                service_selected.visible = false;
            }
        }
        Connections {
            target: service_selected
        }
    }

    Column {
        id: bluetooth_discovery
        spacing: 30
        Item {
            id: topmargin_Item
            width: parent.width
            height: 45  // topMargin을 주는 효과
        }
        Row {
            id: bdbutton_row
            spacing: 20
            Item{
                id: leftmargin_Item
                width: 25
                height: 20
            }

            Text {
                id: bluetoothd_txt
                text: qsTr("Bluetooth Discovery")
                font.pixelSize: 20
                color: "white"
            }
            Button {
                id: bdbutton_on
                text: qsTr("On")
                width: 50
                height: 25
//                onClicked: {
//                    btManager.startDiscovery();
//                    isSearching = true;  // 검색 상태 시작
//                    isStopped = false;   // 검색 중지 상태 해제
//                    deviceModel.clear(); // 장치 목록 초기화
//                }
            }
            Button {
                id: bdbutton_off
                text: qsTr("Off")
                width: 50
                height: 25
//                onClicked: {
//                    btManager.stopDiscovery();
//                    isSearching = false;  // 검색 중지
//                    isStopped = true;     // 검색 중지 상태 설정
//                }
            }

        }
        ListView {
            id: bd_list
            width: parent.width - 70
            height: 250
            anchors.left: parent.left
            anchors.leftMargin: 55
            model: ListModel {
                id: deviceModel
            }

            delegate: Text {
                id: bd_txt
                text: model.deviceName
            }

            // 검색 상태에 따라 표시할 텍스트 관리
            Component.onCompleted: {
                deviceModel.clear();  // 장치 목록 초기화
            }

            // 표시할 내용 제어 (검색 상태 및 장치 목록에 따라)
            Text {
                id: n_o
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: 25
                font.bold: true
                text: {
                    if (isStopped) {
                        return "Off";  // 검색이 중지되면 "Off" 표시
                    } else if (isSearching && deviceModel.count === 0) {
                        return "None";  // 검색 중, 장치 없음
                    }
                }
                visible: deviceModel.count === 0  // 장치가 없을 때만 표시
            }
        }
//        Connections {
//            target: btManager

//            onDeviceDiscovered: {
//                deviceModel.append({"deviceName": deviceName});
//            }

//            onDiscoveryFinished: {
//                console.log("Discovery finished.");
//                isSearching = false;  // 검색 상태 중지
//            }
//        }
    }

}
