#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	union vec3_t {
		float v[3];		// 0x0000
		struct {
			float x;	// 0x0000
			float y;	// 0x0004
			float z;	// 0x0008
		};
	};
	ENGINE_ASSERT_SZ(vec3_t, 0x000C);
}
