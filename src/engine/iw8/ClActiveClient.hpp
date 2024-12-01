#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ClInputSequenceState.hpp"
#include "engine/iw8/ClInputSequenceVirtualAxisKeyState.hpp"
#include "engine/iw8/usercmd_s.hpp"
#include "engine/iw8/HeldStanceInputStack.hpp"
#include "engine/iw8/SecureCLViewangles.hpp"
#include "engine/iw8/SecureCmdNumber.hpp"
#include "engine/iw8/TurnRateCapInfo.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/Weapon.hpp"
#include "engine/iw8/enums/FreeMoveType.hpp"
#include "engine/iw8/enums/LocalClientNum_t.hpp"
#include "engine/iw8/enums/StanceState.hpp"
#include "engine/iw8/enums/UserCommandStateFlags.hpp"

namespace IW8 {
	class ClActiveClient {
	public:
		virtual ~ClActiveClient() = 0;
		virtual const void* /* playerState_s* */ GetPlayerStateC() = 0;
		virtual void* /* playerState_s* */ GetPlayerState() = 0;
		virtual void Pause() = 0;
		virtual void ExecBinding(int, int, int) = 0;
		virtual void ToggleSpecKeyboard(int) = 0;
		virtual void SpecNextKeyboard(int) = 0;
		virtual void SpecPrevKeyboard(int) = 0;
		virtual bool TranslateButton(int, int) = 0;
		virtual int GetServerTime() = 0;
		virtual int GetHudMsgCharHeight() = 0;
		virtual int GetMsgWindowDriftTime() = 0;
		virtual bool ShouldDisplayMsgWindow() = 0;
		virtual void SendUserInfo() = 0;
		virtual bool IsValidRemoteInputState() = 0;
		virtual FreeMoveType GetFreeMoveType() = 0;
		virtual void UpdateCommandTime(const std::uint64_t) = 0;
		virtual void ResetParseInfoMyChanges() = 0;

		bool m_UsingAds;												// 0x0008
		bool m_HoldingBreath;											// 0x0009
		bool m_WasHoldingBreath;										// 0x000A
		bool m_IsRemoteControlling;										// 0x000B
		bool m_AutoForward;												// 0x000C
	private:
		char pad_000D[0x0003];											// 0x000D
	public:
		int m_MouseDX[2];												// 0x0010
		int m_MouseDY[2];												// 0x0018
		float m_WeightedDX[8];											// 0x0020
		float m_WeightedDY[8];											// 0x0040
		int m_MouseWheelDelta;											// 0x0060
		float m_MouseWheelDeltaSustainTime;								// 0x0064
		int m_MouseIndex;												// 0x0068
		bool m_StanceHeld;												// 0x006C
		bool m_CrouchToggle;											// 0x006D
		bool m_CrouchHoldPressed;										// 0x006E
		bool m_CrouchHoldReleased;										// 0x006F
		bool m_IgnoreStanceInput;										// 0x0070
		bool m_WasSprinting;											// 0x0071
		bool m_RequireSlideRelease;										// 0x0072
		bool m_StandToProne;											// 0x0073
		HeldStanceInputStack m_HeldInputs;								// 0x0074
		bool m_WeaponForwardHoldStartedInAds;							// 0x0080
	private:
		char pad_0081[0x0003];											// 0x0081
	public:
		StanceState m_Stance;											// 0x0084
		StanceState m_StanceOnButtonDown;								// 0x0088
		int m_StanceTime;												// 0x008C
		Weapon m_CGameUserCmdWeapon;									// 0x0090
		Weapon m_CGameUserCmdOffHand;									// 0x00CC
		int m_CGameUserCmdAlternate;									// 0x0108
		float m_CGameFOVSensitivityScale;								// 0x010C
		std::uint64_t m_CGameExtraButtons;								// 0x0110
		int m_CGameMountRegisterTime;									// 0x0118
		UserCommandStateFlags m_CGameUserCmdStateFlags;					// 0x011C
		TurnRateCapInfo m_TurnRateCapInfos[5];							// 0x0120
		ClInputSequenceState m_CmdSequenceState[7];						// 0x0148
		ClInputSequenceVirtualAxisKeyState m_CmdSequenceAxisKeys[5];	// 0x0180
		bool m_IsDoubleAdsMountHeld;									// 0x01A8
		bool m_TriggerSuperSprint;										// 0x01A9
		bool m_DetonateOffhandPrimary;									// 0x01AA
		bool m_DetonateOffhandSecondary;								// 0x01AB
		SecureCLViewangles m_ClViewAngles;								// 0x01AC
		int m_CmdInputAccumTimeMs;										// 0x01B8
		vec3_t m_MouseViewDelta;										// 0x01BC
		vec2_t m_AccumulatedMouseDelta;									// 0x01C8
		int m_AccumulatedInputTimer;									// 0x01D0
	private:
		char pad_01D4[0x0004];											// 0x01D4
	public:
		usercmd_s m_Cmds[128];											// 0x01D8
		SecureCmdNumber m_CmdNumber;									// 0x85D8
	private:
		char pad_85DC[0x0004];											// 0x85DC
	public:
		std::uint64_t m_CmdAccumTimeUsec;								// 0x85E0
		std::uint64_t m_CmdTimeUsec;									// 0x85E8
		int m_CmdTimeMsec;												// 0x85F0
	private:
		char pad_85F4[0x0004];											// 0x85F4
	public:
		usercmd_s m_ExtrapCmd;											// 0x85F8
		int m_LatencyDeviceState;										// 0x8700
		std::uint32_t m_CmdNumberAab;									// 0x8704
		std::uint32_t m_CmdNumberSetAab;								// 0x8708
		std::uint32_t m_ClViewAnglesAab;								// 0x870C
		std::uint32_t m_ClViewAnglesSetAab;								// 0x8710
		bool m_MustNotActivatePing;										// 0x8714
	private:
		char pad_8715[0x0003];											// 0x8715
	public:
		LocalClientNum_t m_LocalClientNum;								// 0x8718
	private:
		char pad_871C[0x0004];											// 0x871C
	};
}
