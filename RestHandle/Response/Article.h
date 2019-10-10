#pragma once

#include <QJsonObject>

class QUrl;
class QDateTime;

class Article {
public:
    Article() = default;
    explicit Article(const QJsonObject& json);

    bool isComplete() const;

    QString sourceId() const;
    QString sourceName() const;
    QString author() const;
    QString title() const;
    QString description() const;
    QUrl url() const;
    QUrl urlToImage() const;
    QDateTime publishedAt() const;
    QString content() const;

private:
    QJsonObject m_json;
};
