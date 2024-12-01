#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class GCRef {
	public:
		std::uint64_t m_GCPtr64;	// 0x0000
	};
	ENGINE_ASSERT_SZ(GCRef, 0x0008);
}
