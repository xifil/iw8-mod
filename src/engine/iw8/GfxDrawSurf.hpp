#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxDrawSurfFields.hpp"
#include "engine/iw8/Packed128.hpp"

namespace IW8 {
	union GfxDrawSurf {
		GfxDrawSurfFields m_Fields;	// 0x0000
		Packed128 m_Packed;			// 0x0000
	};
	ENGINE_ASSERT_SZ(GfxDrawSurf, 0x0010);
}
