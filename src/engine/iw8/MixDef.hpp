#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class MixDef {
	public:
		std::uint32_t m_ID;				// 0x0000
		std::uint16_t m_VolModIndex;	// 0x0004
	private:
		char pad_0006[0x0002];			// 0x0006
	public:
		float m_Volume;					// 0x0008
		float m_Fade;					// 0x000C
	};
	ENGINE_ASSERT_SZ(MixDef, 0x0010);
}
