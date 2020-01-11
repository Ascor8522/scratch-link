#ifndef SCRATCHLINKAPPLICATION_H
#define SCRATCHLINKAPPLICATION_H

#include <QString>
#include <Config.h>

class ScratchLinkApplication
{

	private:
		const QString name = PROJECT_NAME;
		const QString version = PROJECT_VERSION;

	public:
		ScratchLinkApplication();
		~ScratchLinkApplication();
		QString const& getName() const;
		QString const& getVersion() const;
		QString getFullVersion() const;

};

#endif // SCRATCHLINKAPPLICATION_H
