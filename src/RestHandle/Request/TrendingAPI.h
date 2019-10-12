#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QObject>
#include <QVector>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchKeyword READ searchKeyword WRITE setSearchKeyword NOTIFY searchKeywordChanged)
    Q_PROPERTY(CheckableModel* sortBy READ sortBy CONSTANT)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString searchKeyword() const;
    CheckableModel* sortBy() const;

    QUrl prepareRequest();

public slots:
    void setSearchKeyword(QString searchKeyword);

signals:
    void searchKeywordChanged();

private:
    QString m_searchKeyword;
    CheckableModel* m_sortBy{ nullptr };
};
