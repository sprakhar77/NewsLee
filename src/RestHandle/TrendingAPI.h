#include <src/RestHandle/Response/Article.h>
#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString country() const;
    QString category() const;
    QVector<Article> trending() const;
    void fetch();

public slots:
    void setCountry(QString country);
    void setCategory(QString category);

signals:
    void countryChanged(QString country);
    void categoryChanged(QString category);
    void trendingNewsChanged();

private slots:
    void handleRestResponse(const QJsonObject& json);

private:
    RestClient m_restClient;
    QString m_country;
    QString m_category;
    QVector<Article> m_trending;
};
