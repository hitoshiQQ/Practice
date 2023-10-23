import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("VideoPlayer")


    Rectangle {
        id: rectangle
        width: 540
        height: 360
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -50
        color: "#3f2aff"
        Text {
                id: text
                text: "Pause"
                font.pointSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#3f2aff"
        }
    }

    ProgressBar {
        id: progressBar
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 150
        width: 540
        to: 5.0
    }

    Timer {
        id: timer
        interval: 500; running: false; repeat: true
        onTriggered: progressBar.value += 0.1;
    }


    Button {
        text: "▶️"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -220
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        onClicked: {
            if (timer.repeat == false)
                timer.repeat = true
            timer.start()

            text.color = "#3f2aff"
        }
    }

    Button {
        text: "⏸"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -110
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        onClicked: {
            timer.repeat = false
            text.color = "Yellow"
        }
    }

    Button {
        text: "⏹"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        onClicked: {
            timer.stop()
            progressBar.value = 0.0
            text.color = "Red"
        }
    }

    Button {
        text: "⏪"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 110
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        onClicked: {
            progressBar.value -= 0.1
            if (timer.repeat == true)
                text.color = "#3f2aff"
            else
                text.color != "white"
        }
    }

    Button {
        text: "⏩"
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 220
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        onClicked: {
            progressBar.value += 0.2
            if (timer.repeat == true)
                text.color = "#3f2aff"
            else
                text.color != "white"
        }
    }
}
