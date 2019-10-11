import Felgo 3.0
import QtQuick 2.0

import 'Sources'
import 'Trending'
import 'Custom'

//import com.Application.Backend 1.0

App {
    Navigation {

        // Comment to use a navigation drawer instead of tabs on Android
        navigationMode: navigationModeTabs

        // TODO add your custom pages here
        NavigationItem {
            title: qsTr("Sources")
            icon: IconType.square

            Sources {
                id: sources
            }
        }

        NavigationItem {
            title: qsTr("Trending")
            icon: IconType.circle

            Trending {
                id: trending
            }

        }

        NavigationItem {
            title: qsTr("Custom")
            icon: IconType.circle

            Custom {
                id: custom
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
