#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndAliasLookup {
	public:
		const char* m_Name;	// 0x0000
	};
	ENGINE_ASSERT_SZ(SndAliasLookup, 0x0008);
}
