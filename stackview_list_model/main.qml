import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick .Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    StackView{
        id :satckviewmain
        anchors.fill: parent
        initialItem: "addPage.qml"

    }
}
