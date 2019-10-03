#include "RequestBackend.h"

RequestBackend::RequestBackend(QObject* parent)
    : QObject(parent)
    , m_everything{ new Everything() }
    , m_sources{ new Sources() }
    , m_trending{ new Trending() }
{
    //Do for everything as well
    connect(m_sources, &Sources::updateSources, this, &RequestBackend::onSourcesUpdated);
    connect(m_trending, &Trending::updateTrendingNews, this, &RequestBackend::onTrendingNewsUpdated);
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

void RequestBackend::onSourcesUpdated(const QVector<Source>& sources)
{
}

void RequestBackend::onTrendingNewsUpdated(const QVector<Article>& articles)
{
}
