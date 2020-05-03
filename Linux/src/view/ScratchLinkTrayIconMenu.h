#ifndef SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H
#define SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H

#include <QMenu>
#include <QAction>

class ScratchLinkTrayIconMenu : public QMenu
{
	Q_OBJECT

	private:
		const QAction* about;
		const QAction* exit;

	public:
		explicit ScratchLinkTrayIconMenu();
		~ScratchLinkTrayIconMenu() override;

		const QAction* getAbout() const;
		const QAction* getExit() const;

};

#endif //SCRATCHLINK_SCRATCHLINKTRAYICONMENU_H
