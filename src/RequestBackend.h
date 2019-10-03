#include <src/RestHandle/EverythingAPI.h>
#include <src/RestHandle/SourcesAPI.h>
#include <src/RestHandle/TrendingAPI.h>

class RequestBackend : public QObject {
    Q_OBJECT

    Q_PROPERTY(EverythingAPI* everythingAPI READ everythingAPI CONSTANT)
    Q_PROPERTY(SourcesAPI* sourcesAPI READ sourcesAPI CONSTANT)
    Q_PROPERTY(TrendingAPI* trendingAPI READ trendingAPI CONSTANT)

public:
    explicit RequestBackend(QObject* parent = nullptr);

    EverythingAPI* everythingAPI() const;
    SourcesAPI* sourcesAPI() const;
    TrendingAPI* trendingAPI() const;

    Q_INVOKABLE void fetchSources();
    Q_INVOKABLE void fetchTrending();

public slots:
    void onSourcesChanged();
    void onTrendingNewsChanged();

private:
    EverythingAPI* m_everythingAPI{ nullptr };
    SourcesAPI* m_sourcesAPI{ nullptr };
    TrendingAPI* m_trendingAPI{ nullptr };
};
