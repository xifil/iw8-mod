#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ClInputSequenceState {
	public:
		int m_NextCommand;	// 0x0000
		int m_PrevTimeMs;	// 0x0004
	};
	ENGINE_ASSERT_SZ(ClInputSequenceState, 0x0008);
}
