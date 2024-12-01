#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ClInputSequenceVirtualAxisKeyState {
		float m_Value;	// 0x0000
		int m_DownTime;	// 0x0004
	};
	ENGINE_ASSERT_SZ(ClInputSequenceVirtualAxisKeyState, 0x0008);
}
