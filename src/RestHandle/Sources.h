#include <src/RestHandle/Response/Source.h>
#include <src/RestHandle/RestClient/RestClient.h>

#include <QObject>

class Sources : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

public:
    explicit Sources(QObject* parent = nullptr);

    QString country() const;
    QString category() const;
    QString language() const;
    QVector<Source> sources() const;

public slots:
    void setCountry(QString country);
    void setCategory(QString category);
    void setLanguage(QString language);

signals:
    void countryChanged(QString country);
    void categoryChanged(QString category);
    void languageChanged(QString language);
    void sourcesChanged();

private slots:
    void handleRestResponse(const QJsonObject& json);

private:
    RestClient m_restClient;
    QString m_country;
    QString m_category;
    QString m_language;
    QVector<Source> m_sources;
};
