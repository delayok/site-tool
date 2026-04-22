import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import Qt.labs.platform 1.0

ApplicationWindow  {
    visible: true
    width: 640
    height: 480
    title: qsTr("10")
    id:window


    property var satckviewmain: pageNavigator

    Item {
        id: pageHost
        anchors.fill: parent

        Loader {
            id: addPageLoader
            anchors.fill: parent
            source: "addPage.qml"
            visible: true
            active: true
        }

        Loader {
            id: listPageLoader
            anchors.fill: parent
            source: "listPage.qml"
            visible: false
            active: true
        }
    }

    QtObject {
        id: pageNavigator
        function push(page) {
            if (page === "listPage.qml") {
                addPageLoader.visible = false
                listPageLoader.visible = true
            } else if (page === "addPage.qml") {
                addPageLoader.visible = true
                listPageLoader.visible = false
            }
        }

        function pop() {
            addPageLoader.visible = true
            listPageLoader.visible = false
        }
    }

    SystemTrayIcon{
        visible: true
        iconSource: "qrc:/iconwin.jpeg" // 必须指定一个有效的图标
        tooltip: "gugugu"

        // 托盘菜单
        menu: Menu {
            id:trayMenu
            MenuItem {
                text: "显示窗口"
                onTriggered: {
                    window.show()
                    console.log("666")
                     trayMenu.close();
                }

            }
            MenuItem {
                text: "退出"
                onTriggered:{
                   console.log("9999")
                   trayMenu.close();
                   stockManager.save();
                   window.requestActivate();
                   Qt.quit()


                }
            }
        }
        // 点击托盘图标的交互
        onActivated: (reason) => {
                         if (reason === SystemTrayIcon.Context) {
                             // 右键

                             trayMenu.open()
                              console.log("8888")
                         }
                     }
    }

    onClosing: (close) =>{
        close.accepted = false
        window.hide();
        console.log("xxxx");
    }


}
