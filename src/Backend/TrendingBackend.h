#include <src/Model/ArticleModel.h>
#include <src/RestHandle/Request/TrendingAPI.h>
#include <src/RestHandle/Response/Article.h>
#include <src/RestHandle/RestClient.h>

#include <QObject>

class TrendingBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(TrendingAPI* trendingAPI READ trendingAPI CONSTANT)
    Q_PROPERTY(ArticleModel* articleModel READ articleModel CONSTANT)

public:
    explicit TrendingBackend(QObject* parent = nullptr);

    TrendingAPI* trendingAPI() const;
    ArticleModel* articleModel() const;

    void fetch(const QVector<QString>& sources);

signals:
    void modelUpdateStarted();
    void modelUpdateFinished();

private slots:
    void
    onResponseRecieved(const QJsonObject& json);

private:
    TrendingAPI* m_trendingAPI{ nullptr };
    RestClient m_restClient;
    ArticleModel* m_articleModel{ nullptr };
};
