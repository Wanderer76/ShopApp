import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: window
    visible: true
    height: 640
    width: 480
    title: qsTr("Best Pizza App")
    property alias stack: stackView

    Material.theme: Material.Light
    color: "white" //Material.background

    Component.onCompleted: {
        toServer.connected()
    }

    header: ToolBar {
        Material.background: Material.Orange
        RowLayout {
            anchors.fill: parent
            ToolButton {
                id: toolButton

                Image {
                    id: menu
                    width: 30
                    height: 30
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    source: "qrc:/res/menu.png"
                    visible: stackView.depth === 1 ? true : false
                    smooth: true
                    mipmap: true
                }

                text: stackView.depth > 1 ? "<" : ""

                font.pixelSize: Qt.application.font.pixelSize * 1.6
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                    } else {
                        drawer.open()
                    }
                }
            }

            Label {
                anchors.horizontalCenter: parent.horizontralCenter
                text: "Best Pizza App"
                color: "black"
            }
        }
    }

    Drawer {
        id: drawer
        height: window.height
        width: window.width * 0.7
        interactive: true
        background: Rectangle {
            implicitWidth: window.width
            // implicitHeight: 40
            //color: "#f5fffa"
            color: Material.color(Material.Teal,
                                  Material.Shade100) //"#93c9ff" //"#6b72d9"
            //Material.color(Material.Orange)
        }

        ToolButton {
            text: "<"

            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                drawer.close()
            }
        }

        Column {
            id: col
            anchors.top: parent.top
            anchors.topMargin: 80
            spacing: 30
            RoundButton {
                id: shop
                Image {
                    anchors.left: shop.left
                    //anchors.bottom: shop.bottom
                    anchors.leftMargin: 20
                    height: 30
                    width: 45
                    anchors.verticalCenter: parent.verticalCenter
                    id: shopImg
                    source: "qrc:/res/shop.svg"
                    mipmap: true
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    ColorOverlay {
                        anchors.fill: shopImg
                        source: shopImg
                        color: "white"
                    }
                }

                width: drawer.width
                height: 60
                text: "Магазин"
                wheelEnabled: true
                font.pointSize: 12
                highlighted: true
                flat: false
                onClicked: {
                    stackView.push("AppView.qml")
                    drawer.close()
                }
            }

            RoundButton {
                id: cart
                width: drawer.width
                height: 50
                text: "Корзина"
                wheelEnabled: true
                font.pointSize: 12
                highlighted: true
                flat: false
                Image {
                    anchors.left: cart.left
                    //anchors.bottom: shop.bottom
                    anchors.leftMargin: 20
                    height: 30
                    anchors.verticalCenter: parent.verticalCenter
                    width: 45
                    id: cartImg
                    source: "qrc:/res/shopping-cart.svg"
                    mipmap: true
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    ColorOverlay {
                        anchors.fill: cartImg
                        source: cartImg
                        color: "white"
                    }
                }
                onClicked: {
                    stack.push("Cart.qml")
                    drawer.close()
                }
            }
            RoundButton {
                id: about
                width: drawer.width
                height: 50
                text: "О программе"
                wheelEnabled: true
                font.pointSize: 12
                highlighted: true
                flat: false
                Image {
                    id: aboutImg
                    source: "qrc:/res/about.png"
                    anchors.left: about.left
                    height: 30
                    width: 30
                    mipmap: true
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    anchors.leftMargin: 30
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

    StackView {
        anchors.fill: parent
        id: stackView
        initialItem: "HomeFile.qml"
    }
}

/*##^##
Designer {
    D{i:7;anchors_height:48;anchors_width:131;anchors_x:174;anchors_y:362}D{i:6;anchors_height:48;anchors_width:131;anchors_x:174;anchors_y:362}
}
##^##*/

