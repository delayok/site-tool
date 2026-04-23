import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import myapp 1.0

Item {

    ColumnLayout{
        anchors.fill: parent
        ListView {
            id: listView
            width: parent.width
            height: parent.height * 0.8
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

    //                RealTimeCurve{
    //                    id: realTimeCurve
    //                    width: parent.width
    //                    height: 130
    //                    lineColor: increase > 0.0 ? "red" : "green"
    //                    tablemodel: stockManager.getXYtableModel(code)
    //                    visible: stockManager.getCodeVisable(code)
    //                }
                    RealtimeCurveSkeleton{
                        id: realTimeCurveGCSnode
                        width: parent.width
                        height: 130
                        codeid: code
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
                            contextMenu.curve = realTimeCurveGCSnode //realTimeCurve,realTimeCurveGCSnode
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
                    text: "移除"
                    onTriggered: {
                        stockManager.removecodelist(contextMenu.code)
                    }
                }
                MenuItem {
                    text: "添加"
                    onTriggered: {
                       satckviewmain.pop();
                    }
                }
            }

            model:stockManager.model
        }

    }
}
