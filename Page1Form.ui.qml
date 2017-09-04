import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Qt.labs.calendar 1.0

Item {
    width: 320
    property alias comboBoxDay: comboBoxDay
    property alias comboBoxHour: comboBoxHour
    property alias comboBoxMinute: comboBoxMinute
    property alias comboBoxOperation: comboBoxOperation
    property alias timerSwitch: timerSwitch

    ComboBox {
        id: comboBoxDay
        x: 60
        y: 64
        width: 200
        height: 40
    }

    ComboBox {
        id: comboBoxHour
        x: 60
        y: 151
        width: 200
        height: 40
    }

    ComboBox {
        id: comboBoxMinute
        x: 60
        y: 232
        width: 200
        height: 40
    }

    ComboBox {
        id: comboBoxOperation
        x: 60
        y: 311
        width: 200
        height: 40
    }

    Switch {
        id: timerSwitch
        x: 59
        y: 386
        width: 140
        height: 40
    }
}
