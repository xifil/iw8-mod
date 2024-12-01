#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DvarValue.hpp"

namespace IW8 {
	class BbConstUsageFlags {
	public:
		bool m_Initialized;		// 0x0000
	private:
		char pad_0001[0x0007];	// 0x0001
	public:
		DvarValue m_CodeValue;	// 0x0008
	};
	ENGINE_ASSERT_SZ(BbConstUsageFlags, 0x0018);
}
