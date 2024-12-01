#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec2_t.hpp"

namespace IW8 {
	class ScreenPlacement {
	public:
		vec2_t m_ScaleVirtualToReal;	// 0x0000
		vec2_t m_ScaleVirtualToFull;	// 0x0008
		vec2_t m_ScaleRealToVirtual;	// 0x0010
		vec2_t m_RealViewportPosition;	// 0x0018
		vec2_t m_RealViewportSize;		// 0x0020
		vec2_t m_VirtualViewableMin;	// 0x0028
		vec2_t m_VirtualViewableMax;	// 0x0030
		vec2_t m_RealViewableMin;		// 0x0038
		vec2_t m_RealViewableMax;		// 0x0040
		vec2_t m_VirtualAdjustableMin;	// 0x0048
		vec2_t m_VirtualAdjustableMax;	// 0x0050
		vec2_t m_RealAdjustableMin;		// 0x0058
		vec2_t m_RealAdjustableMax;		// 0x0060
		float m_SubScreenLeft;			// 0x0068
	};
	ENGINE_ASSERT_SZ(ScreenPlacement, 0x006C);
}
