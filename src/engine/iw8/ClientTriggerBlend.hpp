#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ClientTriggerBlendNode.hpp"

namespace IW8 {
	class ClientTriggerBlend {
	public:
		std::uint16_t m_NumClientTriggerBlendNodes;	// 0x0000
	private:
		char pad_0002[0x0006];						// 0x0002
	public:
		ClientTriggerBlendNode* m_BlendNodes;		// 0x0008
	};
	ENGINE_ASSERT_SZ(ClientTriggerBlend, 0x0010);
}
