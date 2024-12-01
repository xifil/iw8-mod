#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ScreenBlur.hpp"
#include "engine/iw8/Weapon.hpp"
#include "engine/iw8/enums/StanceState.hpp"

namespace IW8 {
	struct MigrationPers {
		bool m_StanceHeld;					// 0x0000
		bool m_CrouchToggle;				// 0x0001
		bool m_CrouchHoldReleased;			// 0x0002
	private:
		char pad_0003[0x0001];				// 0x0003
	public:
		StanceState m_Stance;				// 0x0004
		StanceState m_StanceOnButtonDown;	// 0x0008
		int m_StanceTime;					// 0x000C
		int m_CmdInputAccumTimeMs;			// 0x0010
		Weapon m_CGameUserCmdWeapon;		// 0x0014
		Weapon m_CGameUserCmdOffHand;		// 0x0050
		int m_CGameUserCmdAlternate;		// 0x008C
		Weapon m_WeaponSelect;				// 0x0090
		int m_WeaponSelectInAlt;			// 0x00CC
		int m_WeaponSelectTime;				// 0x00D0
		int m_WeaponForcedSelectTime;		// 0x00D4
		Weapon m_WeaponLatestPrimary;		// 0x00D8
		Weapon m_WeaponPrevPrimary;			// 0x0114
		int m_HoldBreathTime;				// 0x0150
		int m_HoldBreathDelay;				// 0x0154
		float m_HoldBreathFrac;				// 0x0158
		ScreenBlur m_BlurPers;				// 0x015C
	};
	ENGINE_ASSERT_SZ(MigrationPers, 0x0178);
}
