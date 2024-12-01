#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SecureCmdNumber {
	public:
		int m_CmdNumber;	// 0x0000
	};
	ENGINE_ASSERT_SZ(SecureCmdNumber, 0x0004);
}
