#include "RequestBackend.h"

RequestBackend::RequestBackend(QObject* parent)
    : QObject(parent)
    , m_everything{ new Everything() }
    , m_sources{ new Sources() }
    , m_trending{ new Trending() }
{
    //Do for everything as well
    connect(m_sources, &Sources::sourcesChanged, this, &RequestBackend::onSourcesChanged);
    connect(m_trending, &Trending::trendingNewsChanged, this, &RequestBackend::onTrendingNewsChanged);
}

Everything* RequestBackend::everything() const
{
    return m_everything;
}

Sources* RequestBackend::sources() const
{
    return m_sources;
}

Trending* RequestBackend::trending() const
{
    return m_trending;
}

void RequestBackend::onSourcesChanged()
{
    const auto updatedSources = m_sources->sources();
    for (const auto source : updatedSources) {
        qDebug() << source.name() << " ";
    }
}

void RequestBackend::onTrendingNewsChanged()
{
    const auto trendingArticles = m_trending->trending();
    for (const auto article : trendingArticles) {
        qDebug() << article.title() << " ";
    }
}
