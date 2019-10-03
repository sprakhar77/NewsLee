#include <src/RestHandle/CustomAPI.h>
#include <src/RestHandle/SourcesAPI.h>
#include <src/RestHandle/TrendingAPI.h>

class RequestBackend : public QObject {
    Q_OBJECT

    Q_PROPERTY(CustomAPI* customAPI READ customAPI CONSTANT)
    Q_PROPERTY(SourcesAPI* sourcesAPI READ sourcesAPI CONSTANT)
    Q_PROPERTY(TrendingAPI* trendingAPI READ trendingAPI CONSTANT)

public:
    explicit RequestBackend(QObject* parent = nullptr);

    CustomAPI* customAPI() const;
    SourcesAPI* sourcesAPI() const;
    TrendingAPI* trendingAPI() const;

    Q_INVOKABLE void fetchSources();
    Q_INVOKABLE void fetchTrending();

public slots:
    void onSourcesChanged();
    void onTrendingNewsChanged();

private:
    CustomAPI* m_customAPI{ nullptr };
    SourcesAPI* m_sourcesAPI{ nullptr };
    TrendingAPI* m_trendingAPI{ nullptr };
};
