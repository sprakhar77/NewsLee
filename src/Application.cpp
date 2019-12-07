#include "Application.h"

#include <src/Backend/CustomBackend.h>
#include <src/Backend/SourcesBackend.h>
#include <src/Backend/TrendingBackend.h>
#include <src/Dispatcher.h>
#include <src/Model/ArticleModel.h>
#include <src/Model/CheckableModel/CheckableModel.h>
#include <src/Model/SourceModel.h>
#include <src/RestHandle/Request/CustomAPI.h>
#include <src/RestHandle/Request/SourcesAPI.h>
#include <src/RestHandle/Request/TrendingAPI.h>
#include <src/Utils/Enums.h>

#include <QQmlContext>

Application::Application(QObject* parent)
    : QObject(parent)
{
}

void Application::registerMetadata()
{
    qmlRegisterUncreatableMetaObject(ApplicationEnums::staticMetaObject,
        "com.Application.Backend",
        1,
        0,
        "ApplicationEnums",
        QLatin1String("Error: This is only an enum"));
}

void Application::registerQMLTypes()
{
    // Backends
    qmlRegisterType<TrendingBackend>();
    qmlRegisterType<SourcesBackend>();
    qmlRegisterType<CustomBackend>();

    //Models
    qmlRegisterType<ArticleModel>();
    qmlRegisterType<SourceModel>();
    qmlRegisterType<CheckableModel>();

    // APIs
    qmlRegisterType<TrendingAPI>();
    qmlRegisterType<SourcesAPI>();
    qmlRegisterType<CustomAPI>();
}

void Application::initialize(QQmlApplicationEngine* engine)
{
    registerMetadata();
    registerQMLTypes();
    m_dispatcher = new Dispatcher();
    engine->rootContext()->setContextProperty("Dispatcher", m_dispatcher);
}
