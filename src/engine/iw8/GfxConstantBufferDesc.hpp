#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class GfxConstantBufferDesc {
	public:
		void* m_BufferData;			// 0x0000
		std::uint32_t m_BufferSize;	// 0x0008
	private:
		char pad_000C[0x0004];		// 0x0004
	};
	ENGINE_ASSERT_SZ(GfxConstantBufferDesc, 0x0010);
}
