#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class MaterialStageConfig : std::int8_t {
		MTL_STANDARD_STAGES = 0x0,
		MTL_TESSELLATION_STAGES = 0x1,
		MTL_STAGE_CONFIG_COUNT = 0x2
	};
}
