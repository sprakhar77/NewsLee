#include "Sources.h"

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
}
