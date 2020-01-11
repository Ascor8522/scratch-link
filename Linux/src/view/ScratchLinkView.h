#ifndef SCRATCHLINKVIEW_H
#define SCRATCHLINKVIEW_H

#include <QWidget>

#include "./ScratchLinkTrayIcon.h"
#include "../model/ScratchLinkApplication.h"

class ScratchLinkView : public QWidget
{
	Q_OBJECT

	private:
		const ScratchLinkApplication * app;
		const ScratchLinkTrayIcon* trayIcon;

	public:
		explicit ScratchLinkView(const ScratchLinkApplication* app);
		~ScratchLinkView() override;
		void setApp(const ScratchLinkApplication* newApp);
		ScratchLinkTrayIcon const& getScratchLinkTrayIcon() const;

};
#endif // SCRATCHLINKVIEW_H
