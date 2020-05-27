import QtQuick 2.0
import QtQuick.Controls 2.12
import GridModel 1.0

GridView {
    id: view
    property bool append: false
    property alias mod: model
    cellWidth: parent.width / 2
    cellHeight: parent.height / 2
    model: GridModel {
        id: model
    }

    delegate: Delegate {
        id: delegat
        opacity: mouse.pressed ? 0.6 : 1
        color: "#FFF8DC"
        height: cellHeight
        width: cellWidth
        name_field.text: name
        price_field.text: "Цена: " + price + " рублей"
        image_field.source: image

        MouseArea {
            id: mouse
            anchors.fill: delegat

            onClicked: {
                stack.push("InformationPanel.qml", {
                               "imageLabel.source": image,
                               "nameLabel.text": name,
                               "priceLabel.text": "Цена: " + price + " рублей",
                               "countLabel": count,
                               "descriptionLabel.text": descrip,
                               "id": id,
                               "mod": mod
                           })
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

