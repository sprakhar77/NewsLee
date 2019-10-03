import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {

    readonly property QtObject restClient: Dispatcher.restClient

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "green"

    Rectangle
    {
        id: textArea

        anchors
        {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: fetchButton.top
            bottomMargin: 40
        }
         color: "pink"

        TextArea
        {
            anchors.fill: parent
            readOnly: true
            color: "gray"
        }
    }

    Button
    {
        id: fetchButton

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        width: 80
        height: 80

        onClicked:
        {
            restClient.sendRequest();
        }
    }
}
