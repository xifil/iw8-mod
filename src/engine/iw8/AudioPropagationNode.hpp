#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class AudioPropagationNode {
	public:
		vec3_t m_Position;				// 0x0000
		std::uint16_t m_NumEdges;		// 0x000C
	private:
		char pad_000E[0x0002];			// 0x000E
	public:
		std::uint32_t m_EdgeStartIndex;	// 0x0010
	};
	ENGINE_ASSERT_SZ(AudioPropagationNode, 0x0014);
}
