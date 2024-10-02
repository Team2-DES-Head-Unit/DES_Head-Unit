import QtQuick 6.8

Item {
    id:sp_needle
    Image{
        id: speed_needle_img
        source: "file:///Users/kimseungjoo/Desktop/coding/IC_TEST/needle.png"
        fillMode: Image.PreserveAspectFit
        transform: Rotation {
                        angle: -113  // 회전 각도
        }

        Behavior on rotation{
                    NumberAnimation{
                        duration: 50
                        easing.type: Easing.InOutQuad
                    }
        }
    }
}
