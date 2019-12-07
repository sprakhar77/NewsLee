#include <src/Model/SourceModel.h>
#include <src/RestHandle/Request/SourcesAPI.h>
#include <src/RestHandle/Response/Source.h>
#include <src/RestHandle/RestClient.h>

#include <QObject>

class SourcesBackend : public QObject {
    Q_OBJECT

    Q_PROPERTY(SourcesAPI* sourcesAPI READ sourcesAPI CONSTANT)
    Q_PROPERTY(SourceModel* sourceModel READ sourceModel CONSTANT)

public:
    explicit SourcesBackend(QObject* parent = nullptr);

    SourcesAPI* sourcesAPI() const;
    SourceModel* sourceModel() const;

    Q_INVOKABLE void updateSources();

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    SourcesAPI* m_sourcesAPI{ nullptr };
    RestClient m_restClient;
    SourceModel* m_sourceModel{ nullptr };
};
