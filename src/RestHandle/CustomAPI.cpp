#include "CustomAPI.h"

CustomAPI::CustomAPI(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
}
