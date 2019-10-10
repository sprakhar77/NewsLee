#include <Model/ArticleModel.h>
#include <RestHandle/Request/TrendingAPI.h>
#include <RestHandle/Response/Article.h>
#include <RestHandle/RestClient.h>

#include <QObject>

class TrendingBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(TrendingAPI* trendingAPI READ trendingAPI CONSTANT)
    Q_PROPERTY(ArticleModel* articleModel READ articleModel CONSTANT)

public:
    explicit TrendingBackend(QObject* parent = nullptr);

    TrendingAPI* trendingAPI() const;
    ArticleModel* articleModel() const;

    void fetch(const QVector<QString>&sources);

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    TrendingAPI* m_trendingAPI{ nullptr };
    RestClient m_restClient;
    ArticleModel* m_articleModel{ nullptr };
};
