#include "TrendingAPI.h"

#include <QJsonArray>

namespace {
namespace ApiEndpoint {
    const char* const URL_TRENDING = "https://newsapi.org/v2/top-headlines?country=us";
}

namespace JsonKeys {
    const char* const TOTAL_RESULTS = "totalResults";
    const char* const ARTICLES = "articles";
}
}

TrendingAPI::TrendingAPI(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
    QObject::connect(&m_restClient, &RestClient::responseRecieved, this, &TrendingAPI::handleRestResponse);
}

QString TrendingAPI::country() const
{
    return m_country;
}

QString TrendingAPI::category() const
{
    return m_category;
}

QVector<Article> TrendingAPI::trending() const
{
    return m_trending;
}

void TrendingAPI::fetch()
{
    m_restClient.sendRequest(QUrl(ApiEndpoint::URL_TRENDING));
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

void TrendingAPI::handleRestResponse(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_trending.clear();
    const auto trendingArray = json[QLatin1String(JsonKeys::ARTICLES)].toArray();
    for (const auto trending : trendingArray) {
        m_trending.append(Article(trending.toObject()));
    }
    emit trendingNewsChanged();
}
