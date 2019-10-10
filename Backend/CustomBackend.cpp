#include "CustomBackend.h"

#include <QJsonArray>

namespace {

namespace JsonKeys {
    const char* const TOTAL_RESULTS = "totalResults";
    const char* const ARTICLES = "articles";
}
}

CustomBackend::CustomBackend(QObject* parent)
    : QObject(parent)
    , m_customAPI{ new CustomAPI(this) }
    , m_articleModel{ new ArticleModel(this) }
{
    connect(&m_restClient, &RestClient::responseRecieved, this, &CustomBackend::onResponseRecieved);
}

CustomAPI* CustomBackend::customAPI() const
{
    return m_customAPI;
}

ArticleModel* CustomBackend::articleModel() const
{
    return m_articleModel;
}

void CustomBackend::fetch(const QVector<QString>&sources)
{
    Q_ASSERT(m_customAPI);
    const QUrl url = m_customAPI->prepareRequest();

    //TODO: Add sources to query
    m_restClient.sendRequest(url);
}

void CustomBackend::onResponseRecieved(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_articleModel->clearArticles();
    const auto customNews = json[QLatin1String(JsonKeys::ARTICLES)].toArray();
    for (const auto trendingArticle : customNews) {
        m_articleModel->addArticle(new Article(trendingArticle.toObject()));
    }
}
