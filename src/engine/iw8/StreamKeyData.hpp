#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/streamer_handle_t.hpp"

namespace IW8 {
	union StreamKeyData {
		streamer_handle_t m_DataHandle;		// 0x0000
		std::uint8_t* m_ResidentData;		// 0x0000
		std::uint8_t* m_ResidentDataGPU;	// 0x0000
	};
}
