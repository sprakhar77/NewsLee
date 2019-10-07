#include <src/Model/CheckableModel/CheckableModel.h>

class CheckableModelFactory {
public:
    enum class ModelType {
        Country,
        Category,
        Language,
        Source,
        SortBy,
        PageSize,

    };

    static CheckableModel* create(ModelType type);

private:
    CheckableModelFactory();
    static void fillCountries(CheckableModel* checkableModel);
    static void fillCategories(CheckableModel* checkableModel);
    static void fillLanguages(CheckableModel* checkableModel);
    static void fillSources(CheckableModel* checkableModel);
    static void fillSortBy(CheckableModel* checkableModel);
    static void fillPageSizes(CheckableModel* checkableModel);
};
