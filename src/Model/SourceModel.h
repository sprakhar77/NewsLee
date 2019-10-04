#pragma once

#include <src/RestHandle/Response/Source.h>

#include <QAbstractListModel>
class SourceModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum class ModelRole {
        Id = Qt::UserRole + 1,
        Name,
        Description,
        Url,
        Category,
        Language,
        Country
    };
    Q_ENUM(ModelRole)

    SourceModel(QObject* parent = nullptr);
    ~SourceModel() override;

    // Methods interfaced from QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void clearSources();
    void addSource(Source* source);

private:
    QVector<Source*> m_sources;
};
