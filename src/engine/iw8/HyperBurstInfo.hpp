#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class HyperBurstInfo {
	public:
		float m_FireTimeFraction;	// 0x0000
		int m_CoolDownMs;			// 0x0004
		bool m_Enabled;				// 0x0008
	private:
		char pad_0009[0x0003];		// 0x0009
	};
	ENGINE_ASSERT_SZ(HyperBurstInfo, 0x000C);
}
