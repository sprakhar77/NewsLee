import Felgo 3.0
import QtQuick 2.0
import QtQuick.Layouts 1.3

/*

// EXAMPLE USAGE:
// add the following piece of code inside your App { } to display the List Page

Trending {

}

*/

Page
{
    id: control

    title: "Trending"

    SearchBar
    {
        id: searchBar
        target: listView
        pullEnabled: true
        onAccepted:
        {
            console.log("search accepted: "+text)

            // if the search bar is not empty, we prevent it from disappearing
            if(text !== "")
            {
                searchBar.keepVisible = true
                Dispatcher.trendingBackend.trendingAPI.searchKeyword = text
                Dispatcher.fetchTrending()
                // update result
            }
            else
            {
                // initial settings
                searchBar.keepVisible = false
            }
        }
    }

    AppListView
    {
        id: listView

        model: Dispatcher.trendingBackend.articleModel
        delegate: ColumnLayout
        {

            Rectangle
            {
                Layout.preferredHeight: screenHeight - 140
                Layout.preferredWidth: screenWidth

                AppImage
                {
                    id: image

                    width: parent.width
                    height: parent.height/3
                    source: model.urlToImage
                }

                AppText
                {
                    id: title

                    anchors.top: image.bottom
                    anchors.topMargin: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    text: model.title
                    font.family: "Verdana"
                    font.bold: true
                    wrapMode: Text.WordWrap
                }

                AppText
                {
                    id :content

                    anchors.top: title.bottom
                    anchors.topMargin: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    font.family: "Verdana"
                    text: model.content
                    elide: Text.ElideRight
                    wrapMode: Text.WordWrap
                }

                SimpleButton
                {
                    anchors.bottom: parent.bottom
                    color: "#dcdcdc"
                    width: parent.width
                    height: 40
                    text: "Click here to read full article"
                    textColor: "white"
                    pixelSize: 18
                    hoveredLighterFactor: 0.8
                    onClicked:
                    {
                        nativeUtils.openUrl(model.url)
                    }
                }
            }
        }

        PullToRefreshHandler
        {
            onRefresh:
            {
                Dispatcher.fetchTrending();
            }
        }

        AppActivityIndicator
        {
            id: activiyIndicator

            animating: false
            hidesWhenStopped: true
            anchors.centerIn: parent

        }

        Connections
        {
            target: Dispatcher.trendingBackend

            onModelUpdateStarted:
            {
                activiyIndicator.startAnimating()
            }

            onModelUpdateFinished:
            {
                activiyIndicator.stopAnimating()
            }
        }
    }
}





/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
