#include "ScratchLinkApplication.h"
#include <QSysInfo>
#include <QtWidgets/QErrorMessage>

ScratchLinkApplication::ScratchLinkApplication()
	: webSocketServer{ new ScratchLinkWebSocketServer() }
{
	webSocketServer->listen(webSocketServer->getAddress(), webSocketServer->getPort());
	if(!webSocketServer->isListening()) {
	}
	QErrorMessage * em{new QErrorMessage()};
	em->showMessage("TEST");
	delete em;

};

ScratchLinkApplication::~ScratchLinkApplication()
{
	webSocketServer->close();
	delete webSocketServer;
	webSocketServer = nullptr;
};

QString const& ScratchLinkApplication::getName() const
{
	return name;
}

QString const& ScratchLinkApplication::getVersion() const
{
	return version;
}

QString ScratchLinkApplication::getFullVersion() const
{
    return getName() + " " + getVersion() + "\n" + QSysInfo::kernelType();
}

const ScratchLinkWebSocketServer& ScratchLinkApplication::getWebSocketServer() const
{
	return *webSocketServer;
}
