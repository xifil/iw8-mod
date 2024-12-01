#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class SecureCLViewangles {
		vec3_t m_ClViewAngles;	// 0x0000
	};
	ENGINE_ASSERT_SZ(SecureCLViewangles, 0x000C);
}
