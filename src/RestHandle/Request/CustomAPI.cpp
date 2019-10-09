#include "CustomAPI.h"

#include <QUrl>

namespace {
namespace ApiEndpoint {
    const char* const URL_CUSTOM = "https://newsapi.org/v2/everything?q=bitcoin";
}
}

CustomAPI::CustomAPI(QObject* parent)
    : QObject(parent)
{
    m_pageSize = CheckableModelFactory::create(CheckableModelFactory::ModelType::PageSize);
    m_sortBy = CheckableModelFactory::create(CheckableModelFactory::ModelType::SortBy);
    m_language = CheckableModelFactory::create(CheckableModelFactory::ModelType::Language);
}

QString CustomAPI::searchkeyword() const
{
    return m_searchkeyword;
}

QUrl CustomAPI::prepareRequest()
{
    //TODO: Prepare the actuall request with all the query parameters here
    return QUrl(QLatin1String(ApiEndpoint::URL_CUSTOM));
}

CheckableModel* CustomAPI::pageSize() const
{
    return m_pageSize;
}

CheckableModel* CustomAPI::sortBy() const
{
    return m_sortBy;
}

CheckableModel* CustomAPI::language() const
{
    return m_language;
}

QDateTime CustomAPI::from() const
{
    return m_from;
}

QDateTime CustomAPI::to() const
{
    return m_to;
}

void CustomAPI::setSearchkeyword(QString searchkeyword)
{
    if (m_searchkeyword == searchkeyword)
        return;

    m_searchkeyword = searchkeyword;
    emit searchkeywordChanged();
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
