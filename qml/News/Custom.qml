import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

ColumnLayout{
    anchors.fill: parent
    spacing: 0

    ListView{
        id: mListView
        model: Dispatcher.customBackend.articleModel
        delegate: Rectangle{
            width: parent.width
            height: textId.implicitHeight + 30
            color: "beige"
            border.color: "yellowgreen"
            radius: 5

            Text{
                id: textId
                width: parent.height
                height: parent.height
                anchors.centerIn: parent
                text: model.description
                font.pointSize: 13
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Layout.fillHeight: true
        Layout.fillWidth: true

    }

    SpinBox{
        id: spinBoxId
        Layout.fillWidth: true
        value: 10
    }

    Button{
        id : mButton1
        text: "Fetch"
        onClicked: {
            Dispatcher.fetchCustom();
        }
        Layout.fillWidth: true
    }
}
