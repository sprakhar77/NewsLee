import Felgo 3.0
import QtQuick 2.0
import QtQuick.Controls 2.4

Rectangle
{
    id: control

    property QtObject model: null
    readonly property QtObject sourcesBackend: Dispatcher.sourcesBackend

    AppListView
    {
        anchors.fill: parent
        model: control.model
        delegate: SimpleRow
        {
            text: model.name
            badgeValue: model.checked ? qsTr("Selected") : qsTr("")
            onSelected:
            {
                model.checked = !model.checked
                sourcesBackend.updateSources()
            }
        }
    }
}
