#include "ScratchLinkView.h"

ScratchLinkView::ScratchLinkView(const ScratchLinkApplication* const app)
	: QWidget(nullptr), app{ app }, trayIcon{ new ScratchLinkTrayIcon() }
{
}

ScratchLinkView::~ScratchLinkView()
{
	delete trayIcon;
	trayIcon = nullptr;
}

const ScratchLinkTrayIcon* ScratchLinkView::getScratchLinkTrayIcon() const
{
	return trayIcon;
}
