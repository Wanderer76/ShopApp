import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Rectangle {
    color: "white"
    Column {
        id: column
        spacing: 14
        anchors.centerIn: parent
        Label {
            id: welcomeText
            text: qsTr("Добро пожаловать в магазин")
        }

        RoundButton {
            id: button
            width: 150
            height: 50
            text: qsTr("Магазин")
            anchors.horizontalCenter: parent.horizontalCenter

            spacing: 6
            wheelEnabled: true
            font.pointSize: 12
            highlighted: true
            flat: false


            onClicked: {
                console.log("2" - 1)
                stack.push("AppView.qml")
                //  app.visible = true
            }
        }
    }
}
