//
// Created by ascor8522 on 13.03.20.
//

#include "ScratchLinkProtocolVersion.h"
ScratchLinkProtocolVersion::ScratchLinkProtocolVersion(const unsigned int major, unsigned int minor)
	: major{ major }, minor{ minor }
{
}

std::string ScratchLinkProtocolVersion::toString() const
{
	return this->major + "." + this->minor;
}

bool ScratchLinkProtocolVersion::operator==(const ScratchLinkProtocolVersion& version) const
{
	return this->major == version.major
		   && this->minor == version.minor;
}

bool ScratchLinkProtocolVersion::operator<(const ScratchLinkProtocolVersion& version) const
{
	return this->major < version.major
		   || (this->major == version.major && this->minor < version.minor);
}

bool ScratchLinkProtocolVersion::operator<=(const ScratchLinkProtocolVersion& version) const
{
	return *this < version
		   || *this == version;
}

bool ScratchLinkProtocolVersion::operator>(const ScratchLinkProtocolVersion& version) const
{
	return this->major > version.major
		   || (this->major == version.major && this->minor > version.minor);
}

bool ScratchLinkProtocolVersion::operator>=(const ScratchLinkProtocolVersion& version) const
{
	return *this > version
		   || *this == version;
}

