#include "Dispatcher.h"

#include <Backend/CustomBackend.h>
#include <Backend/SourcesBackend.h>
#include <Backend/TrendingBackend.h>
#include <Utils/Enums.h>

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_trendingBackend{ new TrendingBackend(this) }
    , m_sourcesBackend{ new SourcesBackend(this) }
    , m_customBackend{ new CustomBackend(this) }
    , m_applicationPage{ ApplicationEnums::ApplicationPage::START }
    , m_currentPage{ QString() }
{
}

void Dispatcher::fetchSources()
{
    m_sourcesBackend->fetch();
}

void Dispatcher::fetchTrending()
{
    if (const auto sourcesModel = m_sourcesBackend->sourceModel())
    {
        const auto selectedSources = sourcesModel->getSelectedSources();
        m_trendingBackend->fetch(selectedSources);
    }
}

void Dispatcher::fetchCustom()
{
    if (const auto sourcesModel = m_sourcesBackend->sourceModel())
    {
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

void Dispatcher::setCurrentPage(const QString& currentPage)
{
    if (m_currentPage == currentPage) {
        return;
    }
    m_currentPage = currentPage;
    emit currentPageChanged();
}

QString Dispatcher::currentPage() const
{
    return m_currentPage;
}

ApplicationEnums::ApplicationPage Dispatcher::applicationPage() const
{
    return m_applicationPage;
}

void Dispatcher::setApplicationPage(ApplicationEnums::ApplicationPage applicationPage)
{
    if (m_applicationPage == applicationPage) {
        return;
    }
    m_applicationPage = applicationPage;
    emit applicationPageChanged();

    switch (m_applicationPage) {
    case ApplicationEnums::ApplicationPage::START: {
         setCurrentPage(QLatin1String("qrc:/Home/Home.qml"));
        break;
    }
    case ApplicationEnums::ApplicationPage::TRENDING: {
        setCurrentPage(QString(QLatin1String("qrc:/News/Trending.qml")));
        break;
    }
    case ApplicationEnums::ApplicationPage::SOURCES: {
        setCurrentPage(QString(QLatin1String("qrc:/News/Sources.qml")));
        break;
    }
    case ApplicationEnums::ApplicationPage::CUSTOM: {
        setCurrentPage(QString(QLatin1String("qrc:/News/Custom.qml")));
        break;
    }
    }
}
