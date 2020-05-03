#include "ScratchLinkApplication.h"
#include <QSysInfo>
#include <QtWidgets/QErrorMessage>

ScratchLinkApplication::ScratchLinkApplication()
	: webSocketServer{ new ScratchLinkWebSocketServer() }
{
	this->webSocketServer->listen(webSocketServer->getAddress(), webSocketServer->getPort());
}

ScratchLinkApplication::~ScratchLinkApplication()
{
	webSocketServer->close();
	delete webSocketServer;
	webSocketServer = nullptr;
}

QString ScratchLinkApplication::getName()
{
	return ScratchLinkApplication::name;
}

QString ScratchLinkApplication::getVersion()
{
	return ScratchLinkApplication::version;
}

QString ScratchLinkApplication::getFulVersion()
{
	return ScratchLinkApplication::getName()
		   + " "
		   + ScratchLinkApplication::getVersion()
		   + "\n"
		   + QSysInfo::kernelType();
}

const ScratchLinkProtocolVersion* ScratchLinkApplication::getProtocolVersion()
{
	return ScratchLinkApplication::protocolVersion;
}

ScratchLinkWebSocketServer* ScratchLinkApplication::getWebSocketServer() const
{
	return this->webSocketServer;
}
