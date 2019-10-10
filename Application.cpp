#include "Application.h"

#include <Backend/CustomBackend.h>
#include <Backend/SourcesBackend.h>
#include <Backend/TrendingBackend.h>
#include <Dispatcher.h>
#include <Model/ArticleModel.h>
#include <Model/CheckableModel/CheckableModel.h>
#include <Model/SourceModel.h>
#include <RestHandle/Request/CustomAPI.h>
#include <RestHandle/Request/SourcesAPI.h>
#include <RestHandle/Request/TrendingAPI.h>
#include <Utils/Enums.h>

#include <QQmlContext>

Application::Application(QObject* parent)
    : QObject(parent)
{
}

void Application::registerMetadata()
{
    // Register Metadata
    qmlRegisterUncreatableMetaObject(ApplicationEnums::staticMetaObject,
                                     "com.Application.Backend",
                                     1,
                                     0,
                                     "ApplicationEnums",
                                     QLatin1String("Error: This is only an enum"));
    qRegisterMetaType<ApplicationEnums::ApplicationPage>();
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

void Application::initialize(QQmlApplicationEngine *engine)
{
    registerMetadata();
    registerQMLTypes();
    m_dispatcher = new Dispatcher();
    engine->rootContext()->setContextProperty("Dispatcher", m_dispatcher);
}

