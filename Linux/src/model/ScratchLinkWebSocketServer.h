#ifndef _SCRATCHLINKWEBSOCKETSERVER_H_
#define _SCRATCHLINKWEBSOCKETSERVER_H_

#include <QtWebSockets/QWebSocketServer>
#include <Config.h>

class ScratchLinkWebSocketServer : public QWebSocketServer
{

	private:
		const QHostAddress address = QHostAddress::LocalHost;
		const unsigned int port = 20110;
		QWebSocket* socket = nullptr;

	public:
		explicit ScratchLinkWebSocketServer();
		~ScratchLinkWebSocketServer() override;

		const QHostAddress& getAddress() const;

		unsigned int getPort() const;

		QWebSocket* getSocket() const;
		void setSocket(QWebSocket* socket);

		void acceptConnection();
};

#endif //_SCRATCHLINKWEBSOCKETSERVER_H_
