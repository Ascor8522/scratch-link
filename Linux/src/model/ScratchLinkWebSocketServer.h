#ifndef _SCRATCHLINKWEBSOCKETSERVER_H_
#define _SCRATCHLINKWEBSOCKETSERVER_H_

#include <QtWebSockets/QWebSocketServer>
#include <Config.h>

class ScratchLinkWebSocketServer : public QWebSocketServer
{

	private:
		QHostAddress address = QHostAddress::LocalHost;
		unsigned int port = 20110;

	public:
		explicit ScratchLinkWebSocketServer();
		~ScratchLinkWebSocketServer() override;
		const QHostAddress& getAddress() const;
		const unsigned int getPort() const;

};

#endif //_SCRATCHLINKWEBSOCKETSERVER_H_
