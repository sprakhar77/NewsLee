#pragma once

#include <QObject>
#include <QVector>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString country() const;
    QString category() const;
    QString searchkeyword() const;

    QUrl prepareRequest();

    Q_INVOKABLE void addSource(const QString& source);

public slots:
    void setCountry(QString country);
    void setCategory(QString category);

    void setSearchkeyword(QString searchkeyword);

signals:
    void countryChanged();
    void categoryChanged();
    void searchkeywordChanged();

private:
    QString m_country;
    QString m_category;
    QString m_searchkeyword;
    QVector<QString> m_sourcesToFetchFrom;
};
