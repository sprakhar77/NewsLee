#include "Trending.h"

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

QVector<Article> Trending::trending() const
{
    return m_trending;
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
    Q_ASSERT(!json.empty());
    m_trending.clear();
    const auto trendingArray = json[QLatin1String(JsonKeys::ARTICLES)].toArray();
    for (const auto trending : trendingArray) {
        m_trending.append(Article(trending.toObject()));
    }
    emit trendingNewsChanged();
}
