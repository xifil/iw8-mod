#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SndAlias.hpp"

namespace IW8 {
	class SndAliasList {
	public:
		const char* m_AliasName;	// 0x0000
		std::uint32_t m_ID;			// 0x0008
	private:
		char pad_000C[0x0004];		// 0x000C
	public:
		SndAlias* m_Head;			// 0x0010
		int m_Count;				// 0x0018
		int m_Sequence;				// 0x001C
	};
	ENGINE_ASSERT_SZ(SndAliasList, 0x0020);
}
