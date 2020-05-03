#include "ScratchLinkTrayIcon.h"
#include <Config.h>

ScratchLinkTrayIcon::ScratchLinkTrayIcon()
	: QSystemTrayIcon(nullptr), menu{ new ScratchLinkTrayIconMenu() }
{
	this->setIcon(QIcon(":/icon"));
	this->setVisible(true);
	this->setContextMenu((QMenu*) menu);
	this->setToolTip(PROJECT_NAME);
}

ScratchLinkTrayIcon::~ScratchLinkTrayIcon()
{
	delete menu;
	menu = nullptr;
}

const ScratchLinkTrayIconMenu* ScratchLinkTrayIcon::getScratchLinkTrayIconMenu() const
{
	return menu;
};
