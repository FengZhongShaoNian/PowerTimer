import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: applicationWindow
    objectName: "applicationWindow"
    visible: true
    width: 320
    height: 480
    title: qsTr("PowerTimer")
    flags: Qt.MSWindowsFixedSizeDialogHint | Qt.WindowTitleHint | Qt.WindowSystemMenuHint | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint

    Page1 {
    }

    Connections {
        target: applicationWindow
        onWindowStateChanged: {
            if(windowState === Qt.WindowMinimized){
                applicationWindow.hide();
            }
        }
    }
}
