import QtQuick 2.7
import QtQuick.Controls 2.7
import QtQuick.Window 2.2

import QtZeroProps 1.0

Window {
    visible: true
    width: 320
    height: 480

    Column {
        width: parent.width
        height: parent.height

        ListView {
            width: parent.width
            model: QZeroPropsClient.discoveredServices
            delegate: Button {
                width: parent.width
                text: modelData.name
                onClicked: {
                    QZeroPropsClient.connectToService(modelData)
                }
            }
        }

        Button {
            width: parent.width
            anchors.bottom: parent.bottom
            text: "Start Discovery"
            onClicked: QZeroPropsClient.startDiscovery("_cornrow._tcp")
        }
    }
}
