#include "Enums.h"
#include <QMetaEnum>

Enums::Enums()
{

}

namespace ApplicationEnums {
QString countryAsString(ApplicationEnums::Country country)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Country>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(country)));
}

QString countryAsCountryCode(ApplicationEnums::Country country)
{
    return QString();
}

QString categoryTypeAsString(ApplicationEnums::Category category)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Category>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(category)));
}

QString LanguageAsString(ApplicationEnums::Language language)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Language>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(language)));
}

QString LanguageAsLanguageCode(ApplicationEnums::Language language)
{
    return QString();
}

QString sortByAsString(ApplicationEnums::SortBy sortBy)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::SortBy>();
    return QLatin1String(metaEnum.valueToKey(static_cast<int>(sortBy)));
}
}

