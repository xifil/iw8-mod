#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AmbientEvent {
	public:
		std::uint32_t m_ID;						// 0x0000
		std::uint16_t m_AmbientElementIndex;	// 0x0004
	private:
		char pad_0006[0x0002];					// 0x0006
	public:
		float m_Weight;							// 0x0008
	};
	ENGINE_ASSERT_SZ(AmbientEvent, 0x000C);
}
