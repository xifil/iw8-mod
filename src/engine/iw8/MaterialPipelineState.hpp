#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/MaterialSerializedShader.hpp"

namespace IW8 {
	class MaterialPipelineState {
	public:
		std::uint32_t m_PacketSize;							// 0x0000
		std::uint32_t m_MetaDataSize;						// 0x0004
		std::uint8_t* m_Packet;								// 0x0008
		std::uint8_t* m_MetaData;							// 0x0010
		MaterialSerializedShader* m_SerializedShaders[4];	// 0x0018
		void* m_SourceShaders[4];							// 0x0038
		ID3D12PipelineState* m_DerivedPSO;					// 0x0058
		ID3D12PipelineState* m_PSO;							// 0x0060
	};
	ENGINE_ASSERT_SZ(MaterialPipelineState, 0x0068);
}
