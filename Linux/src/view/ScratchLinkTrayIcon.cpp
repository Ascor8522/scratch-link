#include "ScratchLinkTrayIcon.h"
#include <Config.h>

ScratchLinkTrayIcon::ScratchLinkTrayIcon()
	: QSystemTrayIcon(nullptr)
	, menu{ new ScratchLinkTrayIconMenu() }
{
	this->setIcon(QIcon(":/icon"));
	this->setVisible(true);
	this->setContextMenu(menu);
	this->setToolTip(PROJECT_NAME);
}

ScratchLinkTrayIcon::~ScratchLinkTrayIcon()
{
	delete menu;
	menu = nullptr;
}

ScratchLinkTrayIconMenu const& ScratchLinkTrayIcon::getScratchLinkTrayIconMenu() const
{
	return *menu;
};
