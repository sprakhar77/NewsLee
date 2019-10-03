#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class CustomAPI : public QObject {
    Q_OBJECT
public:
    explicit CustomAPI(QObject* parent = nullptr);

private:
    RestClient m_restClient;
};
