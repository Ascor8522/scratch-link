#ifndef SCRATCHLINK_SCRATCHLINKCONTROLLER_H
#define SCRATCHLINK_SCRATCHLINKCONTROLLER_H

#include <cstdlib>

#include "../model/ScratchLinkApplication.h"
#include "../view/ScratchLinkView.h"

/**
 * The controller of the ScratchLink application
 */
class ScratchLinkController
{

	private:
		const ScratchLinkApplication* const model;
		const ScratchLinkView* const view;

	public:
		explicit ScratchLinkController(const ScratchLinkApplication* model, const ScratchLinkView* view);
		~ScratchLinkController();

	private:
		static void onVersionClicked();
		static void onExitClicked();

		void onServerNewConnection();
		void onServerClosed();

		static void onSocketTextMessageRecieved();
		static void onSocketDisconnected();

		static void log(const std::string& message);

};

#endif //SCRATCHLINK_SCRATCHLINKCONTROLLER_H
