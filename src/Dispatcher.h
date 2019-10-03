#include <QObject>

class RestClient;

class Dispatcher : public QObject {
    Q_OBJECT

    Q_PROPERTY(RestClient* restClient READ restClient CONSTANT)

public:
    explicit Dispatcher(QObject* parent = nullptr);

    RestClient* restClient() const;

private:
    RestClient* m_restClient{ nullptr };
};
