#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class MRef {
	public:
		std::uint64_t m_Ptr64;	// 0x0000
	};
	ENGINE_ASSERT_SZ(MRef, 0x0008);
}
