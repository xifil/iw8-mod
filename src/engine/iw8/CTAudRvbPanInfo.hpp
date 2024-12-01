#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class CTAudRvbPanInfo {
	public:
		bool m_HasCustomPosition;	// 0x0000
	private:
		char pad_0001[0x0003];		// 0x0001
	public:
		vec3_t m_Position;			// 0x0004
		float m_MaxWallDistance;	// 0x0010
		float m_MinReverbVolume;	// 0x0014
	};
	ENGINE_ASSERT_SZ(CTAudRvbPanInfo, 0x0018);
}
