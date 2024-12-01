#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class TextureSemantic : std::int8_t {
		TS_2D = 0x0,
		TS_FUNCTION = 0x1,
		TS_COLOR_MAP = 0x2,
		TS_GRAY_MAP = 0x3,
		TS_SIGNED_VELOCITY_MAP = 0x4,
		TS_NORMAL_MAP = 0x5,
		TS_METALNESS_MAP = 0x6,
		TS_NORMAL_OCCLUSION_GLOSS_MAP = 0x7,
		TS_SIGNED_DISTANCE_FIELD = 0x8,
		TS_CARD_IMPOSTER_NORMAL = 0x9,
		TS_COUNT = 0xA
	};
}
