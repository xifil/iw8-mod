#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImageAtlasInfo.hpp"
#include "engine/iw8/GfxImageFallback.hpp"
#include "engine/iw8/GfxImagePixels.hpp"
#include "engine/iw8/GfxImageSemanticSpecific.hpp"
#include "engine/iw8/GfxImageStreamData.hpp"
#include "engine/iw8/enums/GfxImageCategory.hpp"
#include "engine/iw8/enums/GfxImageFlags.hpp"
#include "engine/iw8/enums/GfxPixelFormat.hpp"
#include "engine/iw8/enums/GfxTextureId.hpp"
#include "engine/iw8/enums/TextureSemantic.hpp"

namespace IW8 {
	class GfxImage {
	public:
		const char* m_Name;								// 0x0000
		std::uint8_t* m_PackedAtlasData;				// 0x0008
		GfxTextureId m_TextureId;						// 0x0010
		GfxPixelFormat m_Format;						// 0x0014
		GfxImageFlags m_Flags;							// 0x0018
		std::uint32_t m_TotalSize;						// 0x001C
		GfxImageSemanticSpecific m_SemanticSpecific;	// 0x0020
		std::uint16_t m_Width;							// 0x0024
		std::uint16_t m_Height;							// 0x0026
		std::uint16_t m_Depth;							// 0x0028
		std::uint16_t m_NumElements;					// 0x002A
		GfxImageAtlasInfo m_AtlasInfo;					// 0x002C
		TextureSemantic m_Semantic;						// 0x002E
		GfxImageCategory m_Category;					// 0x002F
		std::uint8_t m_LevelCount;						// 0x0030
		std::uint8_t m_StreamedPartCount;				// 0x0031
		std::uint8_t m_DecalAtlasIndex;					// 0x0032
		char m_FreqDomainMetricBias;					// 0x0033
	private:
		char pad_0034[0x0004];							// 0x0034
	public:
		GfxImageStreamData m_Streams[4];				// 0x0038
		GfxImageFallback* m_Fallback;					// 0x00D8
		GfxImagePixels m_Pixels;						// 0x00E0
	};
	ENGINE_ASSERT_SZ(GfxImage, 0x00E8);
}
