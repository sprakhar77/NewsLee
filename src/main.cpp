#include <FelgoApplication>
//#include <FelgoLiveClient>

#include <QApplication>
#include <QQmlApplicationEngine>

#include <src/Application.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FelgoApplication felgo;

    // Use platform-specific fonts instead of Felgo's default font
    felgo.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;
    felgo.initialize(&engine);

    Application application;
    application.initialize(&engine);

    // Change "Main.qml" to "main.qml" if the application crashes.
    felgo.setMainQmlFileName(QStringLiteral("qml/main.qml"));

    // FelgoLiveClient client (&engine);
    engine.load(QUrl(felgo.mainQmlFileName()));
    return app.exec();
}
