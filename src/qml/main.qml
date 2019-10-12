import Felgo 3.0
import QtQuick 2.0
import QtQuick.Window 2.2

import 'Sources'
import 'Trending'
import 'Custom'

//import com.Application.Backend 1.0

App
{

    //    screenWidth: Screen.width
    //    screenHeight: Screen.height

    Navigation
    {

        id: navigation
        // Comment to use a navigation drawer instead of tabs on Android

       NavigationItem
        {
            title: qsTr("Trending")
            icon: IconType.bolt

            NavigationStack
            {

                Trending
                {
                    id: trending
                }
            }
        }

        NavigationItem
        {
            title: qsTr("Custom")
            icon: IconType.search
            NavigationStack
            {
                Custom
                {
                    id: custom
                }
            }
        }

        // TODO add your custom pages here
        NavigationItem
        {
            title: qsTr("Sources")
            icon: IconType.book
            NavigationStack
            {
                Sources
                {
                    id: sources
                }
            }
        }
    }

    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

}



















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
