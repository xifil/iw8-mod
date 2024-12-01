#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SplinePointRecordList.hpp"

namespace IW8 {
	class SplineRecordList {
	public:
		std::uint16_t m_SplineCount;		// 0x0000
	private:
		char pad_0002[0x0006];				// 0x0002
	public:
		SplinePointRecordList* m_Splines;	// 0x0008
	};
	ENGINE_ASSERT_SZ(SplineRecordList, 0x0010);
}
