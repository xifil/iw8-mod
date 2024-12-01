#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class float4 {
	public:
		__m128 v;	// 0x0000
	};
	ENGINE_ASSERT_SZ(float4, 0x0010);
}
