#ifndef SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H
#define SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H

#include <QMenu>
#include <QAction>

class ScratchLinkTrayIconMenu : public QMenu
{
	Q_OBJECT

	private:
		QAction* about;
		QAction* exit;

	public:
		explicit ScratchLinkTrayIconMenu();
		~ScratchLinkTrayIconMenu() override;
		QAction& getAbout() const;
		QAction& getExit() const;

};

#endif //SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H
