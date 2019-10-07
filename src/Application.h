#include <QQmlApplicationEngine>

class Dispatcher;

class Application : QObject {

    Q_OBJECT
public:
    explicit Application(QObject* parent = nullptr);
    void registerMetadata();
    void registerQMLTypes();
    bool initialize();

private:
    QQmlApplicationEngine m_engine;
    Dispatcher* m_dispatcher;
};
