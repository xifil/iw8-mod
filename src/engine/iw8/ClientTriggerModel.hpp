#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ClientTriggerModel {
	public:
		std::uint16_t m_HullCount;	// 0x0000
	private:
		char pad_0002[0x0002];		// 0x0002
	public:
		std::uint32_t m_FirstHull;	// 0x0004
		std::uint32_t m_Flags;		// 0x0008
	};
	ENGINE_ASSERT_SZ(ClientTriggerModel, 0x000C);
}
