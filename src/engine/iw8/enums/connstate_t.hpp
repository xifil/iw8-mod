#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class connstate_t : int {
		CA_DISCONNECTED = 0x0,
		CA_CONNECTING = 0x1,
		CA_CHALLENGING = 0x2,
		CA_CONNECTED = 0x3,
		CA_SENDINGSTATS = 0x4,
		CA_REQUESTING_MATCH_RULES = 0x5,
		CA_STARTING = 0x6,
		CA_LOADING = 0x7,
		CA_PRIMED = 0x8,
		CA_ACTIVE = 0x9,
		CA_MAP_RESTART = 0xA
	};
}
