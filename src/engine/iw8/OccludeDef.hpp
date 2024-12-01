#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class OccludeDef {
	public:
		std::uint32_t m_ID;				// 0x0000
		std::uint16_t m_EntChannelIdx;	// 0x0004
	private:
		char pad_0006[0x0002];			// 0x0006
	public:
		float m_CutoffLevel1;			// 0x0008
		float m_CutoffLevel2;			// 0x000C
		float m_CutoffLevel3;			// 0x0010
		float m_CutoffLevel4;			// 0x0014
		float m_AttnLevel1;				// 0x0018
		float m_AttnLevel2;				// 0x001C
		float m_AttnLevel3;				// 0x0020
		float m_AttnLevel4;				// 0x0024
	};
	ENGINE_ASSERT_SZ(OccludeDef, 0x0028);
}
