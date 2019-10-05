#include "SourcesAPI.h"

#include <Qurl>

namespace {
namespace ApiEndpoint {
    const char* const URL_SOURCES = "https://newsapi.org/v2/sources";
}
}

SourcesAPI::SourcesAPI(QObject* parent)
    : QObject(parent)
{
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

QUrl SourcesAPI::prepareRequest()
{
    // prepare the actual request here with all the query parameters
    return QUrl(QLatin1String(ApiEndpoint::URL_SOURCES));
}

void SourcesAPI::setCountry(QString country)
{
    if (m_country == country)
        return;

    m_country = country;
    emit countryChanged();
}

void SourcesAPI::setCategory(QString category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged();
}

void SourcesAPI::setLanguage(QString language)
{
    if (m_language == language)
        return;

    m_language = language;
    emit languageChanged();
}
