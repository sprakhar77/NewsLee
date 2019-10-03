#include "Trending.h"

Trending::Trending(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
    QObject::connect(&m_restClient, &RestClient::responseRecieved, this, &Trending::handleRestResponse);
}

QString Trending::country() const
{
    return m_country;
}

QString Trending::category() const
{
    return m_category;
}

void Trending::setCountry(QString country)
{
    if (m_country == country)
        return;

    m_country = country;
    emit countryChanged(m_country);
}

void Trending::setCategory(QString category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged(m_category);
}

void Trending::handleRestResponse(const QJsonObject& json)
{
}
