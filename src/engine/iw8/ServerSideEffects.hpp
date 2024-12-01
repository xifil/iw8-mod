#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ServerExploderDef.hpp"

namespace IW8 {
	class ServerSideEffects {
	public:
		std::uint16_t m_ExploderCount;	// 0x0000
	private:
		char pad_0002[0x0006];			// 0x0002
	public:
		ServerExploderDef* m_Exploders;	// 0x0008
	};
	ENGINE_ASSERT_SZ(ServerSideEffects, 0x0010);
}
