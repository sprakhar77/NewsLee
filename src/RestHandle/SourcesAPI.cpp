#include "SourcesAPI.h"

#include <QJsonArray>

namespace {
namespace ApiEndpoint {
    const char* const URL_SOURCES = "https://newsapi.org/v2/sources";
}
namespace JsonKeys {
    const char* const SOURCES = "sources";
}
}

SourcesAPI::SourcesAPI(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
    QObject::connect(&m_restClient, &RestClient::responseRecieved, this, &SourcesAPI::handleRestResponse);
}

QString SourcesAPI::country() const
{
    return m_country;
}

QString SourcesAPI::category() const
{
    return m_category;
}

QString SourcesAPI::language() const
{
    return m_language;
}

QVector<Source> SourcesAPI::sources() const
{
    return m_sources;
}

void SourcesAPI::fetch()
{
    m_restClient.sendRequest(QUrl(ApiEndpoint::URL_SOURCES));
}

void SourcesAPI::setCountry(QString country)
{
    if (m_country == country)
        return;

    m_country = country;
    emit countryChanged(m_country);
}

void SourcesAPI::setCategory(QString category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged(m_category);
}

void SourcesAPI::setLanguage(QString language)
{
    if (m_language == language)
        return;

    m_language = language;
    emit languageChanged(m_language);
}

void SourcesAPI::handleRestResponse(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_sources.clear();
    const auto sources = json[QLatin1String(JsonKeys::SOURCES)].toArray();
    for (const auto source : sources) {
        m_sources.append(Source(source.toObject()));
    }
    emit sourcesChanged();
}
