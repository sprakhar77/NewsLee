#include "Application.h"

#include <src/APIHandler/RestClient.h>
#include <src/Dispatcher.h>

#include <QQmlContext>

Application::Application(QObject* parent)
    : QObject(parent)
{
}

void Application::registerQMLTypes()
{
    qmlRegisterType<RestClient>();
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
