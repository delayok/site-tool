import QtQuick 2.0
import QtQuick.Controls 2.0
import QtCharts 2.3
import myapp 1.0

Item {
    id: root
    width: 200
    height: 50

    property alias lineColor: lineSeries.color
    property CurveEntity source: null

    onSourceChanged: {
        refreshChart()
    }

    function refreshChart() {
        if (!source) return
        var data = source.dataVec
        if (data && data.length > 0) {
            lineSeries.clear()
            for (var i = 0; i < data.length; i++) {
                lineSeries.append(i, data[i])
            }
        }
    }

    ChartView {
        id: chartView
        anchors.fill: parent
        antialiasing: true
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
            axisX: ValueAxis {
                id: xAxis
                min: 0
                max: 15000
                visible: false
            }
            axisY: ValueAxis {
                id: yAxis
                min: source ? source.minY : -10.0
                max: source ? source.maxY : 10.0
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
