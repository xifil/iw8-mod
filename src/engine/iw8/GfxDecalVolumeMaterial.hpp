#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImage.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class GfxDecalVolumeMaterial {
	public:
		const char* m_Name;								// 0x0000
		GfxImage* m_Channels[6];						// 0x0008
		std::uint32_t m_Flags;							// 0x0038
		vec3_t m_ColorTint;								// 0x003C
		float m_AlphaDissolveParms;						// 0x0048
		float m_EmissiveScale;							// 0x004C
		std::uint32_t m_PackedDisplacementScaleAndBias;	// 0x0050
		float m_DisplacementCutoffDistance;				// 0x0054
		float m_DisplacementCutoffFalloff;				// 0x0058
		std::uint32_t m_PackedTemperatureBaseAndScale;	// 0x005C
		std::uint8_t m_TextureAtlasRowCount;			// 0x0060
		std::uint8_t m_TextureAtlasColumnCount;			// 0x0061
		std::uint8_t m_Padding[6];						// 0x0062
	};
	ENGINE_ASSERT_SZ(GfxDecalVolumeMaterial, 0x0068);
}
