#include <src/RestHandle/Response/Article.h>
#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class Trending : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)

public:
    explicit Trending(QObject* parent = nullptr);

    QString country() const;
    QString category() const;

public slots:
    void setCountry(QString country);
    void setCategory(QString category);

signals:
    void countryChanged(QString country);
    void categoryChanged(QString category);
    void updateTrendingNews(const QVector<Article>& articles);

private slots:
    void handleRestResponse(const QJsonObject& json);

private:
    RestClient m_restClient;
    QString m_country;
    QString m_category;
};
