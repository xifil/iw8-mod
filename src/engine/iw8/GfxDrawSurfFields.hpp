#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class GfxDrawSurfFields {
	public:
		std::uint64_t m_IndirectArgsOffset : 10;	// 0x0000
		std::uint64_t m_GPBatchIndex : 16;			// 0x0000
		std::uint64_t m_ObjectId : 24;				// 0x0000
		std::uint64_t m_HasGfxEntIndex : 1;			// 0x0000
		std::uint64_t m_LightmapIndex : 9;			// 0x0000
		std::uint64_t m_ShadowCaster : 1;			// 0x0000
		std::uint64_t m_MaterialSortedIndex : 16;	// 0x0008
		std::uint64_t m_Tessellation : 3;			// 0x0008
		std::uint64_t m_PrePass : 2;				// 0x0008
		std::uint64_t m_ViewModelRender : 1;		// 0x0008
		std::uint64_t m_LowResShading : 1;			// 0x0008
		std::uint64_t m_SurfType : 4;				// 0x0008
		std::uint64_t m_PrimarySortKey : 6;			// 0x0008
	};
	ENGINE_ASSERT_SZ(GfxDrawSurfFields, 0x0010);
}
