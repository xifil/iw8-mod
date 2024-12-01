#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class netadrtype_t : int {
		NA_BAD = 0x0,
		NA_LOOPBACK = 0x1,
		NA_BROADCAST = 0x2,
		NA_IP = 0x3,
		NA_RAW = 0x4
	};
}
