#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec4_t.hpp"

namespace IW8 {
	union DvarValue {
		bool m_Enabled;					// 0x0000
		int m_Integer;					// 0x0000
		std::uint32_t m_UnsignedInt;	// 0x0000
		std::int64_t m_Integer64;		// 0x0000
		std::uint64_t m_UnsignedInt64;	// 0x0000
		float m_Value;					// 0x0000
		vec4_t m_Vector;				// 0x0000
		const char* m_String;			// 0x0000
		std::uint8_t m_Color[4];		// 0x0000
	};
	ENGINE_ASSERT_SZ(DvarValue, 0x0010);
}
