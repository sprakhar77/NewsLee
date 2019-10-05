import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import com.Application.Backend 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("News App")

    Loader
    {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: pageSwapButtons.top
        source: Dispatcher.currentPage
    }

    RowLayout
    {
        id: pageSwapButtons

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        Button
        {
            id: trending

            height: 40
            text: "Trending"

            onClicked:
            {
                Dispatcher.setApplicationPage(ApplicationEnums.ApplicationPage.TRENDING)
            }
        }
        Button
        {
            id: sources

            height: 40
            text:"Sources"

            onClicked:
            {
                Dispatcher.setApplicationPage(ApplicationEnums.ApplicationPage.SOURCES)
            }
        }
        Button
        {
            id: custom

            height: 40
            text: "Custom"

            onClicked:
            {
                Dispatcher.setApplicationPage(ApplicationEnums.ApplicationPage.CUSTOM)
            }
        }
    }
}