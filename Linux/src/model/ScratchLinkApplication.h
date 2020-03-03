#ifndef SCRATCHLINKAPPLICATION_H
#define SCRATCHLINKAPPLICATION_H

#include <QString>
#include <Config.h>
#include "ScratchLinkWebSocketServer.h"

class ScratchLinkApplication
{

	private:
		const QString name = PROJECT_NAME;
		const QString version = PROJECT_VERSION;
		ScratchLinkWebSocketServer * webSocketServer;

	public:
		explicit ScratchLinkApplication();
		~ScratchLinkApplication();
		QString const& getName() const;
		QString const& getVersion() const;
		QString getFullVersion() const;
		const ScratchLinkWebSocketServer& getWebSocketServer() const;

};

#endif // SCRATCHLINKAPPLICATION_H
