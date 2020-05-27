import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import GridModel 1.0

Rectangle {
    id: infoPanel
    // This is available in all editors.
    property alias info: infoPanel
    property alias imageLabel: image
    property alias nameLabel: nameLab
    property alias priceLabel: priceLab
    property string countLabel: ""
    property alias descriptionLabel: description
    property int id: 0

    color: "#fbe0ab"

    Image {
        id: image
        anchors.right: parent.right
        anchors.rightMargin: 70
        anchors.left: parent.left
        anchors.leftMargin: 70
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 340
        anchors.top: parent.top
        anchors.topMargin: 30
        Layout.topMargin: 30
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        fillMode: Image.PreserveAspectFit
        source: ""
    }

    Column {
        id: column
        width: 350
        anchors.left: parent.left
        anchors.leftMargin: 65
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: image.bottom
        anchors.topMargin: 10
        spacing: 9
        Label {
            id: nameLab
            width: parent.width
            height: 40
            text: qsTr("Name")
            font.italic: true
            font.pointSize: 15
            verticalAlignment: Text.AlignVCenter
            // anchors.top: image.bottom
            anchors.topMargin: 34
        }
        Label {
            id: priceLab
            width: parent.width
            height: 40
            text: qsTr("Price")
            font.italic: true
            font.pointSize: 15
            verticalAlignment: Text.AlignVCenter
            //anchors.top: image.bottom
            anchors.topMargin: 34
        }
        Label {
            id: countLab
            width: parent.width
            height: 40
            text: "В наличии " + countLabel
            font.italic: true
            font.pointSize: 15
            verticalAlignment: Text.AlignVCenter
            // anchors.top: image.bottom
            anchors.topMargin: 34
        }
    }

    Label {
        id: description
        text: qsTr("Desc")
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        leftPadding: 10
        topPadding: 10
        verticalAlignment: Text.AlignTop
        font.pointSize: 13
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 90
        anchors.top: column.bottom
        anchors.topMargin: 35
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
    }

    RoundButton {
        id: addToCart
        text: qsTr("Добавить в корзину")
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.top: description.bottom
        anchors.topMargin: 15
        highlighted: true
        flat: false
        onClicked: {
            if (countLabel > 0) {
                console.log(countLabel)
                toServer.sendCount(id, countLabel - 1)
                stack.pop()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:640;width:480}D{i:1;anchors_height:263;anchors_width:340;anchors_y:34}
D{i:2;anchors_y:303}
}
##^##*/

