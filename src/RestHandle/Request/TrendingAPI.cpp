#include "TrendingAPI.h"

#include <Qurl>

namespace {
namespace ApiEndpoint {
    const char* const URL_TRENDING = "https://newsapi.org/v2/top-headlines?country=us";
}
}

TrendingAPI::TrendingAPI(QObject* parent)
    : QObject(parent)
{
}

QUrl TrendingAPI::prepareRequest()
{
    // Prepare the actuall request with all the query parameters here
    return QUrl(QLatin1String(ApiEndpoint::URL_TRENDING));
}

void TrendingAPI::addSource(const QString& source)
{
    m_sourcesToFetchFrom.push_back(source);
}

QString TrendingAPI::searchkeyword() const
{
    return m_searchkeyword;
}

void TrendingAPI::setSearchkeyword(QString searchkeyword)
{
    if (m_searchkeyword == searchkeyword)
        return;

    m_searchkeyword = searchkeyword;
    emit searchkeywordChanged();
}