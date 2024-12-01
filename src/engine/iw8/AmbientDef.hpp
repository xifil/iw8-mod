#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AmbientDef {
	public:
		const char* m_Name;					// 0x0000
		std::uint32_t m_ID;					// 0x0008
		std::uint16_t m_AmbientEventIndex;	// 0x000C
		std::uint16_t m_NumEvents;			// 0x000E
		float m_TimeMin;					// 0x0010
		float m_TimeMax;					// 0x0014
	};
	ENGINE_ASSERT_SZ(AmbientDef, 0x0018);
}
