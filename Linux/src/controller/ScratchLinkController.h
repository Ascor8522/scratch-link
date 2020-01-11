#ifndef SCRATCHLINK_SCRATCHLINKCONTROLLER_H
#define SCRATCHLINK_SCRATCHLINKCONTROLLER_H

#include "../model/ScratchLinkApplication.h"
#include "../view/ScratchLinkView.h"

class ScratchLinkController
{

	private:
		const ScratchLinkApplication* model;
		const ScratchLinkView* view;

	public:
		explicit ScratchLinkController(const ScratchLinkApplication* model, const ScratchLinkView* view);
		~ScratchLinkController();

};

#endif //SCRATCHLINK_SCRATCHLINKCONTROLLER_H
