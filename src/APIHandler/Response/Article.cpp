#include "Article.h"

#include <QDateTime>
#include <QUrl>

namespace {
namespace JsonKeys {
    const char* const ARTICLE_AUTHOR = "author";
    const char* const ARTICLE_TITLE = "title";
    const char* const ARTICLE_DESCRIPTION = "description";
    const char* const ARTICLE_URL = "url";
    const char* const ARTICLE_URL_TO_IMAGE = "urlToImage";
    const char* const ARTICLE_PUBLISHED_AT = "publishedAt";
    const char* const ARTICLE_CONTENT = "content";
    const char* const ARTICLE_SOURCE = "source";

    namespace SOURCE {
        const char* const ARTICLE_SOURCE_ID = "id";
        const char* const ARTICLE_SOURCE_NAME = "name";
    }
}
}

Article::Article(QJsonObject json)
    : m_json(json)
{
}

bool Article::isComplete()
{
    return !m_json.isEmpty();
}

QString Article::sourceId()
{
    Q_ASSERT(isComplete());
    const QJsonObject source = m_json.value(JsonKeys::ARTICLE_SOURCE).toObject();
    return source.value(QLatin1String(JsonKeys::SOURCE::ARTICLE_SOURCE_ID)).toString();
}

QString Article::sourceName()
{
    Q_ASSERT(isComplete());
    const QJsonObject source = m_json.value(JsonKeys::ARTICLE_SOURCE).toObject();
    return source.value(QLatin1String(JsonKeys::SOURCE::ARTICLE_SOURCE_NAME)).toString();
}

QString Article::author()
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::ARTICLE_AUTHOR)).toString();
}

QString Article::title()
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::ARTICLE_TITLE)).toString();
}

QString Article::description()
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::ARTICLE_DESCRIPTION)).toString();
}

QUrl Article::url()
{
    Q_ASSERT(isComplete());
    return QUrl(m_json.value(QLatin1String(JsonKeys::ARTICLE_URL)).toString());
}

QUrl Article::urlToImage()
{
    Q_ASSERT(isComplete());
    return QUrl(m_json.value(QLatin1String(JsonKeys::ARTICLE_URL_TO_IMAGE)).toString());
}

QDateTime Article::publishedAt()
{
    Q_ASSERT(isComplete());
    return QDateTime::fromString(m_json.value(QLatin1String(JsonKeys::ARTICLE_PUBLISHED_AT)).toString(), Qt::ISODate);
}

QString Article::content()
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::ARTICLE_CONTENT)).toString();
}
