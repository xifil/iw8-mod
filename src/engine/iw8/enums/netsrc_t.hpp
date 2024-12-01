#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class netsrc_t : int {
		NS_CLIENT1 = 0x0,
		NS_CLIENT2 = 0x1,
		NS_MAXCLIENTS = 0x2,
		NS_SERVER = 0x2,
		NS_PACKET = 0x3,
		NS_BOT_FIRST = 0x4,
		NS_BOT_LAST = 0x2713,
		NS_INVALID_NETSRC = 0x2714
	};
}
