#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class EffectDefMap {
	public:
		char m_Name[64];		// 0x0000
		char m_FileName[256];	// 0x0040
	};
	ENGINE_ASSERT_SZ(EffectDevMap, 0x0140);
}
