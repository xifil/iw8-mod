#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class CreateFxPaletteDef {
	public:
		scr_string_t m_AliasName;	// 0x0000
		scr_string_t m_EffectPath;	// 0x0004
		std::uint16_t m_RefCount;	// 0x0008
	private:
		char pad_000A[0x0002];		// 0x000A
	};
	ENGINE_ASSERT_SZ(CreateFxPaletteDef, 0x000C);
}
