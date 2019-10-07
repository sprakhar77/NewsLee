#pragma once

#include <src/Model/CheckableModel/CheckableModelFactory.h>

#include <QObject>
#include <QVector>

class TrendingAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)
    Q_PROPERTY(CheckableModel* country READ country CONSTANT)
    Q_PROPERTY(CheckableModel* category READ category CONSTANT)
    Q_PROPERTY(CheckableModel* sources READ sources CONSTANT)
    Q_PROPERTY(CheckableModel* pageSize READ pageSize CONSTANT)
    Q_PROPERTY(CheckableModel* sortBy READ sortBy CONSTANT)

public:
    explicit TrendingAPI(QObject* parent = nullptr);

    QString searchkeyword() const;

    QUrl prepareRequest();

    Q_INVOKABLE void addSource(const QString& source);

    CheckableModel* country() const;
    CheckableModel* category() const;
    CheckableModel* sources() const;
    CheckableModel* pageSize() const;
    CheckableModel* sortBy() const;

public slots:
    void setSearchkeyword(QString searchkeyword);

signals:
    void searchkeywordChanged();

private:
    QString m_searchkeyword;
    QVector<QString> m_sourcesToFetchFrom;
    CheckableModel* m_country{ nullptr };
    CheckableModel* m_category{ nullptr };
    CheckableModel* m_sources{ nullptr };
    CheckableModel* m_pageSize{ nullptr };
    CheckableModel* m_sortBy{ nullptr };
};
