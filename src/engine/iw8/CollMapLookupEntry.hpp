#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class CollMapLookupEntry {
	public:
		const char* m_TargetName;	// 0x0000
		int m_BrushIndex;			// 0x0008
	private:
		char pad_000C[0x0004];		// 0x000C
	};
	ENGINE_ASSERT_SZ(CollMapLookupEntry, 0x0010);
}
