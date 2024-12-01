#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class GfxImageAtlasSize {
	public:
		std::uint8_t m_RowCount;	// 0x0000
		std::uint8_t m_ColCount;	// 0x0001
	};
	ENGINE_ASSERT_SZ(GfxImageAtlasSize, 0x0002);
}
