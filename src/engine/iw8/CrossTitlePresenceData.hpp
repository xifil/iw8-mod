#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/bdPlatformType.hpp"

namespace IW8 {
	class CrossTitlePresenceData {
	public:
		std::uint64_t m_PlatformID;	// 0x0000
		std::uint32_t m_Version;	// 0x0008
		std::uint32_t m_TitleID;	// 0x000C
		bdPlatformType m_Platform;	// 0x0010
		bool m_Online;				// 0x0011
	private:
		char pad_0012[0x0006];		// 0x0012
	};
	ENGINE_ASSERT_SZ(CrossTitlePresenceData, 0x0018);
}
