#pragma once

#include <src/RestHandle/Response/Article.h>

#include <QAbstractListModel>
class ArticleModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum class ModelRole {
        SourceId = Qt::UserRole + 1,
        SourceName,
        Author,
        Description,
        Url,
        UrlToImage,
        PublishedAt,
        Content
    };
    Q_ENUM(ModelRole)

    ArticleModel(QObject* parent = nullptr);
    ~ArticleModel() override;

    // Methods interfaced from QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void clearArticles();
    void addArticle(Article* article);

private:
    QVector<Article*> m_articles;
};
