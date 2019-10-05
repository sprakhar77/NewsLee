#include <QObject>

namespace ApplicationEnums {
Q_NAMESPACE
Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

enum class ApplicationPage {
    START = 0,
    TRENDING,
    CUSTOM,
    SOURCES
};
Q_ENUM_NS(ApplicationPage)
}

class Enums {
public:
    Enums();
};
