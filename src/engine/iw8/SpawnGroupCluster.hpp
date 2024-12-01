#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"

namespace IW8 {
	class SpawnGroupCluster {
	public:
		std::uint16_t m_Zone;		// 0x0000
		std::uint16_t m_PointCount;	// 0x0002
	private:
		char pad_0004[0x0004];		// 0x0004
	public:
		std::uint16_t* m_Points;	// 0x0008
		Bounds m_Bounds;			// 0x0010
	};
	ENGINE_ASSERT_SZ(SpawnGroupCluster, 0x0028);
}
