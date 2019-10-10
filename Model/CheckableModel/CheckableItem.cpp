#include "CheckableItem.h"

CheckableItem::CheckableItem(const QString& name, bool checked, bool enabled)
    : m_name(name)
    , m_checked(checked)
    , m_enabled(enabled)
{
}

QString CheckableItem::name() const
{
    return m_name;
}

bool CheckableItem::checked() const
{
    return m_checked;
}

bool CheckableItem::enabled() const
{
    return m_enabled;
}

bool CheckableItem::setName(const QString& name)
{
    if (m_name != name) {
        m_name = name;
        return true;
    }
    return false;
}

bool CheckableItem::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        return true;
    }
    return false;
}

bool CheckableItem::setEnabled(bool enabled)
{
    if (m_enabled != enabled) {
        m_enabled = enabled;
        return true;
    }
    return false;
}
