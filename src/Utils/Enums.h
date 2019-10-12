#include <QObject>
#include <QVector>

namespace ApplicationEnums {
Q_NAMESPACE
Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

enum class Country {
    UNITED_ARAB_EMIRATES = 0,
    ARGENTINA,
    AUSTRIA,
    AUSTRALIA,
    BELGIUM,
    BULGARIA,
    BRAZIL,
    CANADA,
    SWITZERLAND,
    CHINA,
    COLOMBIA,
    CUBA,
    CZECHIA,
    GERMANY,
    EGYPT,
    FRANCE,
    UNITED_KINGDOM,
    GREECE,
    HONG_KONG,
    HUNGARY,
    INDONESIA,
    IRELAND,
    ISRAEL,
    INDIA,
    ITALY,
    JAPAN,
    KOREA,
    LITHUANIA,
    LATIVA,
    MOROCCO,
    MEXICO,
    MALAYSIA,
    NIGERIA,
    NETHERLANDS,
    NORWAY,
    NEW_ZELAND,
    PHILIPPINES,
    POLAND,
    PORTUGAL,
    ROMANIA,
    SERBIA,
    RUSSIA,
    SAUDI_ARABIA,
    SWEDEN,
    SINGAPORE,
    SLOVENIA,
    SLOVAKIA,
    THIALAND,
    TURKEY,
    TAIWAN,
    UKRAINE,
    UNITED_STATES_OF_AMERICA,
    VENEZUELA,
    SOUTH_AFRICA

};
Q_ENUM_NS(Country)
QString countryAsString(ApplicationEnums::Country country);
QString countryAsCountryCode(ApplicationEnums::Country country);

enum class Category {
    BUSINESS,
    ENTERTAINMENT,
    GENERAL,
    HEALTH,
    SCIENCE,
    SPORTS,
    TECHNOLOGY
};
Q_ENUM_NS(Category)
QString categoryTypeAsString(ApplicationEnums::Category category);

enum class Language {
    ARABIC,
    GERMAN,
    ENGLISH,
    SPANISH,
    FRENCH,
    HEBREW,
    DUTCH,
    NORWEGIAN,
    PORTUGESE,
    RUSSIAN,
    NORTHERN_SAMI,
    ZULU

};
Q_ENUM_NS(Language)
QString LanguageAsString(ApplicationEnums::Language language);
QString LanguageAsLanguageCode(ApplicationEnums::Language language);

enum class SortBy {
    RELEVANCY,
    POPULARITY,
    PUBLISHED_AT,

};
Q_ENUM_NS(SortBy)
QString sortByAsString(ApplicationEnums::SortBy sortBy);
}

class Enums {
public:
    Enums();
};
