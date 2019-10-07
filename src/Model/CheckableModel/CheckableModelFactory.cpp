#include "CheckableModelFactory.h"

CheckableModel* CheckableModelFactory::create(CheckableModelFactory::ModelType type)
{
    CheckableModel* checkableModel = new CheckableModel();
    switch (type) {
    case ModelType::Country: {
        fillCountries(checkableModel);
    }
    case ModelType::Category: {
        fillCategories(checkableModel);
    }
    case ModelType::Language: {
        fillLanguages(checkableModel);
    }
    case ModelType::Source: {
        fillSources(checkableModel);
    }
    case ModelType::SortBy: {
        fillSortBy(checkableModel);
    }
    case ModelType::PageSize: {
        fillPageSizes(checkableModel);
    }
    }
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

void CheckableModelFactory::fillSources(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillSortBy(CheckableModel* checkableModel)
{
}

void CheckableModelFactory::fillPageSizes(CheckableModel* checkableModel)
{
}
