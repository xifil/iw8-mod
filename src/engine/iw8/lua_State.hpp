#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GCRef.hpp"
#include "engine/iw8/MRef.hpp"
#include "engine/iw8/TValue.hpp"

namespace IW8 {
	class lua_State {
	public:
		GCRef m_NextGC;				// 0x0000
		std::uint8_t m_Marked;		// 0x0008
		std::uint8_t m_GCT;			// 0x0009
		std::uint8_t m_DummyFFID;	// 0x000A
		std::uint8_t m_Status;		// 0x000B
	private:
		char pad_000C[0x0004];		// 0x000C
	public:
		MRef m_GLRef;				// 0x0010
		GCRef m_GCList;				// 0x0018
		TValue* m_Base;				// 0x0020
		TValue* m_Top;				// 0x0028
		MRef m_MaxStack;			// 0x0030
		MRef m_Stack;				// 0x0038
		GCRef m_OpenUpVal;			// 0x0040
		GCRef m_Env;				// 0x0048
		void* m_CFrame;				// 0x0050
		std::uint32_t m_StackSize;	// 0x0058
	private:
		char pad_005C[0x0004];		// 0x005C
	};
	ENGINE_ASSERT_SZ(lua_State, 0x0060);
}
