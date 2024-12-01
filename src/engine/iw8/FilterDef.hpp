#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/SND_EQTYPE.hpp"

namespace IW8 {
	class FilterDef {
	public:
		std::uint32_t m_ID;				// 0x0000
		std::uint8_t m_EntChannelIdx;	// 0x0004
		std::uint8_t m_Band;			// 0x0005
	private:
		char pad_0006[0x0002];			// 0x0006
	public:
		SND_EQTYPE m_Type;				// 0x0008
		float m_Freq;					// 0x000C
		float m_Gain;					// 0x0010
		float m_Q;						// 0x0014
	};
	ENGINE_ASSERT_SZ(FilterDef, 0x0018);
}
