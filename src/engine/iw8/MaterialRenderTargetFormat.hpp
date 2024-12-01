#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class MaterialRenderTargetFormat {
	public:
		std::uint8_t m_DSFormat;			// 0x0000
		std::uint8_t m_ColorRTFormats[4];	// 0x0001
	};
	ENGINE_ASSERT_SZ(MaterialRenderTargetFormat, 0x0005);
}
