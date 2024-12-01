#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	union DvarLimits {
		struct _enumeration {
			int m_StringCount;		// 0x0000
		private:
			char pad_0004[0x0004];	// 0x0004
		public:
			const char** m_Strings;	// 0x0008
		} m_Enumeration;
		struct _integer {
			int m_Min;				// 0x0000
			int m_Max;				// 0x0004
		} m_Integer;
		struct _integer64 {
			std::int64_t m_Min;		// 0x0000
			std::int64_t m_Max;		// 0x0008
		} m_Integer64;
		struct _unsignedInt64 {
			std::uint64_t m_Min;	// 0x0000
			std::uint64_t m_Max;	// 0x0008
		} m_UnsignedInt64;
		struct _value {
			float m_Min;			// 0x0000
			float m_Max;			// 0x0004
			float m_DevGuiStep;		// 0x0008
		} m_Value;
		struct _vector {
			float m_Min;			// 0x0000
			float m_Max;			// 0x0004
			float m_DevGuiStep;		// 0x0008
		} m_Vector;
	};
	ENGINE_ASSERT_SZ(DvarLimits, 0x0010);
}
