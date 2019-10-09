#include "TrendingAPI.h"

#include <QUrl>

namespace {
namespace ApiEndpoint {
    const char* const URL_TRENDING = "https://newsapi.org/v2/top-headlines?country=us";
}
}

TrendingAPI::TrendingAPI(QObject* parent)
    : QObject(parent)
{
    m_country = CheckableModelFactory::create(CheckableModelFactory::ModelType::Country);
    m_category = CheckableModelFactory::create(CheckableModelFactory::ModelType::Category);
    m_pageSize = CheckableModelFactory::create(CheckableModelFactory::ModelType::PageSize);
    m_sortBy = CheckableModelFactory::create(CheckableModelFactory::ModelType::SortBy);
}

QUrl TrendingAPI::prepareRequest()
{
    //TODO: Prepare the actuall request with all the query parameters here
    return QUrl(QLatin1String(ApiEndpoint::URL_TRENDING));
}
CheckableModel* TrendingAPI::country() const
{
    return m_country;
}
CheckableModel* TrendingAPI::category() const
{
    return m_category;
}
CheckableModel* TrendingAPI::pageSize() const
{
    return m_pageSize;
}
CheckableModel* TrendingAPI::sortBy() const
{
    return m_sortBy;
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