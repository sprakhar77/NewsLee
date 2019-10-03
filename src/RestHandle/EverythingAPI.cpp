#include "EverythingAPI.h"

EverythingAPI::EverythingAPI(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
}
