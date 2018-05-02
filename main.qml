import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import com.ics.demo 1.0

ApplicationWindow
{
    id: root
    visible: true
    width: 300
    height: 50
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    title: qsTr("chat app")


    ChatCore
    {
        id: core
    }

    Button
    {
        width: 100
        height: 23
        text: "Add new user"
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: -7
        anchors.centerIn: parent;
        onClicked: {
            core.createNewUser()
        }
    }

    onClosing:
    {
        core.destroy()
    }
}
