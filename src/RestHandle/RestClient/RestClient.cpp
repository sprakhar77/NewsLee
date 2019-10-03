#include "RestClient.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

namespace {
namespace HttpConstants {
    const char* const HTTP_HEADER_AUTHORIZATION = "Authorization";
    const char* const AUTHORIZATION_BEARER = "Bearer";
    const char* const API_KEY = "f71b5d47b67744a0b30ab26ea713159e";
}

namespace JsonKeys {
    const char* const STATUS = "status";
}

namespace JsonValues {
    const char* const OK = "ok";
}
}

RestClient::RestClient(QObject* parent)
    : QObject(parent)
    , m_networkAccessManager{ new QNetworkAccessManager(this) }
    , m_reply{ nullptr }
    , m_dataBuffer{ new QByteArray }
{
}

void RestClient::sendRequest(const QUrl& url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader(HttpConstants::HTTP_HEADER_AUTHORIZATION,
        (QLatin1String(HttpConstants::AUTHORIZATION_BEARER) + QLatin1Char(' ') + HttpConstants::API_KEY).toUtf8());

    m_reply = m_networkAccessManager->get(request);
    connect(m_reply, &QIODevice::readyRead, this, &RestClient::onDataReadReady);
    connect(m_reply, &QNetworkReply::finished, this, &RestClient::onRequestCompleted);
}

void RestClient::onDataReadReady()
{
    m_dataBuffer->append(m_reply->readAll());
}

void RestClient::onRequestCompleted()
{
    if (m_reply->error()) {
        qDebug() << "There was an error to get the response" << m_reply->errorString();
    } else {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(*m_dataBuffer);
        const QJsonObject jsonReply = jsonDocument.object();
        if (jsonReply.empty() || jsonReply.value(QLatin1String(JsonKeys::STATUS)).toString() != JsonValues::OK) {
            qDebug() << "Error : The response code is -" << jsonReply.value(QLatin1String(JsonKeys::STATUS)).toString();
            return;
        }
        emit responseRecieved(jsonReply);
    }
}
