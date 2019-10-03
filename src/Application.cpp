#include "Application.h"

#include <src/Dispatcher.h>

#include <QQmlContext>

Application::Application(QObject* parent)
    : QObject(parent)
{
}

bool Application::initialize()
{
    m_dispatcher = new Dispatcher();

    m_engine.rootContext()->setContextProperty("Dispatcher", m_dispatcher);
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (m_engine.rootObjects().empty()) {
        return false;
    }
    return true;
}
