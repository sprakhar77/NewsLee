import Felgo 3.0
import QtQuick 2.0
import QtQuick.Controls 2.0 as QuickControls2

Page
{
    id: control

    readonly property QtObject sourcesBackend: Dispatcher.sourcesBackend

    title: "Sources"

    // tabs
    AppTabBar
    {
        id: appTabBar
        contentContainer: swipeView

        AppTabButton
        {
            text: "Category"
        }
        AppTabButton
        {
            text: "Country"
        }
        AppTabButton
        {
            text: "Language"
        }
    }

    // tab contents
    QuickControls2.SwipeView
    {
        id: swipeView
        anchors.top: appTabBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        clip: true

        TabSection
        {
            model: sourcesBackend.sourcesAPI.category
        }
        TabSection
        {
            model: sourcesBackend.sourcesAPI.country
        }
        TabSection
        {
            model: sourcesBackend.sourcesAPI.language
        }
    }
} // Page

