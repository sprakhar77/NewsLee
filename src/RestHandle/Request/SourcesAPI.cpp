#include "SourcesAPI.h"

#include <QUrl>

namespace {
namespace ApiEndpoint {
    const char* const URL_SOURCES = "https://newsapi.org/v2/sources";
}
}

SourcesAPI::SourcesAPI(QObject* parent)
    : QObject(parent)
{
    m_country = CheckableModelFactory::create(CheckableModelFactory::ModelType::Country);
    m_category = CheckableModelFactory::create(CheckableModelFactory::ModelType::Category);
    m_language = CheckableModelFactory::create(CheckableModelFactory::ModelType::Language);
}

QUrl SourcesAPI::prepareRequest()
{
    // prepare the actual request here with all the query parameters
    return QUrl(QLatin1String(ApiEndpoint::URL_SOURCES));
}

CheckableModel* SourcesAPI::country() const
{
    return m_country;
}

CheckableModel* SourcesAPI::category() const
{
    return m_category;
}

CheckableModel* SourcesAPI::language() const
{
    return m_language;
}
