#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QObject>
#include <QVector>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)
    Q_PROPERTY(CheckableModel* sortBy READ sortBy CONSTANT)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString searchkeyword() const;
    CheckableModel* sortBy() const;

    QUrl prepareRequest();


public slots:
    void setSearchkeyword(QString searchkeyword);

signals:
    void searchkeywordChanged();

private:
    QString m_searchkeyword;
    CheckableModel* m_sortBy{ nullptr };
};
