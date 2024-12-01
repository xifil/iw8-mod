#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/base_vec3_t.hpp"
#include "engine/iw8/LightSample.hpp"
#include "engine/iw8/UserCmdClientBits.hpp"
#include "engine/iw8/Weapon.hpp"
#include "engine/iw8/enums/UserCommandStateFlags.hpp"

namespace IW8 {
	class usercmd_s {
	public:
		std::uint64_t m_Buttons;				// 0x0000
		UserCommandStateFlags m_StateFlags;		// 0x0008
		int m_ServerTime;						// 0x000C
		int m_CommandTime;						// 0x0010
		int m_InputTime;						// 0x0014
		base_vec3_t<int> m_Angles;				// 0x0018
		Weapon m_Weapon;						// 0x0024
		Weapon m_OffHand;						// 0x0060
		char m_ForwardMove;						// 0x009C
		char m_RightMove;						// 0x009D
		char m_PitchMove;						// 0x009E
		char m_YawMove;							// 0x009F
		std::uint16_t m_MeleeChargeEnt;			// 0x00A0
		std::uint8_t m_PackedControllerAim;		// 0x00A2
		char m_SelectedLoc[2];					// 0x00A3
		char m_SelectedAngle;					// 0x00A5
		char m_RemoteControlAngles[2];			// 0x00A6
		char m_RemoteControlMove[3];			// 0x00A8
		char m_MLGSelectedLoc[2];				// 0x00AB
		char m_MLGSelectedAngle;				// 0x00AD
		LightSample m_LightSample;				// 0x00AE
		std::int16_t m_AvoidForward;			// 0x00B0
		std::int16_t m_AvoidRight;				// 0x00B2
		std::uint8_t m_UpMove;					// 0x00B4
		std::uint8_t m_DownMove;				// 0x00B5
		bool m_InputFromGamepad;				// 0x00B6
		bool m_IsAlternate;						// 0x00B7
		std::int16_t m_VehAngles[3];			// 0x00B8
	private:
		char pad_00BE[0x0002];					// 0x00BE
	public:
		float m_VehOrgX;						// 0x00C0
		float m_VehOrgY;						// 0x00C4
		float m_VehOrgZ;						// 0x00C8
		float m_GunPitch;						// 0x00CC
		float m_GunYaw;							// 0x00D0
		float m_GunXOfs;						// 0x00D4
		float m_GunYOfs;						// 0x00D8
		float m_GunZOfs;						// 0x00DC
		float m_RollSensitivity;				// 0x00E0
		std::int16_t m_ScriptedMeleeTarget;		// 0x00E4
		std::uint16_t m_AirburstMarkDistance;	// 0x00E6
		UserCmdClientBits m_SightedClientsMask;	// 0x00E8
		std::uint16_t m_ExtrapolationMax;		// 0x0104
		std::uint16_t m_InterpolationMax;		// 0x0106
	};
	ENGINE_ASSERT_SZ(usercmd_s, 0x0108);
}
