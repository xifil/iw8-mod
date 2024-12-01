#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/base_vec2_t.hpp"

namespace IW8 {
	template <typename T>
	union base_vec3_t {
		T v[3];
		struct {
			T x;
			T y;
			T z;
		};
		base_vec2_t<T> xy;
	};
	ENGINE_ASSERT_SZ(base_vec3_t<int>, 0x000C);
}
