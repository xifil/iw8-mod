#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SndBank.hpp"

namespace IW8 {
	class SndBankTransient {
	public:
		SndBank m_Bank;	// 0x0000
	};
	ENGINE_ASSERT_SZ(SndBankTransient, 0x0200);
}
