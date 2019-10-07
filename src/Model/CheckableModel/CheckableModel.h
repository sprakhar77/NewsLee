#pragma once

#include <src/Model/CheckableModel/CheckableItem.h>

#include <QAbstractListModel>

class CheckableModel : public QAbstractListModel {

    Q_OBJECT

public:
    enum class ModelRole {
        Name = Qt::UserRole + 1,
        Checked,
        Enabled
    };
    Q_ENUM(ModelRole)

    CheckableModel(QObject* parent = nullptr);

    // Methods interfaced from QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    QVector<QString> extractAllCheckedItems();

private:
    QVector<CheckableItem*> m_items;
};
