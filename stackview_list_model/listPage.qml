import QtQuick 2.0
import QtQuick.Controls 2.3
import myapp 1.0

Item {
    ListView {
        id: listView
        anchors.fill: parent
        delegate: Item {
            // 移除 x: 5，改用左边距锚点更稳健
            anchors.left: parent ? parent.left : undefined
            anchors.leftMargin: 5
            width: parent ? parent.width : 0
            // 关键：高度绑定到 Column
            height: containscolumn.height

            Column{
                id :containscolumn
                width: parent.width

                Row {
                    id:row
                    height: 30
                    spacing: 10

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        width: 60
                    }
                    Text {
                        text: qsTr("价:")  + price
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        color: price > open ? "red" : "green";
                        width: 60
                    }
                    Text {
                        text: qsTr("幅:") + increase
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        color: increase > 0.0 ? "red" : "green";
                        width: 60
                    }
                    Text {
                        text: qsTr("均:") + mhmov
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                        width: 60
                    }

                }

                RealTimeCurve{
                    id: realTimeCurve
                    width: parent.width
                    height: 130
                    lineColor: increase > 0.0 ? "red" : "green"
                    source: stockManager.getCurveEntity(code)
                    tablemodel: stockManager.getXYtableModel(code)
                    visible: stockManager.getCodeVisable(code)
                }

            }
            MouseArea{
                id: museitem
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: {
                    if (mouse.button === Qt.RightButton)
                    {
                        contextMenu.code = code
                        contextMenu.curve = realTimeCurve
                        contextMenu.popup();
                    }
                }
            }
        }


        // 定义右键菜单
        Menu {
            id: contextMenu
            property string code // 存储当前选中的索引
            property var curve // 存储当前选中的索引

            MenuItem {
                text: "显示/隐藏波形"
                onTriggered: {
                    var item = contextMenu.curve
                    if (item) item.visible = !item.visible
                    stockManager.setViable(contextMenu.code);
                }
            }

            MenuItem {
                text: "移除此曲线"
                onTriggered: {
                    stockManager.removecodelist(contextMenu.code)
                }
            }
        }

        model:stockManager.model
    }

    Button {
        id: button
        x: 440
        y: 400
        text: qsTr("上一页")
        onClicked: {
            satckviewmain.pop();
        }
    }
}
