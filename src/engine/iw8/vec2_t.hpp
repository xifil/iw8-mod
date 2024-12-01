#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	union vec2_t {
		float v[2];		// 0x0000
		struct {
			float x;	// 0x0000
			float y;	// 0x0004
		};
	};
	ENGINE_ASSERT_SZ(vec2_t, 0x0008);
}
