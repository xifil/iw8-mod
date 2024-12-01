#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class ClientTriggerBlendNode {
	public:
		vec3_t m_PointA;			// 0x0000
		vec3_t m_PointB;			// 0x000C
		std::uint16_t m_TriggerA;	// 0x0018
		std::uint16_t m_TriggerB;	// 0x001A
	};
	ENGINE_ASSERT_SZ(ClientTriggerBlendNode, 0x001C);
}
