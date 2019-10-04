#include "Application.h"

#include <src/Backend/CustomBackend.h>
#include <src/Backend/SourcesBackend.h>
#include <src/Backend/TrendingBackend.h>
#include <src/Dispatcher.h>
#include <src/Model/ArticleModel.h>
#include <src/Model/SourceModel.h>
#include <src/RestHandle/Request/CustomAPI.h>
#include <src/RestHandle/Request/SourcesAPI.h>
#include <src/RestHandle/Request/TrendingAPI.h>

#include <QQmlContext>

Application::Application(QObject* parent)
    : QObject(parent)
{
}

void Application::registerQMLTypes()
{
    // Backends
    qmlRegisterType<TrendingBackend>();
    qmlRegisterType<SourcesBackend>();
    qmlRegisterType<CustomBackend>();

    //Models
    qmlRegisterType<ArticleModel>();
    //    qmlRegisterType<SourceModel>();

    // APIs
    qmlRegisterType<TrendingAPI>();
    qmlRegisterType<SourcesAPI>();
    qmlRegisterType<CustomAPI>();
}

bool Application::initialize()
{
    m_dispatcher = new Dispatcher();
    registerQMLTypes();

    m_engine.rootContext()->setContextProperty("Dispatcher", m_dispatcher);
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (m_engine.rootObjects().empty()) {
        return false;
    }
    return true;
}
