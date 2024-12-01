#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxFont.hpp"
#include "engine/iw8/Material.hpp"

namespace IW8 {
	class CachedAssets_t {
	public:
		Material* m_ScrollBarArrowUp;			// 0x0000
		Material* m_ScrollBarArrowDown;			// 0x0008
		Material* m_ScrollBarArrowLeft;			// 0x0010
		Material* m_ScrollBarArrowRight;		// 0x0018
		Material* m_ScrollBar;					// 0x0020
		Material* m_SliderBar;					// 0x0028
		Material* m_WhiteMaterial;				// 0x0030
		Material* m_Cursor;						// 0x0038
		Material* m_TextDecodeCharacters;		// 0x0040
		Material* m_TextDecodeCharactersGlow;	// 0x0048
		GfxFont* m_BigFont;						// 0x0050
		GfxFont* m_SmallFont;					// 0x0058
		GfxFont* m_ConsoleFont;					// 0x0060
		GfxFont* m_BoldFont;					// 0x0068
		GfxFont* m_TextFont;					// 0x0070
		GfxFont* m_ExtraBigFont;				// 0x0078
		GfxFont* m_ObjectiveFont;				// 0x0080
		GfxFont* m_HudBigFont;					// 0x0088
		GfxFont* m_HudSmallFont;				// 0x0090
		GfxFont* m_SubtitleFont;				// 0x0098
		GfxFont* m_BigNotoFont;					// 0x00A0
	};
	ENGINE_ASSERT_SZ(CachedAssets_t, 0x00A8);
}
