#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	union OmnvarValue {
		bool m_Enabled;						// 0x0000
		int m_Integer;						// 0x0000
		std::uint32_t m_UnsignedInteger;	// 0x0000
		float m_Value;						// 0x0000
		std::uint32_t m_NCSString;			// 0x0000
	};
	ENGINE_ASSERT_SZ(OmnvarValue, 0x0004);
}
