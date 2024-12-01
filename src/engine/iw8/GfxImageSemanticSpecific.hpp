#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	union GfxImageSemanticSpecific {
		float m_AtlasFps;					// 0x0000
		std::uint32_t m_AlbedoMapScaleBias;	// 0x0000
		std::uint32_t m_NormalMapScaleBias;	// 0x0000
		std::uint32_t m_MaxMipMap;			// 0x0000
	};
	ENGINE_ASSERT_SZ(GfxImageSemanticSpecific, 0x0004);
}
