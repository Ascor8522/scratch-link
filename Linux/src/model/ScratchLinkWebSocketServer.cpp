#include "ScratchLinkWebSocketServer.h"

#include <QErrorMessage>

ScratchLinkWebSocketServer::ScratchLinkWebSocketServer()
	: QWebSocketServer{ PROJECT_NAME, QWebSocketServer::NonSecureMode, nullptr }
{
}

ScratchLinkWebSocketServer::~ScratchLinkWebSocketServer()
{
	close();
}

const QHostAddress& ScratchLinkWebSocketServer::getAddress() const
{
	return address;
}

unsigned int ScratchLinkWebSocketServer::getPort() const
{
	return port;
}

QWebSocket* ScratchLinkWebSocketServer::getSocket() const
{
	return this->socket;
}

void ScratchLinkWebSocketServer::setSocket(QWebSocket* const socket)
{
	this->socket = socket;
}

void ScratchLinkWebSocketServer::acceptConnection()
{
	QWebSocket * s = this->nextPendingConnection();
	if(s != nullptr) {
		this->socket = s;
	}
}
