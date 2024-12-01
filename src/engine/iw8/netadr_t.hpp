#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/netadrtype_t.hpp"
#include "engine/iw8/enums/netsrc_t.hpp"

namespace IW8 {
	class netadr_t {
	public:
		netadrtype_t m_Type;	// 0x0000
		std::uint8_t m_IP[4];	// 0x0004
		std::uint16_t m_Port;	// 0x0008
		std::uint16_t m_Flags;	// 0x000A
		netsrc_t m_LocalNetID;	// 0x000C
		int m_AddrHandleIndex;	// 0x0010
	};
	ENGINE_ASSERT_SZ(netadr_t, 0x0014);
}
