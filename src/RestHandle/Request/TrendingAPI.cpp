#include "TrendingAPI.h"

#include <Qurl>

namespace {
namespace ApiEndpoint {
    const char* const URL_TRENDING = "https://newsapi.org/v2/top-headlines?country=us";
}
}

TrendingAPI::TrendingAPI(QObject* parent)
    : QObject(parent)
{
}

QString TrendingAPI::country() const
{
    return m_country;
}

QString TrendingAPI::category() const
{
    return m_category;
}

QUrl TrendingAPI::prepareRequest()
{
    // Prepare the actuall request with all the query parameters here
    return QUrl(QLatin1String(ApiEndpoint::URL_TRENDING));
}

void TrendingAPI::setCountry(QString country)
{
    if (m_country == country)
        return;

    m_country = country;
    emit countryChanged(m_country);
}

void TrendingAPI::setCategory(QString category)
{
    if (m_category == category)
        return;

    m_category = category;
    emit categoryChanged(m_category);
}