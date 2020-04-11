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
    }
}
