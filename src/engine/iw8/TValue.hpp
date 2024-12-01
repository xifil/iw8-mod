#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GCRef.hpp"

namespace IW8 {
	union TValue {
		std::uint64_t m_U64;	// 0x0000
		long double m_N;		// 0x0000
		GCRef m_GCR;			// 0x0000
		std::int64_t m_It64;	// 0x0000
		struct {
			int m_I;			// 0x0000
			std::uint32_t m_It;	// 0x0004
		};
		std::int64_t m_Ftsz;	// 0x0000
		struct {
			std::uint32_t m_Lo;	// 0x0000
			std::uint32_t m_Hi;	// 0x0004
		} m_U32;
	};
	ENGINE_ASSERT_SZ(TValue, 0x0008);
}
