#include "CheckableModel.h"

CheckableModel::CheckableModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int CheckableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant CheckableModel::data(const QModelIndex& index, int role) const
{
    Q_ASSERT(index.isValid());

    if (const auto item = m_items.at(index.row())) {
        switch (static_cast<ModelRole>(role)) {
        case ModelRole::Name: {
            return item->name();
        }
        case ModelRole::Checked: {
            return item->checked();
        }
        case ModelRole::Enabled: {
            return item->enabled();
        }
        }
    }
    return QVariant();
}

QHash<int, QByteArray> CheckableModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[static_cast<int>(ModelRole::Name)] = "name";
    roles[static_cast<int>(ModelRole::Checked)] = "checked";
    roles[static_cast<int>(ModelRole::Enabled)] = "enabled";

    return roles;
}

bool CheckableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    auto item = m_items[index.row()];

    switch (static_cast<ModelRole>(role)) {
    case ModelRole::Name: {
        if (!item->setName(value.toString())) {
            return false;
        }
        break;
    }
    case ModelRole::Checked: {
        bool checked = value.toBool();
        if (!item->setChecked(checked)) {
            return false;
        }
        break;
    }
    case ModelRole::Enabled: {
        bool enabled = value.toBool();
        if (!item->setEnabled(enabled)) {
            return false;
        }
        break;
    }
    }

    emit dataChanged(index, index);
    return true;
}

void CheckableModel::appendItem(CheckableItem* item)
{
    beginInsertRows({}, m_items.count(), m_items.count());
    m_items.append(item);
    endInsertRows();
}

QVector<QString> CheckableModel::extractAllCheckedItems()
{
    QVector<QString> checkedItems;
    for (const auto item : m_items) {
        if (item && item->checked()) {
            checkedItems.push_back(item->name());
        }
    }
    return checkedItems;
}
