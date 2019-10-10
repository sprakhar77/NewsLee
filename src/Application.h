#include <QQmlApplicationEngine>

class Dispatcher;

class Application : QObject {

    Q_OBJECT
public:
    explicit Application(QObject* parent = nullptr);
    void registerMetadata();
    void registerQMLTypes();
    void initialize(QQmlApplicationEngine *engine);

private:
    Dispatcher* m_dispatcher;
};
