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
    , m_articleModel{ new ArticleModel(this) }
{
    connect(&m_restClient, &RestClient::responseRecieved, this, &TrendingBackend::onResponseRecieved);
}

TrendingAPI* TrendingBackend::trendingAPI() const
{
    return m_trendingAPI;
}

ArticleModel* TrendingBackend::articleModel() const
{
    return m_articleModel;
}

void TrendingBackend::fetch()
{
    Q_ASSERT(m_trendingAPI);
    const QUrl url = m_trendingAPI->prepareRequest();
    m_restClient.sendRequest(url);
}

void TrendingBackend::onResponseRecieved(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_articleModel->clearArticles();
    const auto trendingArray = json[QLatin1String(JsonKeys::ARTICLES)].toArray();
    for (const auto trending : trendingArray) {
        Article* article = new Article(trending.toObject());
        m_articleModel->addArticle(article);
    }
}
