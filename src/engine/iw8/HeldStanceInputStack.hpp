#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/StanceState.hpp"

namespace IW8 {
	class HeldStanceInputStack {
	public:
		StanceState m_HeldStances[2];	// 0x0000
		int m_StackIndex;				// 0x0008
	};
	ENGINE_ASSERT_SZ(HeldStanceInputStack, 0x000C);
}
