#include "TrendingAPI.h"

#include <QUrl>
#include <QUrlQuery>

namespace {
namespace ApiEndpoint {
    const char* const URL_TRENDING = "https://newsapi.org/v2/top-headlines?country=us";
}
}

TrendingAPI::TrendingAPI(QObject* parent)
    : QObject(parent)
{
    m_sortBy = CheckableModelFactory::create(CheckableModelFactory::ModelType::SortBy);
}

QUrl TrendingAPI::prepareRequest()
{
    QUrl url = QUrl(QLatin1String(ApiEndpoint::URL_TRENDING));
    QUrlQuery query;
    if (!m_searchKeyword.isEmpty()) {
        query.addQueryItem("q", m_searchKeyword);
    }
    return url;
}

CheckableModel* TrendingAPI::sortBy() const
{
    return m_sortBy;
}

QString TrendingAPI::searchKeyword() const
{
    return m_searchKeyword;
}

void TrendingAPI::setSearchKeyword(QString searchKeyword)
{
    if (m_searchKeyword == searchKeyword)
        return;

    m_searchKeyword = searchKeyword;
    emit searchKeywordChanged();
}