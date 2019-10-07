#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QDateTime>
#include <QObject>
#include <QVector>

class CustomAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)
    Q_PROPERTY(QDateTime from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QDateTime to READ to WRITE setTo NOTIFY toChanged)

    Q_PROPERTY(CheckableModel* sources READ sources CONSTANT)
    Q_PROPERTY(CheckableModel* pageSize READ pageSize CONSTANT)
    Q_PROPERTY(CheckableModel* sortBy READ sortBy CONSTANT)
    Q_PROPERTY(CheckableModel* language READ language CONSTANT)

public:
    explicit CustomAPI(QObject* parent = nullptr);

    QString searchkeyword() const;
    QDateTime from() const;
    QDateTime to() const;

    QUrl prepareRequest();

    CheckableModel* sources() const;
    CheckableModel* pageSize() const;
    CheckableModel* sortBy() const;
    CheckableModel* language() const;

public slots:
    void setSearchkeyword(QString searchkeyword);
    void setFrom(QDateTime from);
    void setTo(QDateTime to);

signals:
    void searchkeywordChanged();
    void fromChanged();
    void toChanged();

private:
    QString m_searchkeyword;
    QDateTime m_from;
    QDateTime m_to;
    CheckableModel* m_sources{ nullptr };
    CheckableModel* m_pageSize{ nullptr };
    CheckableModel* m_sortBy{ nullptr };
    CheckableModel* m_language{ nullptr };
};
