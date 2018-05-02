import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Item {
    visible: true
    width: 338
    height: 210
    id: userInput

    signal sendMsgSignal(string msg)

    function addMessage(msg) {
        chatArea.append(msg)
        return
    }

    TextArea  {
        id: chatArea
        anchors.top: userInput.top
        anchors.right: userInput.right
        anchors.left: userInput.left
        anchors.bottom: inputField.top
    }

    TextField {
        anchors.bottom: userInput.bottom
        anchors.left: userInput.left
        anchors.right: sendButton.left
        id: inputField
        height: 20
        placeholderText: qsTr("Enter the message")
    }

    Button
    {
        id: sendButton
        anchors.bottom: userInput.bottom
        anchors.right: userInput.right
        width: 20
        text: ">"
        onClicked:
        {
            userInput.sendMsgSignal(inputField.text)
            inputField.remove(0, inputField.length)
        }
    }

    Keys.onReturnPressed:
    {
        userInput.sendMsgSignal(inputField.text)
        inputField.remove(0, inputField.length)

    }



}
