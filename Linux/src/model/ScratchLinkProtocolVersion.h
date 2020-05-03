#ifndef _SCRATCHLINKPROTOCOLVERSION_H_
#define _SCRATCHLINKPROTOCOLVERSION_H_

#include <string>

class ScratchLinkProtocolVersion
{
	private:
		const unsigned int major = 1;
		const unsigned int minor = 0;

	public:
		explicit ScratchLinkProtocolVersion(unsigned int major, unsigned int minor);
		~ScratchLinkProtocolVersion() = default;

		std::string toString() const;

		bool operator==(const ScratchLinkProtocolVersion& version) const;
		bool operator<(const ScratchLinkProtocolVersion& version) const;
		bool operator<=(const ScratchLinkProtocolVersion& version) const;
		bool operator>(const ScratchLinkProtocolVersion& version) const;
		bool operator>=(const ScratchLinkProtocolVersion& version) const;
};

#endif //_SCRATCHLINKPROTOCOLVERSION_H_
