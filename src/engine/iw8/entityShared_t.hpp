#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"
#include "engine/iw8/EntHandle.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class entityShared_t {
	public:
		std::uint8_t m_IsLinked;		// 0x0000
		std::uint8_t m_ModelType;		// 0x0001
		std::uint8_t m_SvFlags;			// 0x0002
		std::uint8_t m_EventTypeFlags;	// 0x0003
		std::uint8_t m_IsInUse;			// 0x0004
	private:
		char pad_0005[0x0003];			// 0x0005
	public:
		Bounds m_Box;					// 0x0008
		Bounds m_AbsBox;				// 0x0020
		vec3_t m_CurrentOrigin;			// 0x0038
		vec3_t m_CurrentAngles;			// 0x0044
		EntHandle m_OwnerNum;			// 0x0050
		int m_EventTime;				// 0x0054
	};
	ENGINE_ASSERT_SZ(entityShared_t, 0x0058);
}
