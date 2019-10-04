#include <QObject>

class CustomBackend;
class SourcesBackend;
class TrendingBackend;

class Dispatcher : public QObject {
    Q_OBJECT

    Q_PROPERTY(TrendingBackend* trendingBackend READ trendingBackend CONSTANT)
    Q_PROPERTY(SourcesBackend* sourcesBackend READ sourcesBackend CONSTANT)
    Q_PROPERTY(CustomBackend* customBackend READ customBackend CONSTANT)

public:
    explicit Dispatcher(QObject* parent = nullptr);

    TrendingBackend* trendingBackend() const;
    SourcesBackend* sourcesBackend() const;
    CustomBackend* customBackend() const;

private:
    TrendingBackend* m_trendingBackend{ nullptr };
    SourcesBackend* m_sourcesBackend{ nullptr };
    CustomBackend* m_customBackend{ nullptr };
};
