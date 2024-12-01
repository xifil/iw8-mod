#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SplinePointEntityRecord.hpp"

namespace IW8 {
	class SplinePointRecordList {
	public:
		std::uint16_t m_SplinePointCount;			// 0x0000
	private:
		char pad_0002[0x0002];						// 0x0002
	public:
		float m_SplineLength;						// 0x0004
		SplinePointEntityRecord* m_SplinePoints;	// 0x0008
	};
	ENGINE_ASSERT_SZ(SplinePointRecordList, 0x0010);
}
