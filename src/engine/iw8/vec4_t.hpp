#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	union vec4_t {
		float v[4];		// 0x0000
		struct {
			float x;	// 0x0000
			float y;	// 0x0004
			float z;	// 0x0008
			float w;	// 0x000C
		};
		struct {
			float r;	// 0x0000
			float g;	// 0x0004
			float b;	// 0x0008
			float a;	// 0x000C
		};
		vec3_t xyz;		// 0x0000
	};
	ENGINE_ASSERT_SZ(vec4_t, 0x0010);
}
