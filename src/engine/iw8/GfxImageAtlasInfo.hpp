#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImageAtlasSize.hpp"

namespace IW8 {
	union GfxImageAtlasInfo {
		GfxImageAtlasSize m_AtlasSize;			// 0x0000
		std::uint16_t m_PackedAtlasDataSize;	// 0x0000
	};
	ENGINE_ASSERT_SZ(GfxImageAtlasInfo, 0x0002);
}
