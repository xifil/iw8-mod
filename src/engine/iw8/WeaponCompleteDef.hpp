#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImage.hpp"
#include "engine/iw8/Material.hpp"
#include "engine/iw8/NoteTrackToSoundEntry.hpp"
#include "engine/iw8/NoteTrackToSuitSoundEntry.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/WeaponDef.hpp"
#include "engine/iw8/ZoomSettings.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class WeaponCompleteDef {
	public:
		const char* m_InternalName;							// 0x0000
		WeaponDef* m_WeapDef;								// 0x0008
		const char* m_DisplayName;							// 0x0010
		const char* m_LootTable;							// 0x0018
		scr_string_t* m_HideTags;							// 0x0020
		/*
		AttachmentList m_Attachments[14];					// 0x0028
		*/
		char m_Attachments[0x00E0];							// 0x0028
		unsigned int m_NumLootVariants;						// 0x0108
		unsigned int m_NumNoteTrackSoundMappings;			// 0x010C
		scr_string_t* m_NoteTrackSoundMapKeys;				// 0x0110
		scr_string_t* m_NoteTrackSoundMapValues;			// 0x0118
		unsigned int m_NumNoteTrackOverrides;				// 0x0120
	private:
		char pad_0124[0x0004];								// 0x0124
	public:
		NoteTrackToSoundEntry* m_NoteTrackOverrides;		// 0x0128
		unsigned int m_NumNoteTrackSuitEntries;				// 0x0130
	private:
		char pad_0134[0x0004];								// 0x0134
	public:
		NoteTrackToSuitSoundEntry* m_NoteTrackSuitEntries;	// 0x0138
		ZoomSettings m_ZoomSettings;						// 0x0140
		int m_ADSTransInTime;								// 0x01B0
		int m_ADSTransOutTime;								// 0x01B4
		int m_ADSTransInToOutTime;							// 0x01B8
		int m_ADSTransOutToInTime;							// 0x01BC
		int m_ClipSize;										// 0x01C0
		int m_VFXImpactType;								// 0x01C4
		float m_PenetrateMultiplier;						// 0x01C8
		float m_ADSViewKickCenterSpeed;						// 0x01CC
		float m_HipViewKickCenterSpeed;						// 0x01D0
	private:
		char pad_01D4[0x0004];								// 0x01D4
	public:
		Material* m_KillIconMat;							// 0x01D8
		Material* m_DPadIconMat;							// 0x01E0
		Material* m_DPadIconInactiveMat;					// 0x01E8
		GfxImage* m_KillIconImg;							// 0x01F0
		GfxImage* m_DPadIconImg;							// 0x01F8
		GfxImage* m_DPadIconInactiveImg;					// 0x0200
		int m_AmmoDropStockMax;								// 0x0208
		bool m_UseSceneDof;									// 0x020C
	private:
		char pad_020D[0x0003];								// 0x020D
	public:
		float m_ADSDofPhysicalFstop;						// 0x0210
		float m_ADSDofPhysicalFocusDistance;				// 0x0214
		bool m_ADSDofPhysicalFocalTag;						// 0x0218
	private:
		char pad_0219[0x0003];								// 0x0219
	public:
		float m_ADSDofPhysicalReloadFstop;					// 0x021C
		float m_ADSDofPhysicalReloadFocusDistance;			// 0x0220
		std::uint16_t m_AccuracyGraphKnotCount[2];			// 0x0224
		vec2_t* m_AccuracyGraphKnots[2];					// 0x0228
		bool m_Enhanced;									// 0x0238
		bool m_DPadIconShowsAmmo;							// 0x0239
		bool m_LUIWeaponInfoWidgetUsesScopeStencil;			// 0x023A
	private:
		char pad_023B[0x0005];								// 0x023B
	public:
		const char* m_AltModeInactiveName;					// 0x0240
		const char* m_DynamicIconAnimationName;				// 0x0248
		bool m_IsUsingDynamicIcon;							// 0x0250
	private:
		char pad_0251[0x0007];								// 0x0251
	public:
		const char* m_LUIWeaponInfoWidgetName;				// 0x0258
		const char* m_LUIWeaponInfoWidgetTag;				// 0x0260
		const char* m_LUICrosshairWidget;					// 0x0268
	};
	ENGINE_ASSERT_SZ(WeaponCompleteDef, 0x0270);
}
