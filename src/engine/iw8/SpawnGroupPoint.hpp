#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class SpawnGroupPoint {
	public:
		vec3_t m_Origin;			// 0x0000
		vec3_t m_Angles;			// 0x000C
		std::uint16_t m_Cluster;	// 0x0018
		std::uint16_t m_Zone;		// 0x001A
	};
	ENGINE_ASSERT_SZ(SpawnGroupPoint, 0x001C);
}
