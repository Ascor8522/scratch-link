#include "ScratchLinkApplication.h"
#include <QSysInfo>

ScratchLinkApplication::ScratchLinkApplication() = default;

ScratchLinkApplication::~ScratchLinkApplication() = default;

QString const& ScratchLinkApplication::getName() const
{
	return name;
}

QString const& ScratchLinkApplication::getVersion() const
{
	return version;
}

QString ScratchLinkApplication::getFullVersion() const
{
	return getName() + " " + getVersion() + " " + QSysInfo::kernelType();
}
