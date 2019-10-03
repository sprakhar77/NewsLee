#include "RequestBackend.h"

RequestBackend::RequestBackend(QObject* parent)
    : QObject(parent)
    , m_customAPI{ new CustomAPI() }
    , m_sourcesAPI{ new SourcesAPI() }
    , m_trendingAPI{ new TrendingAPI() }
{
    //Do for everything as well
    connect(m_sourcesAPI, &SourcesAPI::sourcesChanged, this, &RequestBackend::onSourcesChanged);
    connect(m_trendingAPI, &TrendingAPI::trendingNewsChanged, this, &RequestBackend::onTrendingNewsChanged);
}

CustomAPI* RequestBackend::customAPI() const
{
    return m_customAPI;
}

SourcesAPI* RequestBackend::sourcesAPI() const
{
    return m_sourcesAPI;
}

TrendingAPI* RequestBackend::trendingAPI() const
{
    return m_trendingAPI;
}

void RequestBackend::fetchSources()
{
    m_sourcesAPI->fetch();
}

void RequestBackend::fetchTrending()
{
    m_trendingAPI->fetch();
}

void RequestBackend::onSourcesChanged()
{
    const auto updatedSources = m_sourcesAPI->sources();
    for (const auto source : updatedSources) {
        qDebug() << source.name() << " ";
    }
}

void RequestBackend::onTrendingNewsChanged()
{
    const auto trendingArticles = m_trendingAPI->trendingArticles();
    for (const auto article : trendingArticles) {
        qDebug() << article.title() << " ";
    }
}
