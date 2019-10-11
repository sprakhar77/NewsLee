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
    AppListView
    {
        anchors.fill: parent
        model: Dispatcher.trendingBackend.articleModel
        delegate: ColumnLayout
        {
            spacing: 10
            AppImage
            {
                id: image

                Layout.preferredWidth: screenWidth
                Layout.maximumHeight: screenHeight/3
                source: model.urlToImage
                fillMode: Image.PreserveAspectFit
            }

            AppText
            {
                text: model.title
                wrapMode: Text.WordWrap
                Layout.preferredWidth: screenWidth
            }

            AppText
            {
                text: model.content
                wrapMode: Text.WordWrap
                Layout.preferredWidth: screenWidth
            }

        }
    }

}
