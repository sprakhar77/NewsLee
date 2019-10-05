#pragma once

#include <QObject>
#include <QVector>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)

    // Add Country, Category, Sources, PageSize and SortBy models to select from UI

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString searchkeyword() const;

    QUrl prepareRequest();

    Q_INVOKABLE void addSource(const QString& source);

public slots:
    void setSearchkeyword(QString searchkeyword);

signals:
    void searchkeywordChanged();

private:
    QString m_searchkeyword;
    QVector<QString> m_sourcesToFetchFrom;
};
