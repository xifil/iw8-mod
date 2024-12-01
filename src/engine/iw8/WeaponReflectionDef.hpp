#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/WeapReflRoomType.hpp"

namespace IW8 {
	class WeaponReflectionDef {
	public:
		const char* m_Name;				// 0x0000
		std::uint32_t m_ID;				// 0x0008
	private:
		char pad_000C[0x0004];			// 0x000C
	public:
		const char* m_WeaponClass;		// 0x0010
		std::uint32_t m_WeaponClassID;	// 0x0018
	private:
		char pad_001C[0x0004];			// 0x001C
	public:
		const char* m_Type;				// 0x0020
		WeapReflRoomType m_ZoneType;	// 0x0028
		float m_ZoneTypeScalar;			// 0x002C
		float m_CloseMedThreshold;		// 0x0030
		float m_MedFarThreshold;		// 0x0034
		float m_FarThreshold;			// 0x0038
		float m_NPCCloseMedThreshold;	// 0x003C
		float m_NPCMedFarThreshold;		// 0x0040
		float m_NPCFarThreshold;		// 0x0044
		float m_SpeedOfSound;			// 0x0048
		float m_MaxPitchClose;			// 0x004C
		float m_PitchDistClose;			// 0x0050
		float m_MaxPitchMed;			// 0x0054
		float m_PitchDistMed;			// 0x0058
		float m_MaxPitchFar;			// 0x005C
		float m_PitchDistFar;			// 0x0060
		float m_NPCMaxPitchMed;			// 0x0064
		float m_NPCPitchDistMed;		// 0x0068
		float m_NPCMaxPitchFar;			// 0x006C
		float m_NPCPitchDistFar;		// 0x0070
		float m_FrontVol;				// 0x0074
		float m_FrontEq;				// 0x0078
		float m_SideVol;				// 0x007C
		float m_SideEq;					// 0x0080
		float m_RearVol;				// 0x0084
		float m_RearEq;					// 0x0088
	private:
		char pad_008C[0x0004];			// 0x008C
	};
	ENGINE_ASSERT_SZ(WeaponReflectionDef, 0x0090);
}
