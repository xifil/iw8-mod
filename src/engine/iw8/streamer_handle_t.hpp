#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class streamer_handle_t {
	public:
		std::uint64_t m_Data;	// 0x0000
	};
	ENGINE_ASSERT_SZ(streamer_handle_t, 0x0008);
}
