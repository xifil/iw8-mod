#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/TTFDef.hpp"

namespace IW8 {
	class GfxFont {
	public:
		const char* m_FontName;	// 0x0000
		int m_PixelHeight;		// 0x0008
		int m_TTFCount;			// 0x000C
		TTFDef* m_TTFDefs[4];	// 0x0010
	};
	ENGINE_ASSERT_SZ(GfxFont, 0x0030);
}
