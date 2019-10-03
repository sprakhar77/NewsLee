#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class Everything : public QObject {
    Q_OBJECT
public:
    explicit Everything(QObject* parent = nullptr);

private:
    RestClient m_restClient;
};
