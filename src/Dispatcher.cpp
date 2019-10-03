#include "Dispatcher.h"

#include <src/APIHandler/RestClient.h>

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
}

RestClient* Dispatcher::restClient() const
{
    return m_restClient;
}
