#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Spawner.hpp"

namespace IW8 {
	class SpawnerList {
	public:
		std::uint32_t m_SpawnerCount;	// 0x0000
	private:
		char pad_0004[0x0004];			// 0x0004
	public:
		Spawner* m_SpawnerList;			// 0x0008
	};
	ENGINE_ASSERT_SZ(SpawnerList, 0x0010);
}
