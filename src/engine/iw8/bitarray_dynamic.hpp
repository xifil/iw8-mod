#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class bitarray_dynamic {
	public:
		std::uint32_t* m_Array;		// 0x0000
		std::uint32_t m_WordCount;	// 0x0008
		std::uint32_t m_BitCount;	// 0x000C
	};
	ENGINE_ASSERT_SZ(bitarray_dynamic, 0x0010);
}
