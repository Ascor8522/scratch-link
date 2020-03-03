#include "ScratchLinkWebSocketServer.h"

#include <QErrorMessage>

ScratchLinkWebSocketServer::ScratchLinkWebSocketServer()
	: QWebSocketServer{PROJECT_NAME, QWebSocketServer::NonSecureMode, nullptr}
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

const unsigned int ScratchLinkWebSocketServer::getPort() const
{
	return port;
}
