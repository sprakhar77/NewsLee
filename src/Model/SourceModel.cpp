#include "SourceModel.h"

#include <QUrl>

SourceModel::SourceModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

SourceModel::~SourceModel()
{
}
int SourceModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_sources.count();
}

QVariant SourceModel::data(const QModelIndex& index, int role) const
{
    Q_ASSERT(index.isValid());

    if (const auto source = m_sources.at(index.row())) {
        switch (static_cast<ModelRole>(role)) {
        case ModelRole::Id: {
            return source->id();
        }
        case ModelRole::Name: {
            return source->name();
        }
        case ModelRole::Description: {
            return source->description();
        }
        case ModelRole::Url: {
            return source->url();
        }
        case ModelRole::Category: {
            return source->category();
        }
        case ModelRole::Language: {
            return source->language();
        }
        case ModelRole::Country: {
            return source->country();
        }
        }
    }
    return QVariant();
}

QHash<int, QByteArray> SourceModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[static_cast<int>(ModelRole::Id)] = "id";
    roles[static_cast<int>(ModelRole::Name)] = "name";
    roles[static_cast<int>(ModelRole::Description)] = "description";
    roles[static_cast<int>(ModelRole::Url)] = "url";
    roles[static_cast<int>(ModelRole::Category)] = "category";
    roles[static_cast<int>(ModelRole::Language)] = "language";
    roles[static_cast<int>(ModelRole::Country)] = "country";

    return roles;
}

void SourceModel::clearSources()
{
    if (m_sources.count()) {
        beginRemoveRows({}, 0, m_sources.count() - 1);
        m_sources.clear();
        endRemoveRows();
    }
}

void SourceModel::addSource(Source* source)
{
    Q_ASSERT(source);
    beginInsertRows({}, m_sources.count(), m_sources.count());
    m_sources.append(source);
    endInsertRows();
}

QVector<QString> SourceModel::getSelectedSources()
{
    QVector<QString>selectedSources;
    for(const auto source: m_sources)
    {
        selectedSources.push_back(source->id());
    }
    return selectedSources;
}