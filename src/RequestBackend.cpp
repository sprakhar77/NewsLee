#include "RequestBackend.h"

RequestBackend::RequestBackend(QObject* parent)
    : QObject(parent)
    , m_everythingAPI{ new EverythingAPI() }
    , m_sourcesAPI{ new SourcesAPI() }
    , m_trendingAPI{ new TrendingAPI() }
{
    //Do for everything as well
    connect(m_sourcesAPI, &SourcesAPI::sourcesChanged, this, &RequestBackend::onSourcesChanged);
    connect(m_trendingAPI, &TrendingAPI::trendingNewsChanged, this, &RequestBackend::onTrendingNewsChanged);
}

EverythingAPI* RequestBackend::everythingAPI() const
{
    return m_everythingAPI;
}

SourcesAPI* RequestBackend::sourcesAPI() const
{
    return m_sourcesAPI;
}

TrendingAPI* RequestBackend::trendingAPI() const
{
    return m_trendingAPI;
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
    const auto trendingArticles = m_trendingAPI->trending();
    for (const auto article : trendingArticles) {
        qDebug() << article.title() << " ";
    }
}
