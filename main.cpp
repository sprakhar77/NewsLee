#include <FelgoApplication>
//#include <FelgoLiveClient>

#include <QApplication>
#include <QQmlApplicationEngine>

#include <Application.h>

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

    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

//    FelgoLiveClient client (&engine);
    engine.load(QUrl(felgo.mainQmlFileName()));
    return app.exec();
}
