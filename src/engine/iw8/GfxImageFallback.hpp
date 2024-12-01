#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class GfxImageFallback {
	public:
		std::uint8_t* m_Pixels;	// 0x0000
		std::uint32_t m_Size;	// 0x0008
		std::uint16_t m_Width;	// 0x000C
		std::uint16_t m_Height;	// 0x000E
	};
	ENGINE_ASSERT_SZ(GfxImageFallback, 0x0010);
}
