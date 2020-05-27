import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

ListView {
    id: listView
    spacing: 15
    topMargin: 30
    model: ListModel {

        ListElement {
            names: "Pizza"
            img: "qrc:/res/pizza.svg"
        }
        ListElement {
            names: "Pizza"
            img: "qrc:/res/pizza.svg"
        }
    }
    delegate: CartDelegat {
        height: 150
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 10
        //anchors.verticalCenter: parent.verticalCenter
        image.source: img
        name.text: names
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

