#include "ScratchLinkView.h"

ScratchLinkView::ScratchLinkView(const ScratchLinkApplication* const app)
	: QWidget(nullptr)
	, app{ app }
	, trayIcon{ new ScratchLinkTrayIcon() }
{
}

ScratchLinkView::~ScratchLinkView()
{
	delete trayIcon;
	trayIcon = nullptr;
}

void ScratchLinkView::setApp(const ScratchLinkApplication* const newApp)
{
	app = newApp;
}

ScratchLinkTrayIcon const& ScratchLinkView::getScratchLinkTrayIcon() const
{
	return *trayIcon;
}
