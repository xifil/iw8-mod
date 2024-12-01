#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class WeaponOffsetPatternScale {
	public:
		scr_string_t m_PatternKey;	// 0x0000
		vec3_t m_Scale;				// 0x0004
	};
	ENGINE_ASSERT_SZ(WeaponOffsetPatternScale, 0x0010);
}
