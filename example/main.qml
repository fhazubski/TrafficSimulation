import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        Timer {
            interval: 50
            repeat: true
            running: true
            property real time: 0
            onTriggered: {
                time += interval/10
                simulation.setTime(time);
                console.log(simulation.vehicles.length)
                rect.x = simulation.vehicles[0].x
                rect.y = simulation.vehicles[0].y
                rect.rotation = simulation.vehicles[0].rotation
            }
        }
    }

    Rectangle {
        id: rect
        width: 100
        height: 50
        color: "red"
    }
}
