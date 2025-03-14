#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum ParticleDataFlags : int {
		USE_NONE = 0x0,
		USE_POSITION = 0x1,
		USE_VELOCITY = 0x2,
		USE_COLOR = 0x4,
		USE_ROTATION_ANGLE = 0x8,
		USE_ROTATION_RATE = 0x10,
		USE_SPAWN_POS = 0x20,
		USE_SPAWN_QUAT = 0x40,
		USE_SIZE = 0x80,
		USE_EMISSIVE = 0x100,
		USE_PARENT_VELOCITY = 0x200,
		USE_CHILD_SYSTEM = 0x400,
		USE_SPAWN_TIME = 0x800,
		USE_LIFE = 0x1000,
		USE_STATE = 0x2000,
		USE_RANDOM_SEED = 0x4000,
		USE_FLAGS = 0x8000,
		USE_MODULE_TESTS = 0x10000,
		USE_HANDLE = 0x20000,
		USE_INTENSITY = 0x40000,
		USE_TEMPERATURE = 0x80000,
		USE_CAMERA_DISTANCE = 0x100000,
		USE_INHERIT_PERCENTAGE = 0x200000,
		USE_RAY_CAST_HANDLE = 0x400000,
		USE_ATLAS_INDEX = 0x800000,
		USE_VECTOR_FIELD_SCALE = 0x1000000,
		USE_LIGHTING_FRAC = 0x2000000,
		USE_PREV_PLACEMENT = 0x4000000,
		USE_SHADER_PARAMS = 0x8000000,
		CHECK_FIELD_COUNT = 0x8000001,
		USE_ALL = 0xFFFFFFF,
		USE_BASE = 0x192F8FF,
		USE_EMISSIVE_CURVES = 0x2040100
	};
}
