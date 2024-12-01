#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/OmnvarValue.hpp"
#include "engine/iw8/enums/OmnvarType.hpp"
#include "engine/iw8/enums/OmnvarUserType.hpp"

namespace IW8 {
	class OmnvarDef {
	public:
		const char* m_Name;			// 0x0000
		const char* m_NCSString;	// 0x0008
		int m_PMoveIndex;			// 0x0010
		int m_MinValue;				// 0x0014
		int m_MaxValue;				// 0x0018
		OmnvarValue m_Initial;		// 0x001C
		std::uint8_t m_NumBits;		// 0x0020
		std::uint8_t m_Flags;		// 0x0021
		OmnvarType m_Type;			// 0x0022
		OmnvarUserType m_UserType;	// 0x0023
	private:
		char pad_0024[0x0004];		// 0x0024
	};
	ENGINE_ASSERT_SZ(OmnvarDef, 0x0028);
}
