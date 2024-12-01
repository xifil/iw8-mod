#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class ClientEntityLinkToDef {
	public:
		int m_AnchorIndex;		// 0x0000
		vec3_t m_OriginOffset;	// 0x0004
		vec3_t m_AngleOffset;	// 0x0010
	};
	ENGINE_ASSERT_SZ(ClientEntityLinkToDef, 0x001C);
}
