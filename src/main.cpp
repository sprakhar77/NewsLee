#include "Application.h"

#include <QGuiApplication>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Application application;
    if (!application.initialize()) {
        return -1;
    }
    return app.exec();
}
