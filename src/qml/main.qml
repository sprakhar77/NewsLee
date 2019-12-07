import Felgo 3.0
import QtQuick 2.0
import QtQuick.Window 2.2

import 'Sources'
import 'Trending'
import 'Custom'

App
{
    Navigation
    {
        id: navigation

        NavigationItem
        {
            title: qsTr("Trending")
            icon: IconType.bolt

            NavigationStack
            {
                Trending {}
            }
        }

        NavigationItem
        {
            title: qsTr("Custom")
            icon: IconType.search
            NavigationStack
            {
                Custom {}
            }
        }

        NavigationItem
        {
            title: qsTr("Sources")
            icon: IconType.book
            NavigationStack
            {
                Sources {}
            }
        }
    }
}
