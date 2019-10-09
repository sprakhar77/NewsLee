#include <src/Model/ArticleModel.h>
#include <src/RestHandle/Request/CustomAPI.h>
#include <src/RestHandle/Response/Article.h>
#include <src/RestHandle/RestClient.h>

#include <QObject>

class CustomBackend : public QObject {
    Q_OBJECT
    Q_PROPERTY(CustomAPI* customAPI READ customAPI CONSTANT)
    Q_PROPERTY(ArticleModel* articleModel READ articleModel CONSTANT)

public:
    explicit CustomBackend(QObject* parent = nullptr);

    CustomAPI* customAPI() const;
    ArticleModel* articleModel() const;

    void fetch(const QVector<QString>&sources);

private slots:
    void onResponseRecieved(const QJsonObject& json);

private:
    CustomAPI* m_customAPI{ nullptr };
    RestClient m_restClient;
    ArticleModel* m_articleModel{ nullptr };
};
