#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class RestClient : public QObject {
    Q_OBJECT

public:
    explicit RestClient(QObject* parent = nullptr);

    Q_INVOKABLE void sendRequest();

private slots:
    void onDataReadReady();
    void onRequestCompleted();

private:
    QNetworkAccessManager* m_networkAccessManager;
    QNetworkReply* m_reply;
    QByteArray* m_dataBuffer;
};
