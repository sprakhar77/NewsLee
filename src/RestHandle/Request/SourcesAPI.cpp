#include "SourcesAPI.h"

#include <Qurl>

namespace {
namespace ApiEndpoint {
    const char* const URL_SOURCES = "https://newsapi.org/v2/sources";
}
}

SourcesAPI::SourcesAPI(QObject* parent)
    : QObject(parent)
{
}

QUrl SourcesAPI::prepareRequest()
{
    // prepare the actual request here with all the query parameters
    return QUrl(QLatin1String(ApiEndpoint::URL_SOURCES));
}
