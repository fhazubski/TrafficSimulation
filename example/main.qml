import QtQuick 2.9
import QtQuick.Window 2.2
import Checkerboard 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        anchors.fill: parent
        Component.onCompleted: {
            simulation.addVehicle(0, 0, 1.5, 3.5, 0, 0)
            simulation.addVehicle(0, 0, 1.5, 3.5, 0, 20)
            simulation.overrideAxleAngle(1, 15)
        }

        Timer {
            interval: 16
            repeat: true
            running: true
            property real time: 0
            onTriggered: {
                time += interval
                simulation.setTime(time);
            }
        }
    }

    Checkerboard {
        anchors.fill: parent
        step: 50
        color1: "white"
        color2: "grey"
    }

    Item {
        x: parent.width / 2
        Repeater {
            model: simulation.vehicles
            Rectangle {
                id: rect
                x: -width / 2 + simulation.vehicles[index].x * 15
                y: width * 2 - height / 2 + simulation.vehicles[index].y * 15
                width: simulation.vehicles[index].width * 15
                height: simulation.vehicles[index].height * 15
                rotation: 90 + simulation.vehicles[index].rotation
                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);
            }
        }
    }
}
