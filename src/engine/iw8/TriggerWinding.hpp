#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class TriggerWinding {
	public:
		vec3_t m_Dir;				// 0x0000
		std::uint16_t m_PointCount;	// 0x000C
		std::uint16_t m_FirstPoint;	// 0x000E
		std::uint32_t m_Flags;		// 0x0010
	};
	ENGINE_ASSERT_SZ(TriggerWinding, 0x0014);
}
