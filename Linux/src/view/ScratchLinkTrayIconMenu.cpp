#include "ScratchLinkTrayIconMenu.h"

ScratchLinkTrayIconMenu::ScratchLinkTrayIconMenu()
	: QMenu(nullptr)
	, about{ new QAction() }
	, exit{ new QAction() }
{
	this->addAction(about);
	this->addSeparator();
	this->addAction(exit);
}

ScratchLinkTrayIconMenu::~ScratchLinkTrayIconMenu()
{
	delete about;
	about = nullptr;
	delete exit;
	exit = nullptr;
}

QAction& ScratchLinkTrayIconMenu::getAbout() const
{
	return *about;
}

QAction& ScratchLinkTrayIconMenu::getExit() const
{
	return *exit;
};
