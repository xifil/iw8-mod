#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/WeaponOffsetPatternScale.hpp"

namespace IW8 {
	class WeaponOffsetPatternScaleInfo {
	public:
		int m_NumPatternScales;						// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		WeaponOffsetPatternScale* m_PatternScales;	// 0x0008
	};
	ENGINE_ASSERT_SZ(WeaponOffsetPatternScaleInfo, 0x0010);
}
