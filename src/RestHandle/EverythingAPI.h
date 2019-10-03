#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class EverythingAPI : public QObject {
    Q_OBJECT
public:
    explicit EverythingAPI(QObject* parent = nullptr);

private:
    RestClient m_restClient;
};
