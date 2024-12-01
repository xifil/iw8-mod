#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/bitarray_dynamic.hpp"

namespace IW8 {
	class SpatialPartition_Population_TransientMap {
	public:
		std::uint32_t m_TransientCount;				// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		bitarray_dynamic* m_PartitionsForTransient;	// 0x0008
	};
	ENGINE_ASSERT_SZ(SpatialPartition_Population_TransientMap, 0x0010);
}
