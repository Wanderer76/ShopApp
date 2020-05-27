import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: rectangle
    property alias name_field: name
    property alias price_field: price
    property alias image_field: image
    //border.width: 1
    Image {
        id: image
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 170
        antialiasing: true
        anchors.right: parent.right
        anchors.rightMargin: 25
        anchors.left: parent.left
        anchors.leftMargin: 25
        anchors.top: parent.top
        anchors.topMargin: 25
        source: ""
        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    Column {
        id: column
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: image.bottom
        anchors.topMargin: 20
        spacing: 4
        Label {
            id: name
            width: parent.width
            height: 40
            text: qsTr("Label")
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.strikeout: false
            font.underline: false
            font.bold: true
            font.italic: true
            font.pointSize: 18
            font.family: "Arial"
            color: "#e9967a"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Label {
            id: price
            text: qsTr("Label")
            font.italic: true
            font.pointSize: 15
            height: 40
            width: parent.width
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:480}D{i:1;anchors_width:432;anchors_x:34;anchors_y:26}
D{i:2;anchors_height:185;anchors_width:200;anchors_x:140;anchors_y:287}
}
##^##*/

