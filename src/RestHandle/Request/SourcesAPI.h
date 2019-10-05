#pragma once

#include <QObject>

class SourcesAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

public:
    explicit SourcesAPI(QObject* parent = nullptr);

    QString country() const;
    QString category() const;
    QString language() const;
    QUrl prepareRequest();

public slots:
    void setCountry(QString country);
    void setCategory(QString category);
    void setLanguage(QString language);

signals:
    void countryChanged();
    void categoryChanged();
    void languageChanged();

private:
    QString m_country;
    QString m_category;
    QString m_language;
};
