#include "Sources.h"

#include <QJsonArray>

namespace {
namespace ApiEndpoint {
    const char* const URL_SOURCES = "https://newsapi.org/v2/sources";
}
namespace JsonKeys {
    const char* const SOURCES = "sources";
}
}

Sources::Sources(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
    QObject::connect(&m_restClient, &RestClient::responseRecieved, this, &Sources::handleRestResponse);
}

QString Sources::country() const
{
    return m_country;
}

QString Sources::category() const
{
    return m_category;
}

QString Sources::language() const
{
    return m_language;
}

QVector<Source> Sources::sources() const
{
    return m_sources;
}

void Sources::setCountry(QString country)
{
    if (m_country == country)
        return;

    m_country = country;
    emit countryChanged(m_country);
}

void Sources::setCategory(QString category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged(m_category);
}

void Sources::setLanguage(QString language)
{
    if (m_language == language)
        return;

    m_language = language;
    emit languageChanged(m_language);
}

void Sources::handleRestResponse(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_sources.clear();
    const auto sources = json[QLatin1String(JsonKeys::SOURCES)].toArray();
    for (const auto source : sources) {
        m_sources.append(Source(source.toObject()));
    }
    emit sourcesChanged();
}
