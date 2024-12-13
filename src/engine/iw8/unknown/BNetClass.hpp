#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class BNetClass {
	public:
		int m_State;				// 0x0000
	private:
		char pad_0004[0x02CC];	// 0x0004
	public:
		bool m_FinishedAuth;			// 0x02D0
	private:
		char pad_02D1[0x0023];	// 0x02D1
	public:
		int m_Var3;				// 0x02F4
		char m_Var4;			// 0x02F8
	private:
		char pad_02F9[0x0003];	// 0x02F9
	public:
		int m_Var5;				// 0x02FC
	};
	ENGINE_ASSERT_SZ(BNetClass, 0x0300);
}
