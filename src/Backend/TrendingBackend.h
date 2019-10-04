#include <src/RestHandle/Request/TrendingAPI.h>
#include <src/RestHandle/Response/Article.h>
#include <src/RestHandle/RestClient.h>

#include <QObject>

class TrendingBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(TrendingAPI* trendingAPI READ trendingAPI CONSTANT)

public:
    explicit TrendingBackend(QObject* parent = nullptr);

    TrendingAPI* trendingAPI() const;
    QVector<Article> trendingArticles() const;
    Q_INVOKABLE void fetch();

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    TrendingAPI* m_trendingAPI;
    RestClient m_restClient;
    QVector<Article> m_trendingArticles;
};
