#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SocialPresence.hpp"

namespace IW8 {
	class LocalUserPresenceData {
	public:
		SocialPresence m_Current;	// 0x0000
		int m_LastUpdateTimestamp;	// 0x0030
		int m_NextUpdateTimestamp;	// 0x0034
	};
	ENGINE_ASSERT_SZ(LocalUserPresenceData, 0x0038);
}
