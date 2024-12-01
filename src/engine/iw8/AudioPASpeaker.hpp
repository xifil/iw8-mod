#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class AudioPASpeaker {
	public:
		vec3_t m_Origin;				// 0x0000
		std::uint32_t m_NameHash;		// 0x000C
		std::uint32_t m_EntChannelHash;	// 0x0010
	};
	ENGINE_ASSERT_SZ(AudioPASpeaker, 0x0014);
}
