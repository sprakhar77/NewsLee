#include "Enums.h"
#include <QMetaEnum>

Enums::Enums()
{
}

namespace ApplicationEnums {
QString countryAsString(ApplicationEnums::Country country)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Country>();
    return QString(QLatin1String(metaEnum.valueToKey(static_cast<int>(country)))).replace("_", " ").toLower();
}

QString countryAsCountryCode(ApplicationEnums::Country country)
{
    return QString();
}

QString categoryTypeAsString(ApplicationEnums::Category category)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Category>();
    return QString(QLatin1String(metaEnum.valueToKey(static_cast<int>(category)))).replace("_", " ").toLower();
}

QString LanguageAsString(ApplicationEnums::Language language)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::Language>();
    return QString(QLatin1String(metaEnum.valueToKey(static_cast<int>(language)))).replace("_", " ").toLower();
}

QString LanguageAsLanguageCode(ApplicationEnums::Language language)
{
    return QString();
}

QString sortByAsString(ApplicationEnums::SortBy sortBy)
{
    const auto metaEnum = QMetaEnum::fromType<ApplicationEnums::SortBy>();
    return QString(QLatin1String(metaEnum.valueToKey(static_cast<int>(sortBy)))).replace("_", " ").toLower();
}
}
