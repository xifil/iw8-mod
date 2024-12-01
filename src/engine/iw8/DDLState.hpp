#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLDef.hpp"
#include "engine/iw8/DDLMember.hpp"

namespace IW8 {
	class DDLState {
	public:
		bool m_IsValid;			// 0x0000
	private:
		char pad_0001[0x0003];	// 0x0001
	public:
		int m_Offset;			// 0x0004
		int m_ArrayIndex;		// 0x0008
	private:
		char pad_000C[0x0004];	// 0x000C
	public:
		DDLMember* m_Member;	// 0x0010
		const DDLDef* m_DDLDef;	// 0x0018
	};
	ENGINE_ASSERT_SZ(DDLState, 0x0020);
}
