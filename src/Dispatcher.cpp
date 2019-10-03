#include "Dispatcher.h"

#include "APIHandler/RestClient.h"

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_restClient()
{
}

RestClient* Dispatcher::restClient() const
{
    return m_restClient;
}
