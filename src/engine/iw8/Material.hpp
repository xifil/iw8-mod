#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxDecalVolumeMaterial.hpp"
#include "engine/iw8/GfxDrawSurf.hpp"
#include "engine/iw8/MaterialConstantBufferDef.hpp"
#include "engine/iw8/MaterialConstantDef.hpp"
#include "engine/iw8/MaterialTechniqueSet.hpp"
#include "engine/iw8/MaterialTextureDef.hpp"

namespace IW8 {
	class Material {
	public:
		const char* m_Name;									// 0x0000
		std::uint32_t m_Contents;							// 0x0008
		std::uint32_t m_SurfaceFlags;						// 0x000C
		float m_MaxDisplacement;							// 0x0010
		MaterialGeometryType m_MaterialType;				// 0x0014
		std::uint8_t m_CameraRegion;						// 0x0018
		std::uint8_t m_SortKey;								// 0x0019
		union {
			std::uint16_t m_RuntimeFlags;					// 0x001A
			std::uint16_t m_Flags;							// 0x001A
		};
		std::uint8_t m_TextureCount;						// 0x001C
		std::uint8_t m_ConstantCount;						// 0x001D
		std::uint8_t m_ConstantBufferCount;					// 0x001E
		std::uint8_t m_LayerCount;							// 0x001F
		std::uint16_t m_PackedAtlasDataSize;				// 0x0020
		std::uint8_t m_TextureAtlasRowCount;				// 0x0022
		std::uint8_t m_TextureAtlasColumnCount;				// 0x0023
	private:
		char pad_0024[0x0004];								// 0x0024
	public:
		GfxDrawSurf m_DrawSurf;								// 0x0028
		std::uint8_t* m_PackedAtlasData;					// 0x0038
		MaterialTechniqueSet* m_TechniqueSet;				// 0x0040
		MaterialTextureDef* m_TextureTable;					// 0x0048
		MaterialConstantDef* m_ConstantTable;				// 0x0050
		GfxDecalVolumeMaterial* m_DecalVolumeMaterial;		// 0x0058
		std::uint8_t* m_ConstantBufferIndex;				// 0x0060
		MaterialConstantBufferDef* m_ConstantBufferTable;	// 0x0068
		const char** m_SubMaterials;						// 0x0070
	};
	ENGINE_ASSERT_SZ(Material, 0x0078);
}
