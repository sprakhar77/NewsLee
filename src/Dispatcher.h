#include <src/RequestBackend.h>

class Dispatcher : public QObject {
    Q_OBJECT

    Q_PROPERTY(RequestBackend* requestBackend READ requestBackend CONSTANT)

public:
    explicit Dispatcher(QObject* parent = nullptr);

    RequestBackend* requestBackend() const;

private:
    RequestBackend* m_requestBackend{ nullptr };
};
