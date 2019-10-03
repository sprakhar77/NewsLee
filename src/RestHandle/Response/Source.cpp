#include "Source.h"

#include <QUrl>

namespace {
namespace JsonKeys {
    const char* const SOURCE_ID = "id";
    const char* const SOURCE_NAME = "name";
    const char* const SOURCE_DESCRIPTION = "description";
    const char* const SOURCE_URL = "url";
    const char* const SOURCE_CATEGORY = "category";
    const char* const SOURCE_LANGUAGE = "language";
    const char* const SOURCE_COUNTRY = "country";
}
}

Source::Source(const QJsonObject& json)
    : m_json(json)
{
}

bool Source::isComplete() const
{
    return !m_json.isEmpty();
}

QString Source::id() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_ID)).toString();
}

QString Source::name() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_NAME)).toString();
}

QString Source::description() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_DESCRIPTION)).toString();
}

QUrl Source::url() const
{
    Q_ASSERT(isComplete());
    return QUrl(m_json.value(QLatin1String(JsonKeys::SOURCE_URL)).toString());
}

QString Source::category() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_CATEGORY)).toString();
}

QString Source::language() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_LANGUAGE)).toString();
}

QString Source::country() const
{
    Q_ASSERT(isComplete());
    return m_json.value(QLatin1String(JsonKeys::SOURCE_COUNTRY)).toString();
}
