#include <src/model/ScratchLinkApplication.h>
#include "ScratchLinkTrayIconMenu.h"

ScratchLinkTrayIconMenu::ScratchLinkTrayIconMenu()
	: QMenu(nullptr)
{
	QAction * a = new QAction();
	a->setText(ScratchLinkApplication::getFulVersion());
	this->addAction(a);
	this->about = a;

	this->addSeparator();

	QAction * b = new QAction();
	b->setText("Exit");
	this->addAction(b);
	this->exit = b;
}

ScratchLinkTrayIconMenu::~ScratchLinkTrayIconMenu()
{
	delete about;
	about = nullptr;
	delete exit;
	exit = nullptr;
}

const QAction* ScratchLinkTrayIconMenu::getAbout() const
{
	return about;
}

const QAction* ScratchLinkTrayIconMenu::getExit() const
{
	return exit;
};
