#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/BlurPriority.hpp"
#include "engine/iw8/enums/BlurTime.hpp"

namespace IW8 {
	class ScreenBlur {
	public:
		BlurPriority m_Priority;	// 0x0000
		BlurTime m_Time;			// 0x0004
		int m_TimeStart;			// 0x0008
		int m_TimeEnd;				// 0x000C
		float m_Start;				// 0x0010
		float m_End;				// 0x0014
		float m_Radius;				// 0x0018
	};
	ENGINE_ASSERT_SZ(ScreenBlur, 0x001C);
}
