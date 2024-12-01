#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/netadr_t.hpp"
#include "engine/iw8/XNADDR.hpp"
#include "engine/iw8/XSECURITY_INFO.hpp"

namespace IW8 {
	class ClServerInfo {
	public:
		XNADDR m_XNAddr;				// 0x0000
		XSECURITY_INFO m_XNInfo;		// 0x0054
		netadr_t m_Addr;				// 0x006C
		std::uint8_t m_Clients;			// 0x0080
		std::uint8_t m_MaxClients;		// 0x0081
		std::uint8_t m_Dirty;			// 0x0082
		std::uint8_t m_RequestCount;	// 0x0083
		std::int16_t m_MinPing;			// 0x0084
		std::int16_t m_MaxPing;			// 0x0086
		std::int16_t m_Ping;			// 0x0088
		bool m_IsDedicated;				// 0x008A
		std::uint8_t m_IsLobby;			// 0x008B
		char m_HostName[36];			// 0x008C
		char m_MapName[36];				// 0x00B0
		char m_GameType[16];			// 0x00D4
	};
	ENGINE_ASSERT_SZ(ClServerInfo, 0x00E4);
}
