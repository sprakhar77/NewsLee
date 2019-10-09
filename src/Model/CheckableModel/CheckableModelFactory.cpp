#include "CheckableModelFactory.h"
#include <src/Utils/Enums.h>

CheckableModel* CheckableModelFactory::create(CheckableModelFactory::ModelType type)
{
    CheckableModel* checkableModel = new CheckableModel();
    switch (type) {
    case ModelType::Country: {
        fillCountries(checkableModel);
        return checkableModel;
    }
    case ModelType::Category: {
        fillCategories(checkableModel);
        return checkableModel;
    }
    case ModelType::Language: {
        fillLanguages(checkableModel);
        return checkableModel;
    }
    case ModelType::SortBy: {
        fillSortBy(checkableModel);
        return checkableModel;
    }
    }
    return checkableModel;
}

void CheckableModelFactory::fillCountries(CheckableModel* checkableModel)
{
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::ARGENTINA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::AUSTRALIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::AUSTRIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::BELGIUM)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::BRAZIL)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::BULGARIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::CANADA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::CHINA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::COLOMBIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::CUBA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::CZECHIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::GERMANY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::EGYPT)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::FRANCE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::UNITED_KINGDOM)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::GREECE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::HONG_KONG)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::HUNGARY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::INDONESIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::IRELAND)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::ISRAEL)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::INDIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::ITALY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::JAPAN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::KOREA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::LITHUANIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::LATIVA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::MOROCCO)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::MEXICO)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::MALAYSIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::NIGERIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::NETHERLANDS)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::NORWAY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::NEW_ZELAND)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::PHILIPPINES)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::POLAND)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::PORTUGAL)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::ROMANIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SERBIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::RUSSIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SAUDI_ARABIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SWEDEN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SINGAPORE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SLOVENIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SLOVAKIA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::THIALAND)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::TURKEY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::TAIWAN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::UKRAINE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::UNITED_STATES_OF_AMERICA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::VENEZUELA)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::countryAsString(ApplicationEnums::Country::SOUTH_AFRICA)));

}

void CheckableModelFactory::fillCategories(CheckableModel* checkableModel)
{
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::BUSINESS)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::ENTERTAINMENT)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::GENERAL)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::HEALTH)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::SCIENCE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::SPORTS)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::categoryTypeAsString(ApplicationEnums::Category::TECHNOLOGY)));

}

void CheckableModelFactory::fillLanguages(CheckableModel* checkableModel)
{
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::ARABIC)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::GERMAN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::ENGLISH)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::SPANISH)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::FRENCH)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::HEBREW)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::DUTCH)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::NORWEGIAN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::PORTUGESE)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::RUSSIAN)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::NORTHERN_SAMI)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::LanguageAsString(ApplicationEnums::Language::ZULU)));

}

void CheckableModelFactory::fillSortBy(CheckableModel* checkableModel)
{
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::sortByAsString(ApplicationEnums::SortBy::RELEVANCY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::sortByAsString(ApplicationEnums::SortBy::POPULARITY)));
    checkableModel->appendItem(new CheckableItem(ApplicationEnums::sortByAsString(ApplicationEnums::SortBy::PUBLISHED_AT)));
}
