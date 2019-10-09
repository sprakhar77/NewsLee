#include "Enums.h"
#include <QMetaEnum>

Enums::Enums()
{

}

QString ApplicationEnums::countryAsString(ApplicationEnums::Country country)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Country>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(country)));
}

QString ApplicationEnums::countryAsCountryCode(ApplicationEnums::Country country)
{
    return QString();
}

QString categoryTypeAsString(ApplicationEnums::Category category)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Category>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(category)));
}

QString ApplicationEnums::LanguageAsString(ApplicationEnums::Language language)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Language>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(language)));
}

QString ApplicationEnums::LanguageAsLanguageCode(ApplicationEnums::Language language)
{
    return QString();
}

QString ApplicationEnums::sortByAsString(ApplicationEnums::SortBy sortBy)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::SortBy>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(sortBy)));
}

QVector<QString> ApplicationEnums::getAvailablePageSizes()
{
    return QVector<QString> {"20", "40", "60", "80", "100"};
}
