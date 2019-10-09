#include "CheckableModelFactory.h"

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
    case ModelType::PageSize: {
        fillPageSizes(checkableModel);
        return checkableModel;
    }
    }
    return checkableModel;
}

void CheckableModelFactory::fillCountries(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillCategories(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillLanguages(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillSortBy(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillPageSizes(CheckableModel* checkableModel)
{
}
