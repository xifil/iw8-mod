#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsAsset.hpp"

namespace IW8 {
	class TriggerModel {
	public:
		int m_Contents;								// 0x0000
		std::uint16_t m_HullCount;					// 0x0004
		std::uint16_t m_FirstHull;					// 0x0006
		std::uint16_t m_WindingCount;				// 0x0008
		std::uint16_t m_FirstWinding;				// 0x000A
		std::uint32_t m_Flags;						// 0x000C
		PhysicsAsset* m_PhysicsAsset;				// 0x0010
		std::uint16_t m_PhysicsShapeOverrideIdx;	// 0x0018
	private:
		char pad_001A[0x0006];						// 0x001A
	};
	ENGINE_ASSERT_SZ(TriggerModel, 0x0020);
}
