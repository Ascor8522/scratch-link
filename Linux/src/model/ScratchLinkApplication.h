#ifndef SCRATCHLINKAPPLICATION_H
#define SCRATCHLINKAPPLICATION_H

#include <QString>
#include <Config.h>

#include "ScratchLinkWebSocketServer.h"
#include "ScratchLinkProtocolVersion.h"

class ScratchLinkApplication
{

	private:
		inline static const QString name = PROJECT_NAME;
		inline static const QString version = PROJECT_VERSION;
		inline static const ScratchLinkProtocolVersion* protocolVersion = new ScratchLinkProtocolVersion
			{
				(unsigned int)PROJECT_VERSION_MAJOR,
				(unsigned int)PROJECT_VERSION_MINOR
			};
		ScratchLinkWebSocketServer* webSocketServer;

	public:
		explicit ScratchLinkApplication();
		~ScratchLinkApplication();

		static QString getName();
		static QString getVersion();
		static QString getFulVersion();
		static const ScratchLinkProtocolVersion* getProtocolVersion();

		ScratchLinkWebSocketServer* getWebSocketServer() const;

};

#endif // SCRATCHLINKAPPLICATION_H
