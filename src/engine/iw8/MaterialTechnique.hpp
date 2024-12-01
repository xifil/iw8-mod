#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxStateBits.hpp"
#include "engine/iw8/MaterialPipelineState.hpp"
#include "engine/iw8/MaterialRenderTargetFormat.hpp"
#include "engine/iw8/MaterialShaderArgument.hpp"
#include "engine/iw8/enums/MaterialConstantLayout.hpp"
#include "engine/iw8/enums/MaterialStageConfig.hpp"
#include "engine/iw8/enums/MaterialTechniqueType.hpp"

namespace IW8 {
	class MaterialTechnique {
	public:
		const char* m_Name;									// 0x0000
		MaterialTechniqueType m_Type;						// 0x0008
		std::uint16_t m_Flags;								// 0x000C
		std::uint8_t m_PipelineStateInputLayoutCount;		// 0x000E
		std::uint8_t m_PipelineStateMap[26];				// 0x000F
	private:
		char pad_0029[0x0007];								// 0x0029
	public:
		MaterialPipelineState* m_PipelineStates;			// 0x0030
		std::uint8_t m_PerPrimArgCount;						// 0x0038
		std::uint8_t m_PerObjArgCount;						// 0x0039
		std::uint8_t m_StableArgCount;						// 0x003A
		std::uint8_t m_NeverArgCount;						// 0x003B
		std::uint16_t m_PerPrimArgSize;						// 0x003C
		std::uint16_t m_PerObjArgSize;						// 0x003E
		std::uint16_t m_StableArgSize;						// 0x0040
		std::uint8_t m_ColorRTCount;						// 0x0042
		MaterialRenderTargetFormat m_RenderTargetFormats;	// 0x0043
		std::uint64_t m_CustomBufferFlags;					// 0x0048
		std::uint32_t m_CustomSamplerFlags;					// 0x0050
		MaterialConstantLayout m_PrecompiledIndex;			// 0x0054
		MaterialStageConfig m_StageConfig;					// 0x0055
	private:
		char pad_0056[0x0002];								// 0x0056
	public:
		GfxStateBits m_StateBits;							// 0x0058
		MaterialShaderArgument* m_Args;						// 0x0068
	};
	ENGINE_ASSERT_SZ(MaterialTechnique, 0x0070);
}
