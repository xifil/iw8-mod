#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetFrequencyEntry;
	class PhysicsVFXEventAssetFrequencyRule {
	public:
		int m_NumEntries;								// 0x0000
	private:
		char pad_0004[0x0004];							// 0x0004
	public:
		PhysicsVFXEventAssetFrequencyEntry* m_Entries;	// 0x0008
	};
}
