#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsAssetUsageCounter {
	public:
		int m_ServerEnt;	// 0x0000
		int m_ClientEnt;	// 0x0004
		int m_DynEnt;		// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsAssetUsageCounter, 0x000C);
}
