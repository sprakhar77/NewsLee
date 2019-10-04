#include "TrendingBackend.h"

#include <QJsonArray>

namespace {

namespace JsonKeys {
    const char* const TOTAL_RESULTS = "totalResults";
    const char* const ARTICLES = "articles";
}
}

TrendingBackend::TrendingBackend(QObject* parent)
    : QObject(parent)
    , m_trendingAPI{ new TrendingAPI(this) }
{
    connect(&m_restClient, &RestClient::responseRecieved, this, &TrendingBackend::onResponseRecieved);
}

TrendingAPI* TrendingBackend::trendingAPI() const
{
    return m_trendingAPI;
}

QVector<Article> TrendingBackend::trendingArticles() const
{
    return m_trendingArticles;
}

void TrendingBackend::fetch()
{
    Q_ASSERT(!m_trendingAPI);
    const QUrl url = m_trendingAPI->prepareRequest();
    m_restClient.sendRequest(url);
}

void TrendingBackend::onResponseRecieved(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_trendingArticles.clear();
    const auto trendingArray = json[QLatin1String(JsonKeys::ARTICLES)].toArray();
    for (const auto trending : trendingArray) {
        m_trendingArticles.append(Article(trending.toObject()));
    }
}
