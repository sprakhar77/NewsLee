#pragma once

#include <QVariant>

class CheckableItem {
public:
    CheckableItem(const QString& name = QString(), bool checked = false, bool enabled = true);

    QString name() const;
    bool checked() const;
    bool enabled() const;

    bool setName(const QString& name);
    bool setChecked(bool checked);
    bool setEnabled(bool enabled);

private:
    QString m_name;
    bool m_checked;
    bool m_enabled;
};
