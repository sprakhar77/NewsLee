#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QDateTime>
#include <QObject>
#include <QVector>

class CustomAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchKeyword READ searchKeyword WRITE setSearchKeyword NOTIFY searchKeywordChanged)
    Q_PROPERTY(QDateTime from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QDateTime to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(CheckableModel* sortBy READ sortBy CONSTANT)

public:
    explicit CustomAPI(QObject* parent = nullptr);

    QString searchKeyword() const;
    QDateTime from() const;
    QDateTime to() const;
    CheckableModel* sortBy() const;

    QUrl prepareRequest();

public slots:
    void setSearchKeyword(QString searchKeyword);
    void setFrom(QDateTime from);
    void setTo(QDateTime to);

signals:
    void searchKeywordChanged();
    void fromChanged();
    void toChanged();

private:
    QString m_searchKeyword;
    QDateTime m_from;
    QDateTime m_to;
    CheckableModel* m_sortBy{ nullptr };
};
