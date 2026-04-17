import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick .Controls 2.0
import Qt.labs.platform 1.0

ApplicationWindow  {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:window


    StackView{
        id :satckviewmain
        anchors.fill: parent
        initialItem: "addPage.qml"

    }

    SystemTrayIcon{
        visible: true
        iconSource: "qrc:/iconwin.jpeg" // 必须指定一个有效的图标
        tooltip: "我的 QML 应用"

        // 托盘菜单
        menu: Menu {
            id:trayMenu
            MenuItem {
                text: "显示窗口"
                onTriggered: window.show()
            }
            MenuItem {
                text: "退出"
                onTriggered:{
                    stockManager.save();
                    Qt.quit()
                }
            }
        }
        // 点击托盘图标的交互
        onActivated: (reason) => {
                         if (reason === SystemTrayIcon.Context) {
                             // 右键
                             trayMenu.open()
                         }
                     }
    }

    onClosing: (close) =>{
        close.accepted = false
        window.hide();
    }


}
