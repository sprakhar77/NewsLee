#include <QJsonObject>

class QUrl;

class Source {
public:
    Source() = default;
    explicit Source(const QJsonObject& json);

    bool isComplete() const;

    QString id() const;
    QString name() const;
    QString description() const;
    QUrl url() const;
    QString category() const;
    QString language() const;
    QString country() const;

private:
    QJsonObject m_json;
};
