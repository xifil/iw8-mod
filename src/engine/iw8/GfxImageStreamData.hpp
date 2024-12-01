#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/XPakEntryInfo.hpp"
#include "engine/iw8/enums/GfxImageStreamLevelCountAndSize.hpp"

namespace IW8 {
	class GfxImageStreamData {
	public:
		XPakEntryInfo m_XPakEntry;								// 0x0000
		GfxImageStreamLevelCountAndSize m_LevelCountAndSize;	// 0x0020
		std::uint16_t m_Width;									// 0x0024
		std::uint16_t m_Height;									// 0x0026
	};
	ENGINE_ASSERT_SZ(GfxImageStreamData, 0x0028);
}
