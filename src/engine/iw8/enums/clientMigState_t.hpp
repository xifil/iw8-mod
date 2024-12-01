#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class clientMigState_t : int {
		CMSTATE_INACTIVE = 0x0,
		CMSTATE_OLDHOSTLEAVING = 0x1,
		CMSTATE_LIMBO = 0x2,
		CMSTATE_NEWHOSTCONNECT = 0x3,
		CMSTATE_COUNT = 0x4
	};
}
