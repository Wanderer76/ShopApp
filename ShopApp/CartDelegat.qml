import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: rectangle
    property alias image: img
    property alias name: nam
    border.width: 1
    Image {
        id: img
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 200
        anchors.left: parent.left
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        smooth: true
        height: parent.height
        width: parent.height
    }

    Text {
        id: nam
        font.pointSize: 20
        font.family: "Calibri"
        anchors.left: parent.left
        anchors.leftMargin: img.width + 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:480;anchors_width:480}
}
##^##*/

