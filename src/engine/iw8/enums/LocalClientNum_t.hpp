#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class LocalClientNum_t : int {
		LOCAL_CLIENT_INVALID = -1,
		LOCAL_CLIENT_0 = 0,
		LOCAL_CLIENT_1 = 1,
		LOCAL_CLIENT_LAST = 1,
		LOCAL_CLIENT_COUNT = 2
	};
}
