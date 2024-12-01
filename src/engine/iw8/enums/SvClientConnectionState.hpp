#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class SvClientConnectionState : std::int8_t {
		CS_FREE = 0x0,
		CS_ZOMBIE = 0x1,
		CS_RECONNECTING = 0x2,
		CS_CONNECTED = 0x3,
		CS_CLIENTLOADING = 0x4,
		CS_ACTIVE = 0x5
	};
}
