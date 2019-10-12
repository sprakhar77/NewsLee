#include "CustomAPI.h"

#include <QUrl>
#include <QUrlQuery>

namespace {
namespace ApiEndpoint {
    const char* const URL_CUSTOM = "https://newsapi.org/v2/everything?q=bitcoin";
}
}

CustomAPI::CustomAPI(QObject* parent)
    : QObject(parent)
{
    m_sortBy = CheckableModelFactory::create(CheckableModelFactory::ModelType::SortBy);
}

QString CustomAPI::searchKeyword() const
{
    return m_searchKeyword;
}

QUrl CustomAPI::prepareRequest()
{
    //TODO: Prepare the actuall request with all the query parameters here
    return QUrl(QLatin1String(ApiEndpoint::URL_CUSTOM));
}

CheckableModel* CustomAPI::sortBy() const
{
    return m_sortBy;
}

QDateTime CustomAPI::from() const
{
    return m_from;
}

QDateTime CustomAPI::to() const
{
    return m_to;
}

void CustomAPI::setSearchKeyword(QString searchKeyword)
{
    if (m_searchKeyword == searchKeyword)
        return;

    m_searchKeyword = searchKeyword;
    emit searchKeywordChanged();
}

void CustomAPI::setFrom(QDateTime from)
{
    if (m_from == from)
        return;

    m_from = from;
    emit fromChanged();
}

void CustomAPI::setTo(QDateTime to)
{
    if (m_to == to)
        return;

    m_to = to;
    emit toChanged();
}
