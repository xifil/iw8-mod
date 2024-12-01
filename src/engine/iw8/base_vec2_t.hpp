#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	template <typename T>
	union base_vec2_t {
		T v[2];
		struct {
			T x;
			T y;
		};
	};
	ENGINE_ASSERT_SZ(base_vec2_t<int>, 0x0008);
}
