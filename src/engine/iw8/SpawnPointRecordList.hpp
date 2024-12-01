#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SpawnPointEntityRecord.hpp"

namespace IW8 {
	class SpawnPointRecordList {
	public:
		std::uint16_t m_SpawnsCount;		// 0x0000
	private:
		char pad_0002[0x0006];				// 0x0002
	public:
		SpawnPointEntityRecord* m_Spawns;	// 0x0008
	};
	ENGINE_ASSERT_SZ(SpawnPointRecordList, 0x0010);
}
