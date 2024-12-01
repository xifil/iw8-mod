#include "addr_utils.hpp"
#include "screen.h"
#include "debug_output.h"
#include "engine/iw8/CachedAssets_t.hpp"
#include "engine/iw8/GfxFont.hpp"
#include "functions.hpp"

void CL_ScreenMP_DrawOverlay_Detour() {
	auto DevGui_Draw = reinterpret_cast<void(*)(int)>(0x1417E5CD0_g);
	auto Con_DrawConsole = reinterpret_cast<void(*)(int)>(0x1415AE0B0_g);

	gameInitialized = true;

	Con_DrawConsole(0);
	DevGui_Draw(0);

	if (Dvars::show_watermark->m_Current.m_Enabled) {
		auto R_AddCmdDrawText = reinterpret_cast<void(*)(const char* text, int maxChars, void* font, int fontHeight, float x, float y,
			float xScale, float yScale, float rotation, const float* color)>(0x141965330_g);
		IW8::CachedAssets_t* sharedUiInfo_assets = reinterpret_cast<IW8::CachedAssets_t*>(0x152C46570_g);

		IW8::GfxFont* font = sharedUiInfo_assets->m_SubtitleFont;
		float color[4] = { .666f, .666f, .666f, .666f };
		//CL_DrawText(0x14EF2DEA0_g, "iw8-mod: dev", 0x7FFFFFFF, sharedUiInfo_assets->m_SmallFont, 0.f, 480.f, 1, 1, 1.f, 1.f, color, 7);
		R_AddCmdDrawText("iw8-mod: dev (pt) [" __TIMESTAMP__ "]", 0x7FFFFFFF, font, font->m_PixelHeight,
			4.f, 4.f + static_cast<float>(font->m_PixelHeight), 1.f, 1.f, 0.f, color);
	}
}
