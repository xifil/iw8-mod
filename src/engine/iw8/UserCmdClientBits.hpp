#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class UserCmdClientBits {
	public:
		std::uint32_t m_Data[7];	// 0x0000
	};
	ENGINE_ASSERT_SZ(UserCmdClientBits, 0x001C);
}
