#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class DynEntityListId : std::int16_t {
		DEFAULT_DYNENTITY_LIST_ID = 0x600,
		DYNENTITY_LIST_ID_INVALID = 0x600,
		DYNENTITY_LIST_ID_UNLOADING = 0x601
	};
}
