## NewsLee

A cross platform news application written in C++/Qt/QML, uses REST services to querry various endpoints from NewsAPI 

There are still some small things that needs to be done to support even more features, the backend already has the infrastructure to support and store custom queris with advanced filters like -

TODOS
* Search news from a given start date to end data
* Sort the articles by popularity, relevancy and published date
* Show the list of sources with their name, description, Url etc.

This involes some work in the UI but fairley less in the backend, where simply adding query parameters to(CustonAPI::prepareRequest(), TrendingAPI::prepareRequest()) the REST calls for the respective API's will do the trick.

### IOS
<table width = "100%">
<td><img src = "resources/images/1.png" width = 250 height = 600></td>
<td align = "center"><img src = "resources/images/2.png" width = 250 height = 600></td>
<td align = "right"><img src = "resources/images/3.png" width = 250 height = 600></td>
</table>
<br>
<table width = "100%">
<td><img src = "resources/images/6.png" width = 250 height = 600></td>
<td align = "center"><img src = "resources/images/7.png" width = 250 height = 600></td>
<td align = "right"><img src = "resources/images/8.png" width = 250 height = 600></td>
</table>

<br>
<br>

### Android
<table width = "100%">
<td><img src = "resources/images/10.png" width = 250 height = 600></td>
<td align = "center"><img src = "resources/images/11.png" width = 250 height = 600></td>
<td align = "right"><img src = "resources/images/13.png" width = 250 height = 600></td>
</table>
<br>
<table width = "100%">
<td><img src = "resources/images/14.png" width = 250 height = 600></td>
<td align = "center"><img src = "resources/images/12.png" width = 250 height = 600></td>
<td align = "right"><img src = "resources/images/10.png" width = 250 height = 600></td>
</table>
