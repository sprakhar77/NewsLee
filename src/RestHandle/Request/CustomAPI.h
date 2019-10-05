#pragma once

#include <QDateTime>
#include <QObject>
#include <QVector>

class CustomAPI : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString searchkeyword READ searchkeyword WRITE setSearchkeyword NOTIFY searchkeywordChanged)
    Q_PROPERTY(QDateTime from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QDateTime to READ to WRITE setTo NOTIFY toChanged)

    // Add Source, PageSize, SortBy and Language models to select from UI

public:
    explicit CustomAPI(QObject* parent = nullptr);

    QString searchkeyword() const;
    QDateTime from() const;
    QDateTime to() const;

    QUrl prepareRequest();

    Q_INVOKABLE void addSource(const QString& source);

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
    QVector<QString> m_sourcesToFetchFrom;
    QDateTime m_from;
    QDateTime m_to;
};
