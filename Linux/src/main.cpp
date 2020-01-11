#include <QApplication>

#include "./model/ScratchLinkApplication.h"
#include "./view/ScratchLinkView.h"
#include "./controller/ScratchLinkController.h"

int main(int argc, char* argv[])
{
	const QApplication a(argc, argv);
	const ScratchLinkApplication app;
	const ScratchLinkView v{ &app };
	const ScratchLinkController c{ &app, &v };
	return QApplication::exec();
}
