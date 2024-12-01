#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class cmd_function_s {
	public:
		cmd_function_s* m_Next;					// 0x0000
		const char* m_Name;						// 0x0008
		const char** m_AutoCompleteList;		// 0x0010
		unsigned int m_AutoCompleteListCount;	// 0x0018
	private:
		char pad_001C[0x0004];					// 0x001C
	public:
		void(__fastcall* m_Function)();			// 0x0020
	};
	ENGINE_ASSERT_SZ(cmd_function_s, 0x0028);
}
