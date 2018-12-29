import QtQuick 2.9
import QtQuick.Window 2.2
import Checkerboard 1.0
import Obstacles 1.0

Window {
    visible: true
    width: 640
    height: 480

    onWidthChanged: {
        console.log(width, " ", height)
    }

    QtObject {
        id: globals
        readonly property real pixelsPerMeter: 15.0
    }

    Item {
        anchors.fill: parent
        Component.onCompleted: {
            simulation.addVehicle(width / 2 / globals.pixelsPerMeter, 3.0, 1.5, 3.5, 0, 0)
            simulation.addVehicle(width / 2 / globals.pixelsPerMeter, 3.0, 1.5, 3.5, 0, 50)
            simulation.overrideAxleAngle(1, 15)
        }

        Timer {
            interval: 16
            repeat: true
            running: true
            property real time: 0
            onTriggered: {
                time += interval
                simulation.setTime(time)
            }
        }
    }

    Checkerboard {
        anchors.fill: parent
        step: 50
        color1: "white"
        color2: "grey"
    }

    Obstacles {
        anchors.fill: parent
        meterInPixels: globals.pixelsPerMeter
    }

    Repeater {
        model: simulation.vehicles
        Rectangle {
            id: rect
            x: simulation.vehicles[index].x * globals.pixelsPerMeter
            y: simulation.vehicles[index].y * globals.pixelsPerMeter
            width: simulation.vehicles[index].width * globals.pixelsPerMeter
            height: simulation.vehicles[index].height * globals.pixelsPerMeter
            rotation: 90 + simulation.vehicles[index].rotation
            color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);
        }
    }
}
