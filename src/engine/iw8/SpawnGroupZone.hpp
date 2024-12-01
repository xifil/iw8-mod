#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class SpawnGroupZone {
	public:
		scr_string_t m_Name;			// 0x0000
		std::uint16_t m_PointCount;		// 0x0004
	private:
		char pad_0006[0x0002];			// 0x0006
	public:
		std::uint16_t* m_Points;		// 0x0008
		std::uint16_t m_ClusterCount;	// 0x0010
	private:
		char pad_0012[0x0006];			// 0x0012
	public:
		std::uint16_t* m_Clusters;		// 0x0018
		Bounds m_Bounds;				// 0x0020
	};
	ENGINE_ASSERT_SZ(SpawnGroupZone, 0x0038);
}
