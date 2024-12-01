#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/EntHandle.hpp"
#include "engine/iw8/entityShared_t.hpp"
#include "engine/iw8/Weapon.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class gentity_s {
	public:
		/*
		entityState_t m_S;																							// 0x0000
		*/
		char m_S[0x00F8];																							// 0x0000
		entityShared_t m_R;																							// 0x00F8
		/*
		gclient_s* m_Client;																						// 0x0150
		*/
		char m_Client[0x0008];																						// 0x0150
		/*
		sentient_s* m_Sentient;																						// 0x0158
		*/
		char m_Sentient[0x0008];																					// 0x0158
		/*
		Vehicle* m_Vehicle;																							// 0x0160
		*/
		char m_Vehicle[0x0008];																						// 0x0160
		/*
		gagent_s* m_Agent;																							// 0x0168
		*/
		char m_Agent[0x0008];																						// 0x0168
		/*
		actor_s* m_Actor;																							// 0x0170
		*/
		char m_Actor[0x0008];																						// 0x0170
		/*
		BgObjectHandle<GTurret> m_TurretHandle;																		// 0x0178
		*/
		char m_TurretHandle[0x0004];																				// 0x0178
		scr_string_t m_ClassName;																					// 0x017C
		scr_string_t m_ScriptClassNme;																				// 0x0180
		scr_string_t m_ScriptLinkName;																				// 0x0184
		scr_string_t m_ScriptLinkTo;																				// 0x0188
		scr_string_t m_ScriptNoteworthy;																			// 0x018C
		scr_string_t m_Target;																						// 0x0190
		scr_string_t m_TargetName;																					// 0x0194
		std::uint32_t m_AttachIgnoreCollision;																		// 0x0198
		int m_SpawnFlags;																							// 0x019C
		/*
		GameModeFlagContainer<enum BgEntityFlagsCommon, enum BgEntityFlagsSP, enum BgEntityFlagsMP, 64> m_Flags;	// 0x01A0
		*/
		char m_Flags[0x0008];																						// 0x01A0
		int m_ClipMask;																								// 0x01A8
		int m_ProcessedFrame;																						// 0x01AC
		EntHandle m_Parent;																							// 0x01B0
		int m_NextThink;																							// 0x01B4
		int m_Health;																								// 0x01B8
		int m_MaxHealth;																							// 0x01BC
		/*
		BgEntityComponents m_C;																						// 0x01C0
		*/
		char m_C[0x00A0];																							// 0x01C0
		/*
		hint_t m_Hint;																								// 0x0260
		*/
		char m_Hint[0x0038];																						// 0x0260
		EntHandle m_MissileTargetEnt;																				// 0x0298
		EntHandle m_RemoteControlledOwner;																			// 0x029C
		EntHandle m_LinkedBeamEnt;																					// 0x02A0
		/*
		GMovingPlatformEntityTracking m_MovingPlatformTrack;														// 0x02A4
		*/
		char m_MovingPlatformTrack[0x0004];																			// 0x02A4
		/*
		GMovingPlatformInfo m_MoverInfo;																			// 0x02A8
		*/
		char m_MoverInfo[0x0018];																					// 0x02A8
		/*
		EntityTagInfo* m_TagInfo;																					// 0x02C0
		*/
		char m_TagInfo[0x0008];																						// 0x02C0
		gentity_s* m_TagChildren;																					// 0x02C8
		/*
		XAnimTree* m_AnimTree;																						// 0x02D0
		*/
		char m_AnimTree[0x0008];																					// 0x02D0
		std::uint16_t m_AttachModelNames[28];																		// 0x02D8
		scr_string_t m_AttachTagNames[28];																			// 0x0310
		gentity_s* m_NextFree;																						// 0x0380
		/*
		GDamageNotifyInfo m_DamageNotify;																			// 0x0388
		*/
		char m_DamageNotify[0x008C];																				// 0x0388
		std::uint16_t m_Model;																						// 0x0414
		std::uint8_t m_PhysicsObject;																				// 0x0416
		std::uint8_t m_Active;																						// 0x0417
		std::uint8_t m_Handler;																						// 0x0418
		std::uint8_t m_Padding[3];																					// 0x0419
		int m_BirthTime;																							// 0x041C
		std::uint16_t m_InfluencePointIndex;																		// 0x0420
		bool m_HasSpawnInfluencePoint;																				// 0x0422
		/*
		EntityMarkFlags m_MarkFlags;																				// 0x0423
		*/
		char m_MarkFlags[0x0001];																					// 0x0423
		std::uint32_t m_MarkFilterIn[7];																			// 0x0424
		std::uint32_t m_MarkFilterOut[7];																			// 0x0440
		/*
		ClientBits m_ClientMask;																					// 0x045C
		*/
		char m_ClientMask[0x001C];																					// 0x045C
		int m_DisconnectTime;																						// 0x0478
		EntHandle m_GrenadeActivator;																				// 0x047C
		scr_string_t m_LookAtText0;																					// 0x0480
		scr_string_t m_LookAtText1;																					// 0x0484
		struct {
			scr_string_t NotifyString;	// 0x0000
			std::uint16_t Index;		// 0x0004
			std::uint8_t Stoppable;		// 0x0006
			std::uint8_t Padding2[1];	// 0x0007
		} m_SndWait;																								// 0x0488
		float m_AngleLerpRate;																						// 0x0490
		int m_PreviousEventSequence;																				// 0x0494
		int m_Padding3;																								// 0x0498
		int m_UseCount;																								// 0x049C
		/*
		EntityAnimScript* m_Scripted;																				// 0x04A0
		*/
		char m_Scripted[0x0008];																					// 0x04A0
		Weapon m_AttachWeapons[4];																					// 0x04A8
		scr_string_t m_AttachWeaponTagNames[4];																		// 0x0598
		std::uint32_t m_AttachModelIsOnBack;																		// 0x05A8
		std::uint32_t m_Padding4;																					// 0x05AC
	};
	ENGINE_ASSERT_SZ(gentity_s, 0x05B0);
}
