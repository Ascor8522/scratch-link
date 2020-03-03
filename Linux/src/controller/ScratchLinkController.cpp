#include "ScratchLinkController.h"
#include <QApplication>
#include <QClipboard>
#include <QtWidgets/QErrorMessage>

ScratchLinkController::ScratchLinkController(const ScratchLinkApplication* const model, const ScratchLinkView* const view)
	: model{ model }
	, view{ view }
{
	view->getScratchLinkTrayIcon().getScratchLinkTrayIconMenu().getAbout().setText(model->getFullVersion());
	QObject::connect(
		&view->getScratchLinkTrayIcon().getScratchLinkTrayIconMenu().getAbout(),
		&QAction::triggered,
		[=] () {
			QApplication::clipboard()->setText(model->getFullVersion());
			if (system("notify-send")) {
				QString command = "notify-send 'Version Information copied to clipboard' \""
								  + model->getFullVersion()
								  + "\"";
				system((command.toStdString()).c_str());
			}
		}
	);

	view->getScratchLinkTrayIcon().getScratchLinkTrayIconMenu().getExit().setText("Exit");
	QObject::connect(
		&view->getScratchLinkTrayIcon().getScratchLinkTrayIconMenu().getExit(),
		&QAction::triggered,
		[=] () {
			QApplication::exit(0);
		}
	);

	QObject::connect(
		&model->getWebSocketServer(),
		&ScratchLinkWebSocketServer::newConnection,
		[=] () {
			qDebug("Connected");
		}
	);
}

ScratchLinkController::~ScratchLinkController() = default;
