#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/GfxBlendStateBits.hpp"
#include "engine/iw8/enums/GfxOtherStateBits.hpp"

namespace IW8 {
	class GfxStateBits {
	public:
		GfxOtherStateBits m_OtherBits;	// 0x0000
		GfxBlendStateBits m_BlendBits;	// 0x0008
	};
	ENGINE_ASSERT_SZ(GfxStateBits, 0x0010);
}
