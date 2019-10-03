#include "Everything.h"

Everything::Everything(QObject* parent)
    : QObject(parent)
    , m_restClient{ new RestClient() }
{
}
