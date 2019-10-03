#include <QJsonObject>

class QUrl;
class QDateTime;

class Article {
public:
    Article() = default;
    explicit Article(QJsonObject json);

    bool isComplete();

    QString sourceId();
    QString sourceName();
    QString author();
    QString title();
    QString description();
    QUrl url();
    QUrl urlToImage();
    QDateTime publishedAt();
    QString content();

private:
    QJsonObject m_json;
};
