#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxConstantBuffer.hpp"

namespace IW8 {
	class MaterialConstantBufferDef {
	public:
		std::uint32_t m_VSDataSize;
		std::uint32_t m_HSDataSize;
		std::uint32_t m_DSDataSize;
		std::uint32_t m_PSDataSize;
		std::uint8_t* m_VSData;
		std::uint8_t* m_HSData;
		std::uint8_t* m_DSData;
		std::uint8_t* m_PSData;
		GfxConstantBuffer m_VSConstantBuffer;
		GfxConstantBuffer m_HSConstantBuffer;
		GfxConstantBuffer m_DSConstantBuffer;
		GfxConstantBuffer m_PSConstantBuffer;
	};
	ENGINE_ASSERT_SZ(MaterialConstantBufferDef, 0x0090);
}
