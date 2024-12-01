#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxConstantBufferDesc.hpp"

namespace IW8 {
	class GfxConstantBuffer : public GfxConstantBufferDesc {
	public:
		ID3D12Resource* m_Buffer;	// 0x0010
	};
	ENGINE_ASSERT_SZ(GfxConstantBuffer, 0x0018);
}
