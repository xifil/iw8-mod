#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SpawnGroupCluster.hpp"
#include "engine/iw8/SpawnGroupPoint.hpp"
#include "engine/iw8/SpawnGroupZone.hpp"

namespace IW8 {
	class SpawnGroup {
	public:
		std::uint16_t m_PointCount;		// 0x0000
	private:
		char pad_0002[0x0006];			// 0x0002
	public:
		SpawnGroupPoint* m_Points;		// 0x0008
		std::uint16_t m_ClusterCount;	// 0x0010
	private:
		char pad_0012[0x0006];			// 0x0012
	public:
		SpawnGroupCluster* m_Clusters;	// 0x0018
		std::uint16_t m_ZoneCount;		// 0x0020
	private:
		char pad_0022[0x0006];			// 0x0022
	public:
		SpawnGroupZone* m_Zones;		// 0x0028
	};
	ENGINE_ASSERT_SZ(SpawnGroup, 0x0030);
}
