#ifndef SCRATCHLINK_SCRATCHLINKTRAYICON_H
#define SCRATCHLINK_SCRATCHLINKTRAYICON_H

#include <QSystemTrayIcon>
#include "ScratchLinkTrayIconMenu.h"

class ScratchLinkTrayIcon : public QSystemTrayIcon
{
	Q_OBJECT

	private:
		ScratchLinkTrayIconMenu* menu;

	public:
		explicit ScratchLinkTrayIcon();
		~ScratchLinkTrayIcon() override;
		ScratchLinkTrayIconMenu const& getScratchLinkTrayIconMenu() const;

};

#endif //SCRATCHLINK_SCRATCHLINKTRAYICON_H
