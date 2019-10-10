#include "ArticleModel.h"

#include <QDateTime>
#include <QUrl>

ArticleModel::ArticleModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

ArticleModel::~ArticleModel()
{
}

int ArticleModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_articles.count();
}

QVariant ArticleModel::data(const QModelIndex& index, int role) const
{
    Q_ASSERT(index.isValid());

    if (const auto article = m_articles.at(index.row())) {
        switch (static_cast<ModelRole>(role)) {
        case ModelRole::SourceId: {
            return article->sourceId();
        }
        case ModelRole::SourceName: {
            return article->sourceName();
        }
        case ModelRole::Author: {
            return article->author();
        }
        case ModelRole::Description: {
            return article->description();
        }
        case ModelRole::Url: {
            return article->url();
        }
        case ModelRole::UrlToImage: {
            return article->urlToImage();
        }
        case ModelRole::PublishedAt: {
            return article->publishedAt();
        }
        case ModelRole::Content: {
            return article->content();
        }
        }
    }
    return QVariant();
}

QHash<int, QByteArray> ArticleModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[static_cast<int>(ModelRole::SourceId)] = "sourceId";
    roles[static_cast<int>(ModelRole::SourceName)] = "sourceName";
    roles[static_cast<int>(ModelRole::Author)] = "author";
    roles[static_cast<int>(ModelRole::Description)] = "description";
    roles[static_cast<int>(ModelRole::Url)] = "url";
    roles[static_cast<int>(ModelRole::UrlToImage)] = "urlToImage";
    roles[static_cast<int>(ModelRole::PublishedAt)] = "publishedAt";
    roles[static_cast<int>(ModelRole::Content)] = "content";

    return roles;
}

void ArticleModel::clearArticles()
{
    if (m_articles.count()) {
        beginRemoveRows({}, 0, m_articles.count() - 1);
        m_articles.clear();
        endRemoveRows();
    }
}

void ArticleModel::addArticle(Article* article)
{
    Q_ASSERT(article);
    beginInsertRows({}, m_articles.count(), m_articles.count());
    m_articles.append(article);
    endInsertRows();
}
