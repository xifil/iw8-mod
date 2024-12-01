#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class SplinePointEntityRecord {
	public:
		int m_SplineId;					// 0x0000
		int m_SplineNodeId;				// 0x0004
		scr_string_t m_SplineNodeLabel;	// 0x0008
		scr_string_t m_TargetName;		// 0x000C
		scr_string_t m_Target;			// 0x0010
		scr_string_t m_String;			// 0x0014
		float m_Speed;					// 0x0018
		float m_SplineNodeTension;		// 0x001C
		vec3_t m_Origin;				// 0x0020
		vec3_t m_Angles;				// 0x002C
		float m_Throttle;				// 0x0038
		vec2_t m_CorridorDims;			// 0x003C
		vec3_t m_Tangent;				// 0x0044
		float m_DistToNextNode;			// 0x0050
		vec3_t m_PositionCubic[4];		// 0x0054
		vec3_t m_TangentQuadratic[3];	// 0x0084
	};
	ENGINE_ASSERT_SZ(SplinePointEntityRecord, 0x00A8);
}
