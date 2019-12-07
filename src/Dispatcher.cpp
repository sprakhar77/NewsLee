#include "Dispatcher.h"

#include <src/Backend/CustomBackend.h>
#include <src/Backend/SourcesBackend.h>
#include <src/Backend/TrendingBackend.h>
#include <src/Utils/Enums.h>

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_trendingBackend{ new TrendingBackend(this) }
    , m_sourcesBackend{ new SourcesBackend(this) }
    , m_customBackend{ new CustomBackend(this) }
{
}

void Dispatcher::fetchTrending()
{
    if (const auto sourcesModel = m_sourcesBackend->sourceModel()) {
        const auto selectedSources = sourcesModel->getSelectedSources();
        m_trendingBackend->fetch(selectedSources);
    }
}

void Dispatcher::fetchCustom()
{
    if (const auto sourcesModel = m_sourcesBackend->sourceModel()) {
        const auto selectedSources = sourcesModel->getSelectedSources();
        m_customBackend->fetch(selectedSources);
    }
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
