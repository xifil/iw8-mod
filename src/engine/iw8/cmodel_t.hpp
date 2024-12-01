#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"
#include "engine/iw8/PhysicsAsset.hpp"

namespace IW8 {
	class cmodel_t {
	public:
		Bounds m_Bounds;							// 0x0000
		float m_Radius;								// 0x0018
	private:
		char pad_001C[0x0004];						// 0x0004
	public:
		PhysicsAsset* m_PhysicsAsset;				// 0x0020
		std::uint16_t m_PhysicsShapeOverrideIdx;	// 0x0028
		std::uint16_t m_NavObstacleIdx;				// 0x002A
		std::uint32_t m_EdgeFirstIndex;				// 0x002C
		std::uint32_t m_EdgeTotalCount;				// 0x0030
	private:
		char pad_0034[0x0004];						// 0x0034
	};
	ENGINE_ASSERT_SZ(cmodel_t, 0x0038);
}
