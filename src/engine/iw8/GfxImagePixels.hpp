#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/streamer_handle_t.hpp"

namespace IW8 {
	union GfxImagePixels {
		streamer_handle_t m_StreamedDataHandle;	// 0x0000
		std::uint8_t* m_ResidentData;			// 0x0000
	};
	ENGINE_ASSERT_SZ(GfxImagePixels, 0x0008);
}
