#include "SourcesBackend.h"

#include <QJsonArray>

namespace {
namespace JsonKeys {
    const char* const SOURCES = "sources";
}
}

SourcesBackend::SourcesBackend(QObject* parent)
    : QObject(parent)
    , m_sourcesAPI{ new SourcesAPI(this) }
{
    connect(&m_restClient, &RestClient::responseRecieved, this, &SourcesBackend::onResponseRecieved);
}

SourcesAPI* SourcesBackend::sourcesAPI() const
{
    return m_sourcesAPI;
}

QVector<Source> SourcesBackend::sources() const
{
    return m_sources;
}

void SourcesBackend::fetch()
{
    Q_ASSERT(!m_sourcesAPI);
    const QUrl url = m_sourcesAPI->prepareRequest();
}

void SourcesBackend::onResponseRecieved(const QJsonObject& json)
{
    Q_ASSERT(!json.empty());
    m_sources.clear();
    const auto sources = json[QLatin1String(JsonKeys::SOURCES)].toArray();
    for (const auto source : sources) {
        m_sources.append(Source(source.toObject()));
    }
}
