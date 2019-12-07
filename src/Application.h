#include <QQmlApplicationEngine>

class Dispatcher;

class Application : QObject {
    Q_OBJECT

public:
    explicit Application(QObject* parent = nullptr);

    void initialize(QQmlApplicationEngine *engine);

private:
    void registerMetadata();
    void registerQMLTypes();

private:
    Dispatcher* m_dispatcher;
};
