#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class BallisticInfoCalculated {
	public:
		float* m_Distances;			// 0x0000
		float m_ZeroingAngle;		// 0x0008
		int m_NumDistanceEntries;	// 0x000C
	};
	ENGINE_ASSERT_SZ(BallisticInfoCalculated, 0x0010);
}
