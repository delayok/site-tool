import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item {
    id: element
    property StackView stackViewReference

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Row{
            id: row
            Layout.fillHeight: false

            spacing: 10
            Text {
                id: idcode
                height: 40
                text: qsTr("请输入名字/代码：")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            TextField{
                id: textField2
                placeholderText: "000001"
                focus: true;
                selectByMouse: true
                mouseSelectionMode: TextInput.SelectCharacters
                // 设置选择区域颜色
                selectedTextColor: "white"


            }

            Button {
                id: button
                text: "添加"
                onClicked: {
                    stockManager.curcode = textField2.text;
                }
            }

        }


        Button {
            Layout.preferredHeight: 40
            id: button1
            text: qsTr("下一页")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            transformOrigin: Item.Center
            onClicked: {
                satckviewmain.push("listPage.qml");
            }
        }

    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:100;anchors_width:100;anchors_x:129;anchors_y:312}
}
##^##*/
