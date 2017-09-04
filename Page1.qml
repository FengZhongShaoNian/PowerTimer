import QtQuick 2.7

Page1Form {
    id: root
    property string day: ""
    property string hour: ""
    property string minute: ""
    property string operation: ""

    function today(){
        return new Date();
    }

    comboBoxDay.textRole: "text"
    comboBoxDay.model: ListModel{
        id: dateModel
    }

    comboBoxHour.model: ["00点","01点","02点","03点","04点","05点","06点","07点","08点","09点","10点","11点","12点","13点","14点","15点","16点","17点","18点","19点","20点","21点","22点","23点"]

    comboBoxMinute.textRole: "text"
    comboBoxMinute.model:  ListModel{
        id: minuteModel
    }

    comboBoxOperation.model: ["定时关机", "定时重启"]
    timerSwitch.text: "未启动"
    timerSwitch.onClicked: {
        if(timerSwitch.checked === true){
            timerSwitch.text = "已启动";
            root.day = comboBoxDay.currentText;
            root.hour = comboBoxHour.currentText;
            root.minute = comboBoxMinute.currentText;
            root.operation = comboBoxOperation.currentText;

            comboBoxDay.enabled = false;
            comboBoxHour.enabled = false;
            comboBoxMinute.enabled = false;
            comboBoxOperation.enabled = false;

            timer.start();
        }else{
            timerSwitch.text = "未启动";

            comboBoxDay.enabled = true;
            comboBoxHour.enabled = true;
            comboBoxMinute.enabled = true;
            comboBoxOperation.enabled = true;

            timer.stop();
        }
    }

    Timer{
        id: timer
        repeat: true
        interval: 1000 // 1秒
        onTriggered: {
            var date = new Date();
            var currentDate = date.toLocaleDateString(Qt.locale(), "yyyy年MM月dd日");
            var currentHour = date.toLocaleTimeString(Qt.locale(), "hh点");
            var currentMinute = date.toLocaleTimeString(Qt.locale(), "mm分");
            if(currentDate === root.day){
                if(currentHour === root.hour){
                    if(currentMinute === root.minute){
                        if(root.operation === "定时关机"){
                            power.shutdown();
                        }
                        else if(root.operation === "定时重启"){
                            power.reboot();
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        var date = today();

        for(var i = 0; i < 5; ++i){           
            comboBoxDay.model.append({text: date.toLocaleDateString(Qt.locale(), "yyyy年MM月dd日")});
            date.setDate(date.getDate() + 1);
        }
        comboBoxDay.currentIndex = 0;

        for(var j = 0; j < 60; ++j){
            if(j < 10){
                comboBoxMinute.model.append({text: "0" + j.toString() + "分"});
            }else{
                comboBoxMinute.model.append({text: j.toString() + "分"});
            }
        }
        comboBoxMinute.currentIndex = 0;
    }
}
