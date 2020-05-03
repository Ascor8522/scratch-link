#include "ScratchLinkController.h"
#include <QApplication>
#include <QClipboard>
#include <iostream>

/**
 * Creates a new ScratchLink Controller
 * @param model a pointer to the model of the application
 * @param view a pointer to the view of the application
 */
ScratchLinkController::ScratchLinkController(const ScratchLinkApplication* const model, const ScratchLinkView* const view)
	: model{ model }
	, view{ view }
{

	const ScratchLinkTrayIconMenu* ti{ this->view->getScratchLinkTrayIcon()->getScratchLinkTrayIconMenu() };

	QObject::connect(ti->getAbout(), &QAction::triggered, &ScratchLinkController::onVersionClicked);
	QObject::connect(ti->getExit(), &QAction::triggered, &ScratchLinkController::onExitClicked);
/*
	QObject::connect(this->model->getWebSocketServer(), &ScratchLinkWebSocketServer::newConnection, this, &ScratchLinkController::onServerNewConnection);
	QObject::connect(this->model->getWebSocketServer(), &ScratchLinkWebSocketServer::closed, this, &ScratchLinkController::onServerClosed);
 */
}

ScratchLinkController::~ScratchLinkController() = default;

void ScratchLinkController::onVersionClicked()
{
	QApplication::clipboard()->setText(ScratchLinkApplication::getFulVersion());
	if (system("notify-send"))
	{
		QString command = "notify-send 'Version Information copied to clipboard' \""
						  + ScratchLinkApplication::getFulVersion()
						  + "\"";
		system((command.toStdString()).c_str());
	}
}

void ScratchLinkController::onExitClicked()
{
	QApplication::exit(0);
}

void ScratchLinkController::onServerNewConnection()
{
	ScratchLinkController::log("New client attempted to connect");
	QWebSocket* s = this->model->getWebSocketServer()->nextPendingConnection();

	/*
	if (this->model->getWebSocketServer()->getSocket() != nullptr)
	{
		s->close(QWebSocketProtocol::CloseCode::CloseCodeNormal, "Another client is already connected");
		delete s;
		s = nullptr;
		ScratchLinkController::log("Connection request rejected");
		return;
	}
	 */
	this->model->getWebSocketServer()->setSocket(s);
	this->model->getWebSocketServer()->acceptConnection();
/*
	QObject::connect(s, &QWebSocket::textMessageReceived, &ScratchLinkController::onSocketTextMessageRecieved);
	QObject::connect(s, &QWebSocket::disconnected, &ScratchLinkController::onSocketDisconnected);
*/
	ScratchLinkController::log("New client is now connected");
}

void ScratchLinkController::onServerClosed()
{
	ScratchLinkController::log("Server closed");
}

void ScratchLinkController::onSocketTextMessageRecieved()
{
	ScratchLinkController::log("Client sent a message");
}

void ScratchLinkController::onSocketDisconnected()
{
	ScratchLinkController::log("Client disconnected");
}

void ScratchLinkController::log(const std::string& message)
{
	QDateTime local(QDateTime::currentDateTime());
	std::cout << "[" << local.toString().toStdString() << "] " << message << "\n";
}
