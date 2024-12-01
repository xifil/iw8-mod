#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ADSRSetting.hpp"
#include "engine/iw8/AdsrZoneEntry.hpp"
#include "engine/iw8/AmbientDef.hpp"
#include "engine/iw8/AmbientElement.hpp"
#include "engine/iw8/AmbientEvent.hpp"
#include "engine/iw8/FilterDef.hpp"
#include "engine/iw8/FullOcclusionDef.hpp"
#include "engine/iw8/MixDef.hpp"
#include "engine/iw8/OccludeDef.hpp"
#include "engine/iw8/PlayerBreathStateDef.hpp"
#include "engine/iw8/ReverbDef.hpp"
#include "engine/iw8/TimescaleEntry.hpp"
#include "engine/iw8/ZoneDef.hpp"

namespace IW8 {
	class SoundTable {
	public:
		std::uint32_t m_ID;							// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		ADSRSetting* m_ADSRSettings;				// 0x0008
		std::uint32_t m_ADSRCount;					// 0x0010
	private:
		char pad_0014[0x0004];						// 0x0014
	public:
		AmbientDef* m_AmbientDefs;					// 0x0018
		std::uint32_t m_AmbientDefCount;			// 0x0020
	private:
		char pad_0024[0x0004];						// 0x0024
	public:
		AmbientEvent* m_AmbientEvents;				// 0x0028
		std::uint32_t m_AmbientEventCount;			// 0x0030
	private:
		char pad_0034[0x0004];						// 0x0034
	public:
		AmbientElement* m_AmbientElements;			// 0x0038
		std::uint32_t m_AmbientElementsCount;		// 0x0040
	private:
		char pad_0044[0x0004];						// 0x0044
	public:
		FilterDef* m_Filters;						// 0x0048
		std::uint32_t m_FilterCount;				// 0x0050
	private:
		char pad_0054[0x0004];						// 0x0054
	public:
		MixDef* m_Mixes;							// 0x0058
		std::uint32_t m_MixCount;					// 0x0060
	private:
		char pad_0064[0x0004];						// 0x0064
	public:
		AdsrZoneEntry* m_NPCADSRZones;				// 0x0068
		std::uint32_t m_NPCADSRZoneCount;			// 0x0070
	private:
		char pad_0074[0x0004];						// 0x0074
	public:
		OccludeDef* m_OcclusionFilters;				// 0x0078
		std::uint32_t m_OcclusionFilterCount;		// 0x0080
	private:
		char pad_0084[0x0004];						// 0x0084
	public:
		AdsrZoneEntry* m_PlayerADSRZones;			// 0x0088
		std::uint32_t m_PlayerADSRZoneCount;		// 0x0090
	private:
		char pad_0094[0x0004];						// 0x0094
	public:
		ReverbDef* m_Reverbs;						// 0x0098
		std::uint32_t m_ReverbCount;				// 0x00A0
	private:
		char pad_00A4[0x0004];						// 0x00A4
	public:
		TimescaleEntry* m_TimeScaleSettings;		// 0x00A8
		std::uint32_t m_TimeScaleSettingCount;		// 0x00B0
	private:
		char pad_00B4[0x0004];						// 0x00B4
	public:
		ZoneDef* m_Zones;							// 0x00B8
		std::uint32_t m_ZoneCount;					// 0x00C0
	private:
		char pad_00C4[0x0004];						// 0x00C4
	public:
		FullOcclusionDef* m_FullOcclusionDefs;		// 0x00C8
		std::uint32_t m_FullOcclusionDefCount;		// 0x00D0
	private:
		char pad_00D4[0x0004];						// 0x00D4
	public:
		PlayerBreathStateDef* m_PlrBreathStateDefs;	// 0x00D8
		std::uint32_t m_PlrBreathStateDefCount;		// 0x00E0
	private:
		char pad_00E4[0x0004];						// 0x00E4
	};
	ENGINE_ASSERT_SZ(SoundTable, 0x00E8);
}
