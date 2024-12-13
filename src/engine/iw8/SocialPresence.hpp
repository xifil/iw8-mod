#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/CrossTitlePresenceData.hpp"

namespace IW8 {
	class SocialPresence {
	public:
		CrossTitlePresenceData m_CrossTitlePresenceData;	// 0x0000
		std::uint32_t m_SessionFlags;						// 0x0018
		char m_ClanTag[12];									// 0x001C
		char m_Version;										// 0x0028
		char m_Context;										// 0x0029
		char m_GameType;									// 0x002A
		char m_MapIndex;									// 0x002B
		char m_Flags;										// 0x002C
		char m_InputType;									// 0x002D
	private:
		char pad_002E[0x0002];								// 0x002E
	};
	ENGINE_ASSERT_SZ(SocialPresence, 0x0030);
}
