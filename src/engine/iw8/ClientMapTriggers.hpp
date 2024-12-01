#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ClientTriggerHull.hpp"
#include "engine/iw8/ClientTriggerModel.hpp"
#include "engine/iw8/TriggerSlab.hpp"

namespace IW8 {
	class ClientMapTriggers {
		std::uint32_t m_Count;			// 0x0000
	private:
		char pad_0004[0x0004];			// 0x0004
	public:
		ClientTriggerModel* m_Models;	// 0x0008
		std::uint32_t m_HullCount;		// 0x0010
	private:
		char pad_0014[0x0004];			// 0x0014
	public:
		ClientTriggerHull* m_Hulls;		// 0x0018
		std::uint32_t m_SlabCount;		// 0x0020
	private:
		char pad_0024[0x0004];			// 0x0024
	public:
		TriggerSlab* m_Slabs;			// 0x0028
	};
	ENGINE_ASSERT_SZ(ClientMapTriggers, 0x0030);
}
