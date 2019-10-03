#include "Dispatcher.h"

Dispatcher::Dispatcher(QObject* parent)
    : QObject(parent)
    , m_requestBackend{ new RequestBackend(this) }
{
}

RequestBackend* Dispatcher::requestBackend() const
{
    return m_requestBackend;
}
