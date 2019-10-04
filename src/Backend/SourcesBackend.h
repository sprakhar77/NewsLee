#include <src/RestHandle/Request/SourcesAPI.h>
#include <src/RestHandle/Response/Source.h>
#include <src/RestHandle/RestClient.h>

#include <QObject>

class SourcesBackend : public QObject {
    Q_OBJECT

    Q_PROPERTY(SourcesAPI* sourcesAPI READ sourcesAPI CONSTANT)

public:
    explicit SourcesBackend(QObject* parent = nullptr);

    SourcesAPI* sourcesAPI() const;
    QVector<Source> sources() const;
    Q_INVOKABLE void fetch();

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    SourcesAPI* m_sourcesAPI;
    RestClient m_restClient;
    QVector<Source> m_sources;
};
