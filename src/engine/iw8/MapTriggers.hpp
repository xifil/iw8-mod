#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/TriggerHull.hpp"
#include "engine/iw8/TriggerModel.hpp"
#include "engine/iw8/TriggerSlab.hpp"
#include "engine/iw8/TriggerWinding.hpp"
#include "engine/iw8/TriggerWindingPoint.hpp"

namespace IW8 {
	class MapTriggers {
	public:
		std::uint32_t m_Count;					// 0x0000
	private:
		char pad_0004[0x0004];					// 0x0004
	public:
		TriggerModel* m_Models;					// 0x0008
		std::uint32_t m_HullCount;				// 0x0010
	private:
		char pad_0014[0x0004];					// 0x0014
	public:
		TriggerHull* m_Hulls;					// 0x0018
		std::uint32_t m_SlabCount;				// 0x0020
	private:
		char pad_0024[0x0004];					// 0x0024
	public:
		TriggerSlab* m_Slabs;					// 0x0028
		std::uint32_t m_WindingCount;			// 0x0030
	private:
		char pad_0034[0x0004];					// 0x0034
	public:
		TriggerWinding* m_Windings;				// 0x0038
		std::uint32_t m_WindingPointCount;		// 0x0040
	private:
		char pad_0044[0x0004];					// 0x0044
	public:
		TriggerWindingPoint* m_WindingPoints;	// 0x0048
	};
	ENGINE_ASSERT_SZ(MapTriggers, 0x0050);
}
