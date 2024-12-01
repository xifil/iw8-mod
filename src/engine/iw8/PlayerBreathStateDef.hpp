#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PlayerBreathStateDef {
	public:
		std::uint32_t m_StateType;	// 0x0000
	private:
		char pad_0004[0x0004];		// 0x0004
	public:
		const char* m_InhaleAlias;	// 0x0008
		const char* m_ExhaleAlias;	// 0x0010
		int m_MinBreaths;			// 0x0018
	private:
		char pad_001C[0x0004];		// 0x001C
	};
	ENGINE_ASSERT_SZ(PlayerBreathStateDef, 0x0020);
}
