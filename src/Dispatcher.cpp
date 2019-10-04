#include "Dispatcher.h"

#include <src/Backend/CustomBackend.h>
#include <src/Backend/SourcesBackend.h>
#include <src/Backend/TrendingBackend.h>

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_trendingBackend{ new TrendingBackend(this) }
    , m_sourcesBackend{ new SourcesBackend(this) }
    , m_customBackend{ new CustomBackend(this) }
{
}

TrendingBackend* Dispatcher::trendingBackend() const
{
    return m_trendingBackend;
}

SourcesBackend* Dispatcher::sourcesBackend() const
{
    return m_sourcesBackend;
}

CustomBackend* Dispatcher::customBackend() const
{
    return m_customBackend;
}
