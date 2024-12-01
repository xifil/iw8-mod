#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/MaterialTechnique.hpp"
#include "engine/iw8/TechniqueMask.hpp"
#include "engine/iw8/enums/MaterialGeometryType.hpp"

namespace IW8 {
	class MaterialTechniqueSet {
	public:
		const char* m_Name;						// 0x0000
		std::uint64_t m_Flags;					// 0x0008
		MaterialGeometryType m_MaterialType;	// 0x0010
	private:
		char pad_0014[0x0004];					// 0x0014
	public:
		TechniqueMask m_TechniqueMask;			// 0x0018
		MaterialTechnique** m_MaskedTechniques;	// 0x0038
	};
	ENGINE_ASSERT_SZ(MaterialTechniqueSet, 0x0040);
}
