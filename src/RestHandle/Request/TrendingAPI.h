#pragma once

#include <QObject>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString country() const;
    QString category() const;
    QUrl prepareRequest();

public slots:
    void setCountry(QString country);
    void setCategory(QString category);

signals:
    void countryChanged(QString country);
    void categoryChanged(QString category);

private:
    QString m_country;
    QString m_category;
};
