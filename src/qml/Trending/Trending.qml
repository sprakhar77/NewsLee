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
                Layout.preferredHeight: screenHeight
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

                Rectangle
                {
                    anchors.bottom: parent.bottom
                    color: "black"
                    width: parent.width
                    height: 2
                }
            }
        }

//        PullToRefreshHandler
//        {
//            onRefresh:
//            {
//                Dispatcher.fetchTrending();
//            }
//        }
    }
}





/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
