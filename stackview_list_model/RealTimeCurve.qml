import QtQuick 2.0
import QtQuick.Controls 2.0
import QtCharts 2.3
import myapp 1.0

Item {
    id: root
    width: 200
    height: 50

    property alias lineColor: lineSeries.color
    property MapTableModel tablemodel: null


    ChartView {
        id: chartView
        anchors.fill: parent
        antialiasing:false
        backgroundColor: "transparent"
        legend.visible: false
        animationOptions: ChartView.NoAnimation
        margins.top: 0
        margins.bottom: 0
        margins.left: 0
        margins.right: 0

        LineSeries {
            id: lineSeries
            name: "RealTime"
            color: "#00FFFF"
            width: 1.5
            useOpenGL: true  // 启用 OpenGL
            axisX: ValueAxis {
                id: xAxis
                min: 0
                max: 20000
                visible: false
            }
            axisY: ValueAxis {
                id: yAxis
                min: -10.0
                max: 10.0
            }

            VXYModelMapper {
                id: vxymodel
                series:lineSeries
                model: tablemodel
                xColumn: 0
                yColumn: 1
            }
        }
    }

    function setRange(min, max) {
        yAxis.min = min
        yAxis.max = max
    }

    function clear() {
        lineSeries.clear()
    }
}
