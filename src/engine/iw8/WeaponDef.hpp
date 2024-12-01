#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ADSOverlay.hpp"
#include "engine/iw8/AdvancedIdleSettings.hpp"
#include "engine/iw8/BallisticInfo.hpp"
#include "engine/iw8/FxCombinedDef.hpp"
#include "engine/iw8/GrenadeRotationParams.hpp"
#include "engine/iw8/HyperBurstInfo.hpp"
#include "engine/iw8/LaserSettings.hpp"
#include "engine/iw8/Material.hpp"
#include "engine/iw8/SndAliasLookup.hpp"
#include "engine/iw8/SwaySettings.hpp"
#include "engine/iw8/TracerDef.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/WeaponDamageInfo.hpp"
#include "engine/iw8/WeaponOffsetCurveDescription.hpp"
#include "engine/iw8/WeaponOffsetPatternScaleInfo.hpp"
#include "engine/iw8/enums/activeReticleType_t.hpp"
#include "engine/iw8/enums/AdsOffsetInterpolationType.hpp"
#include "engine/iw8/enums/ammoCounterClipType_t.hpp"
#include "engine/iw8/enums/DeployType.hpp"
#include "engine/iw8/enums/DualWieldType.hpp"
#include "engine/iw8/enums/guidedMissileType_t.hpp"
#include "engine/iw8/enums/HitmarkerType.hpp"
#include "engine/iw8/enums/OffhandClass.hpp"
#include "engine/iw8/enums/offhandShieldButton_t.hpp"
#include "engine/iw8/enums/offhandShieldMaxSpeed_t.hpp"
#include "engine/iw8/enums/PenetrateType.hpp"
#include "engine/iw8/enums/ReloadType.hpp"
#include "engine/iw8/enums/ReticleType.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"
#include "engine/iw8/enums/scriptedAnimEvent_t.hpp"
#include "engine/iw8/enums/targetAssistType_t.hpp"
#include "engine/iw8/enums/targetAssistBehavior_t.hpp"
#include "engine/iw8/enums/tracerStyle_t.hpp"
#include "engine/iw8/enums/turret3pAnimType_t.hpp"
#include "engine/iw8/enums/turretFireType_t.hpp"
#include "engine/iw8/enums/weapClass_t.hpp"
#include "engine/iw8/enums/WeapDetonateType.hpp"
#include "engine/iw8/enums/weapFireType_t.hpp"
#include "engine/iw8/enums/weapInventoryType_t.hpp"
#include "engine/iw8/enums/WeaponChargeType.hpp"
#include "engine/iw8/enums/weaponIconRatioType_t.hpp"
#include "engine/iw8/enums/WeaponSlot.hpp"
#include "engine/iw8/enums/WeapOverlayInteface_t.hpp"
#include "engine/iw8/enums/weapProjExposion_t.hpp"
#include "engine/iw8/enums/weapStance_t.hpp"
#include "engine/iw8/enums/WeapStickinessType.hpp"
#include "engine/iw8/enums/weapType_t.hpp"

namespace IW8 {
	class AnimOverride;
	class Gesture;
	class LaserDef;
	class RumbleInfo;
	class SFXOverride;
	class VFXOverride;
	class WeaponAnimPackage;
	class WeaponEntityNotify;
	class WeaponOffsetPatternDescription;
	class WeaponSFXPackage;
	class WeaponVFXPackage;
	class XAnimParts;
	class XModel;

	class WeaponDef {
	public:
		const char* m_OverlayName;												// 0x0000
		XModel* m_GunXModel;													// 0x0008
		XModel* m_GunXModelLeftHand;											// 0x0010
		XModel* m_GunXModelRightHand;											// 0x0018
		XModel* m_DefaultViewModel;												// 0x0020
		XModel* m_DefaultWorldModelLeftHand;									// 0x0028
		XModel* m_DefaultWorldModelRightHand;									// 0x0030
		XModel* m_WorldModel;													// 0x0038
		XModel* m_WorldXModelLeftHand;											// 0x0040
		XModel* m_WorldXModelRightHand;											// 0x0048
		XModel* m_DefaultWorldModel;											// 0x0050
		XModel* m_CensorshipWorldModel;											// 0x0058
		XModel* m_CensorshipWorldModelLeftHand;									// 0x0060
		XModel* m_CensorshipWorldModelRightHand;								// 0x0068
		XModel* m_PlayerShadowModel;											// 0x0070
		XModel* m_PlayerShadowModelLeftHand;									// 0x0078
		XModel* m_PlayerShadowModelRightHand;									// 0x0080
		XModel* m_HandXModel;													// 0x0088
		WeaponAnimPackage* m_XAnims;											// 0x0090
		WeaponAnimPackage* m_XAnimsRightHanded;									// 0x0098
		WeaponAnimPackage* m_XAnimsLeftHanded;									// 0x00A0
		XAnimParts* m_TurretRaiseAnim;											// 0x00A8
		XAnimParts* m_TurretIdleAnim;											// 0x00B0
		XAnimParts* m_TurretFireAnim;											// 0x00B8
		WeaponDamageInfo m_DamageInfo;											// 0x00C0
		int m_FireTime;															// 0x0140
		int m_FireDelay;														// 0x0144
		int m_FireTimeAkimbo;													// 0x0148
		int m_FireDelayAkimbo;													// 0x014C
		float m_SprintOutTimerScale;											// 0x0150
	private:
		char pad_0154[0x0004];													// 0x0154
	public:
		const char* m_ModeName;													// 0x0158
		scr_string_t* m_NoteTrackRumbleMapKeys;									// 0x0160
		scr_string_t* m_NoteTrackRumbleMapValues;								// 0x0168
		scr_string_t* m_NoteTrackFXMapKeys;										// 0x0170
		FxCombinedDef* m_NoteTrackFXMapValues;									// 0x0178
		scr_string_t* m_NoteTrackFXMapTagValues;								// 0x0180
		int m_PlayerAnimType;													// 0x0188
		scriptedAnimEvent_t m_ScriptedAnimEvent;								// 0x018C
		int m_ScriptedAnimType;													// 0x0190
		weapType_t m_WeapType;													// 0x0194
		weapClass_t m_WeapClass;												// 0x0198
		PenetrateType m_PenetrateType;											// 0x019C
		weapInventoryType_t m_InventoryType;									// 0x01A0
		weapFireType_t m_FireType;												// 0x01A4
		turretFireType_t m_TurretFireType;										// 0x01A8
		int m_BurstCount;														// 0x01AC
		targetAssistType_t m_TargetAssistType;									// 0x01B0
		targetAssistBehavior_t m_TargetAssistBehavior;							// 0x01B4
		float m_TargetAssistRange;												// 0x01B8
		float m_TargetAssistAngle;												// 0x01BC
		float m_TargetAssistLosOffsetForward;									// 0x01C0
		float m_TargetAssistLosOffsetRight;										// 0x01C4
		float m_TargetAssistLosOffsetUp;										// 0x01C8
		bool m_TargetAssistOnlyAvailableInAds;									// 0x01CC
	private:
		char pad_01CD[0x0003];													// 0x01CD
	public:
		ReloadType m_ReloadType;												// 0x01D0
		float m_BurstFireCooldown;												// 0x01D4
		bool m_BurstFireAuto;													// 0x01D8
	private:
		char pad_01D9[0x0003];													// 0x01D9
	public:
		float m_ViewPitchMaxSpeed;												// 0x01DC
		float m_ViewYawMaxSpeed;												// 0x01E0
		bool m_AlignBarrelWithTurretBody;										// 0x01E4
		bool m_KeepOrientationOnExit;											// 0x01E5
	private:
		char pad_01E6[0x0002];													// 0x01E6
	public:
		float m_KickBackForceMultiplier;										// 0x01E8
		bool m_AutoAdjust;														// 0x01EC
		bool m_NetworkLODRangeOverride;											// 0x01ED
	private:
		char pad_01EE[0x0002];													// 0x01EE
	public:
		float m_NetworkLODRangeOverrideDistance;								// 0x01F0
		OffhandClass m_OffhandClass;											// 0x01F4
		weapStance_t m_Stance;													// 0x01F8
	private:
		char pad_01FC[0x0004];													// 0x01FC
	public:
		WeaponVFXPackage* m_VFXPackage;											// 0x0200
		WeaponSFXPackage* m_SFXPackage;											// 0x0208
		bool m_DisableBreathOffhand;											// 0x0210
	private:
		char pad_0211[0x0003];													// 0x0211
	public:
		ReticleType m_ReticleType;												// 0x0214
		HitmarkerType m_HitmarkerType;											// 0x0218
	private:
		char pad_021C[0x0004];													// 0x021C
	public:
		Material* m_ReticleCenter;												// 0x0220
		Material* m_ReticleSide;												// 0x0228
		Material* m_ReticleOnePiece;											// 0x0230
		int m_ReticleCenterSize;												// 0x0238
		int m_ReticleSideSize;													// 0x023C
		int m_ReticleMinOfs;													// 0x0240
		bool m_ReticleCenterPulse;												// 0x0244
	private:
		char pad_0245[0x0003];													// 0x0245
	public:
		int m_ReticleShakeDuration;												// 0x0248
		int m_ReticleSettleDuration;											// 0x024C
		int m_ReticleNumBulletsToRapidFire;										// 0x0250
		activeReticleType_t m_ActiveReticleType;								// 0x0254
		bool m_UseTurretViewModelAnims;											// 0x0258
		bool m_UseTurret3pIK;													// 0x0259
	private:
		char pad_025A[0x0002];													// 0x025A
	public:
		turret3pAnimType_t m_Turret3pAnimType;									// 0x025C
		float m_TurretFireAnimMinTime;											// 0x0260
		vec3_t m_StandOfs;														// 0x0264
		vec3_t m_StandOfsRot;													// 0x0270
		vec3_t m_StandOfsRotPivot;												// 0x027C
		vec3_t m_StandMove;														// 0x0288
		vec3_t m_StandRot;														// 0x0294
		vec3_t m_StrafeMove;													// 0x02A0
		vec3_t m_StrafeRot;														// 0x02AC
		AdsOffsetInterpolationType m_HipOffsetLerpType;							// 0x02B8
		vec3_t m_DuckedOfs;														// 0x02BC
		vec3_t m_DuckedOfsRot;													// 0x02C8
		vec3_t m_DuckedOfsRotPivot;												// 0x02D4
		vec3_t m_DuckedMove;													// 0x02E0
		vec3_t m_DuckedRot;														// 0x02EC
		vec3_t m_ProneOfs;														// 0x02F8
		vec3_t m_ProneMove;														// 0x0304
		vec3_t m_ProneRot;														// 0x0310
		float m_ADSForwardOffset;												// 0x031C
		float m_ADSRoll;														// 0x0320
		float m_PosMoveRate;													// 0x0324
		float m_PosProneMoveRate;												// 0x0328
		float m_StandMoveMinSpeed;												// 0x032C
		float m_DuckedMoveMinSpeed;												// 0x0330
		float m_ProneMoveMinSpeed;												// 0x0334
		float m_PosRotRate;														// 0x0338
		float m_PosProneRotRate;												// 0x033C
		float m_DuckedOfsRotRate;												// 0x0340
		float m_StandRotMinSpeed;												// 0x0344
		float m_DuckedRotMinSpeed;												// 0x0348
		float m_ProneRotMinSpeed;												// 0x034C
		float m_ReticleShakeMagnitude;											// 0x0350
		float m_ReticleRapidFireMultiplier;										// 0x0354
		XModel* m_WorldClipModel;												// 0x0358
		XModel* m_RocketModel;													// 0x0360
		GfxImage* m_HudIcon;													// 0x0368
		GfxImage* m_PickupIcon;													// 0x0370
		GfxImage* m_DangerIconImg;												// 0x0378
		GfxImage* m_ThrowBackIconImg;											// 0x0380
		Material* m_DangerIconMat;												// 0x0388
		Material* m_ThrowBackIconMat;											// 0x0390
		bool m_HideWarningIcons;												// 0x0398
	private:
		char pad_0399[0x0003];													// 0x0399
	public:
		float m_WarningIconsDelay;												// 0x039C
		ammoCounterClipType_t m_AmmoCounterClip;								// 0x03A0
		int m_StartAmmo;														// 0x03A4
		int m_PerkStartAmmo;													// 0x03A8
		int m_PerkMaxAmmo;														// 0x03AC
		const char* m_AmmoName;													// 0x03B0
		int m_AmmoIndex;														// 0x03B8
		int m_MaxAmmo;															// 0x03BC
		int m_ShotCount;														// 0x03C0
	private:
		char pad_03C4[0x0004];													// 0x03C4
	public:
		const char* m_SharedAmmoCapName;										// 0x03C8
		int m_SharedAmmoCapIndex;												// 0x03D0
		int m_SharedAmmoCap;													// 0x03D4
		int m_AmmoUsedPerShot;													// 0x03D8
		bool m_RequireAmmoUsedPerShot;											// 0x03DC
		bool m_DisableNoAmmoWarning;											// 0x03DD
	private:
		char pad_03DE[0x0002];													// 0x03DE
	public:
		float m_LowAmmoWarningThreshold;										// 0x03E0
		int m_LowAmmoWarningCount;												// 0x03E4
		int m_DamageType;														// 0x03E8
		int m_MeleeDamage;														// 0x03EC
		int m_MeleeCountToFinisher;												// 0x03F0
		bool m_HasMeleeFinisher;												// 0x03F4
	private:
		char pad_03F5[0x0003];													// 0x03F5
	public:
		float m_AutoAimRange;													// 0x03F8
		float m_AimAssistRange;													// 0x03FC
		float m_AimAssistRangeAds;												// 0x0400
		float m_AimAssistPitchSlowdown;											// 0x0404
		float m_AimAssistPitchSlowdownADS;										// 0x0408
		float m_AimAssistYawSlowdown;											// 0x040C
		float m_AimAssistYawSlowdownAds;										// 0x0410
		float m_AimAssistLockOnStrength;										// 0x0414
		float m_AimPadding;														// 0x0418
		float m_EnemyCrosshairRange;											// 0x041C
		float m_MoveSpeedScale;													// 0x0420
		float m_ADSMoveSpeedScale;												// 0x0424
		float m_SprintDurationScale;											// 0x0428
		float m_SprintRestoreDelay;												// 0x042C
		ADSOverlay m_Overlay;													// 0x0430
		WeapOverlayInteface_t m_OverlayInterface;								// 0x04A0
		float m_ADSBobFactor;													// 0x04A4
		float m_ADSViewBobMult;													// 0x04A8
		float m_ADSGunBobPitchScale;											// 0x04AC
		float m_ADSGunBobYawScale;												// 0x04B0
		float m_ADSGunBobTiltPitchScale;										// 0x04B4
		float m_ADSGunBobTiltYawScale;											// 0x04B8
		float m_ADSGunBobTiltRollScale;											// 0x04BC
		float m_ADSGunBobTiltBulletDirScale;									// 0x04C0
		float m_ADSGunBobTiltOffset;											// 0x04C4
		float m_ADSGunBobCrouchFactor;											// 0x04C8
		float m_ADSCrouchViewKickFactor;										// 0x04CC
		float m_ADSCrouchGunKickFactor;											// 0x04D0
		float m_ADSProneViewKickFactor;											// 0x04D4
		float m_ADSProneGunKickFactor;											// 0x04D8
		float m_HipSpreadStandMin;												// 0x04DC
		float m_HipSpreadDuckedMin;												// 0x04E0
		float m_HipSpreadProneMin;												// 0x04E4
		float m_HipSpreadSprintMin;												// 0x04E8
		float m_HipSpreadInAirMin;												// 0x04EC
		float m_HipSpreadStandMax;												// 0x04F0
		float m_HipSpreadDuckedMax;												// 0x04F4
		float m_HipSpreadProneMax;												// 0x04F8
		float m_HipSpreadSprintMax;												// 0x04FC
		float m_HipSpreadInAirMax;												// 0x0500
		float m_HipSpreadDecayRate;												// 0x0504
		float m_HipSpreadFireAdd;												// 0x0508
		float m_HipSpreadTurnAdd;												// 0x050C
		float m_HipSpreadMoveAdd;												// 0x0510
		float m_HipSpreadDuckedDecay;											// 0x0514
		float m_HipSpreadProneDecay;											// 0x0518
		float m_HipSpreadSprintDecay;											// 0x051C
		float m_HipSpreadInAirDecay;											// 0x0520
		float m_HipReticleSidePos;												// 0x0524
		float m_ADSIdleAmount;													// 0x0528
		float m_HipIdleAmount;													// 0x052C
		float m_ADSIdleSpeed;													// 0x0530
		float m_HipIdleSpeed;													// 0x0534
		float m_IdleCrouchFactor;												// 0x0538
		float m_IdleProneFactor;												// 0x053C
		float m_GunMaxPitch;													// 0x0540
		float m_GunMaxYaw;														// 0x0544
		float m_ViewMaxPitch;													// 0x0548
		float m_ViewMaxYaw;														// 0x054C
		float m_ADSIdleLerpStartTime;											// 0x0550
		float m_ADSIdleLerpTime;												// 0x0554
		bool m_UseUninterruptedAdsIdleMotion;									// 0x0558
		bool m_DisableInputDrivenViewReturnDampening;							// 0x0559
	private:
		char pad_055A[0x0002];													// 0x055A
	public:
		float m_SlideSpreadMin;													// 0x055C
		float m_SlideSpreadMax;													// 0x0560
		float m_SlideSpreadDecayRate;											// 0x0564
		float m_SlideSpreadFireAdd;												// 0x0568
		float m_SlideSpreadTurnAdd;												// 0x056C
		SwaySettings m_SwaySettings;											// 0x0570
		float m_ADSFireRateScale;												// 0x0670
		float m_ADSDamageRangeScale;											// 0x0674
		float m_ADSFireAnimFrac;												// 0x0678
		float m_FireTimerLerpToAdsScale;										// 0x067C
		bool m_AlwaysFireAtMaxRangeInAds;										// 0x0680
		bool m_ADSAlignEnabled;													// 0x0681
		bool m_DisableTagAlignX;												// 0x0682
	private:
		char pad_0683[0x0001];													// 0x0683
	public:
		vec3_t m_ADSAlignOffset;												// 0x0684
		AdsOffsetInterpolationType m_ADSAlignOffsetLerpType;					// 0x0690
		AdsOffsetInterpolationType m_ADSAlignLerpType;							// 0x0694
		float m_ADSMovementAnimLerpStart;										// 0x0698
		float m_ADSMovementAnimLerpEnd;											// 0x069C
		float m_DualWieldViewModelOffset;										// 0x06A0
		float m_ScopeDriftDelay;												// 0x06A4
		float m_ScopeDriftLerpInTime;											// 0x06A8
		float m_ScopeDriftSteadyTime;											// 0x06AC
		float m_ScopeDriftLerpOutTime;											// 0x06B0
		float m_ScopeDriftSteadyFactor;											// 0x06B4
		float m_ScopeDriftUnsteadyFactor;										// 0x06B8
		weaponIconRatioType_t m_KillIconRatio;									// 0x06BC
		int m_ReloadAmmoAdd;													// 0x06C0
		int m_ReloadStartAdd;													// 0x06C4
		bool m_ReloadTwoRound;													// 0x06C8
	private:
		char pad_06C9[0x0003];													// 0x06C9
	public:
		int m_AmmoDropStockMin;													// 0x06CC
		int m_AmmoDropClipPercentMin;											// 0x06D0
		int m_AmmoDropClipPercentMax;											// 0x06D4
		float m_CameraShakeScale;												// 0x06D8
		int m_CameraShakeDuration;												// 0x06DC
		float m_CameraShakeRadius;												// 0x06E0
		int m_ExplosionRadius;													// 0x06E4
		int m_ExplosionRadiusMin;												// 0x06E8
		int m_ExplosionForceRadius;												// 0x06EC
		int m_ExplosionInnerDamage;												// 0x06F0
		int m_ExplosionOuterDamage;												// 0x06F4
		float m_ExplosionForceScalar;											// 0x06F8
		float m_DamageConeAngle;												// 0x06FC
		float m_BulletExplDmgMultMin;											// 0x0700
		float m_BulletExplDmgMult;												// 0x0704
		float m_BulletExplRadiusMult;											// 0x0708
		int m_ProjectileSpeed;													// 0x070C
		int m_ProjectileSpeedUp;												// 0x0710
		int m_ProjectileSpeedForward;											// 0x0714
		int m_ProjectileActivateDist;											// 0x0718
		int m_ProjectileDetonationRadius;										// 0x071C
		float m_ProjLifetime;													// 0x0720
		float m_ProjLifetimeStdDeviation;										// 0x0724
		float m_TimeToAccelerate;												// 0x0728
		float m_ProjectileCurvature;											// 0x072C
		XModel* m_ProjectileModel;												// 0x0730
		weapProjExposion_t m_ProjExplosion;										// 0x0738
	private:
		char pad_073C[0x0004];													// 0x073C
	public:
		FxCombinedDef m_ProjExplosionEffect;									// 0x0740
		FxCombinedDef m_ProjDudEffect;											// 0x0748
		FxCombinedDef m_ProjTimeoutEffect;										// 0x0750
		bool m_DisableFxOnTimeout;												// 0x0758
	private:
		char pad_0759[0x0003];													// 0x0759
	public:
		WeapStickinessType m_Stickiness;										// 0x075C
		float m_RicochetChance;													// 0x0760
		int m_ExplosionSteppedRadiusInner;										// 0x0764
		int m_ExplosionSteppedRadiusMid;										// 0x0768
		int m_ExplosionSteppedRadiusOuter;										// 0x076C
		int m_ExplosionSteppedDamageInner;										// 0x0770
		int m_ExplosionSteppedDamageMid;										// 0x0774
		int m_ExplosionSteppedDamageOuter;										// 0x0778
		bool m_RiotShieldEnableDamage;											// 0x077C
	private:
		char pad_077D[0x0003];													// 0x077D
	public:
		int m_RiotShieldHealth;													// 0x0780
		float m_RiotShieldDamageMult;											// 0x0784
		float* m_ParallelBounce;												// 0x0788
		float* m_PerpendicularBounce;											// 0x0790
		FxCombinedDef m_VmProjBodyEffect;										// 0x0798
		FxCombinedDef m_ProjBodyEffect;											// 0x07A0
		FxCombinedDef m_ProjTrailEffect;										// 0x07A8
		FxCombinedDef m_ProjBeaconEffect;										// 0x07B0
		vec3_t m_ProjectileColor;												// 0x07B8
		guidedMissileType_t m_GuidedMissileType;								// 0x07C4
		float m_MaxSteeringAccel;												// 0x07C8
		int m_ProjIgnitionDelay;												// 0x07CC
		FxCombinedDef m_ProjIgnitionEffect;										// 0x07D0
		float m_ADSAimPitch;													// 0x07D8
		float m_ADSInCrosshairAlphaStart;										// 0x07DC
		float m_ADSInCrosshairAlphaEnd;											// 0x07E0
		float m_ADSOutCrosshairAlphaStart;										// 0x07E4
		float m_ADSOutCrosshairAlphaEnd;										// 0x07E8
		bool m_ADSShouldShowCrosshair;											// 0x07EC
	private:
		char pad_07ED[0x0003];													// 0x07ED
	public:
		float m_ADSGunKickPitchMin;												// 0x07F0
		float m_ADSGunKickPitchMax;												// 0x07F4
		float m_ADSGunKickYawMin;												// 0x07F8
		float m_ADSGunKickYawMax;												// 0x07FC
		float m_ADSGunKickMagMin;												// 0x0800
		float m_ADSGunKickAccel;												// 0x0804
		float m_ADSGunKickSpeedMax;												// 0x0808
		float m_ADSGunKickSpeedDecay;											// 0x080C
		float m_ADSGunKickStaticDecay;											// 0x0810
		float m_ADSViewKickPitchMin;											// 0x0814
		float m_ADSViewKickPitchMax;											// 0x0818
		float m_ADSViewKickYawMin;												// 0x081C
		float m_ADSViewKickYawMax;												// 0x0820
		float m_ADSViewKickMagMin;												// 0x0824
		float m_ADSViewScatterMin;												// 0x0828
		float m_ADSViewScatterMax;												// 0x082C
		float m_ADSSpread;														// 0x0830
		float m_ADSSpreadNVG;													// 0x0834
		float m_ADSSpreadStartFrac;												// 0x0838
		float m_ADSSpreadEndFrac;												// 0x083C
		int m_VisibilityAxis;													// 0x0840
		float m_VisibilityUpOffset;												// 0x0844
		float m_HipGunKickPitchMin;												// 0x0848
		float m_HipGunKickPitchMax;												// 0x084C
		float m_HipGunKickYawMin;												// 0x0850
		float m_HipGunKickYawMax;												// 0x0854
		float m_HipGunKickMagMin;												// 0x0858
		float m_HipGunKickAccel;												// 0x085C
		float m_HipGunKickSpeedMax;												// 0x0860
		float m_HipGunKickSpeedDecay;											// 0x0864
		float m_HipGunKickStaticDecay;											// 0x0868
		float m_HipViewKickPitchMin;											// 0x086C
		float m_HipViewKickPitchMax;											// 0x0870
		float m_HipViewKickYawMin;												// 0x0874
		float m_HipViewKickYawMax;												// 0x0878
		float m_HipViewKickMagMin;												// 0x087C
		float m_HipViewScatterMin;												// 0x0880
		float m_HipViewScatterMax;												// 0x0884
		float m_MultipleReloadClipPercentage;									// 0x0888
		float m_HipStartingGunKickPercent;										// 0x088C
		float m_HipStartingViewKickPercent;										// 0x0890
		int m_ADSStartingKickBullets;											// 0x0894
		float m_ADSStartingGunKickPercent;										// 0x0898
		float m_ADSStartingViewKickPercent;										// 0x089C
		float m_HipEndingGunKickPercent;										// 0x08A0
		float m_HipEndingViewKickPercent;										// 0x08A4
		int m_ADSEndingKickBullets;												// 0x08A8
		float m_ADSEndingGunKickPercent;										// 0x08AC
		float m_ADSEndingViewKickPercent;										// 0x08B0
		float m_KickAlignedInputScalar;											// 0x08B4
		float m_KickOpposedInputScalar;											// 0x08B8
		float m_ViewKickMaintainFraction;										// 0x08BC
		float m_ADSGunTiltPitchFactor;											// 0x08C0
		float m_ADSGunTiltYawFactor;											// 0x08C4
		float m_ADSGunTiltRollFactor;											// 0x08C8
		float m_ADSGunTiltOffset;												// 0x08CC
		float m_HipGunTiltPitchFactor;											// 0x08D0
		float m_HipGunTiltYawFactor;											// 0x08D4
		float m_HipGunTiltRollFactor;											// 0x08D8
		float m_HipGunTiltOffset;												// 0x08DC
		bool m_UseNewViewKick;													// 0x08E0
		bool m_UseNewGunKick;													// 0x08E1
		bool m_UseAngularViewKick;												// 0x08E2
		bool m_UseAngularGunKick;												// 0x08E3
		float m_HipAngularViewKickDir[6];										// 0x08E4
		float m_HipAngularViewKickDev[6];										// 0x08FC
		float m_HipAngularViewKickStrengthMin[6];								// 0x0914
		float m_HipAngularViewKickStrengthMax[6];								// 0x092C
		float m_HipAngularViewKickPitchScale[6];								// 0x0944
		float m_ADSAngularViewKickDir[6];										// 0x095C
		float m_ADSAngularViewKickDev[6];										// 0x0974
		float m_ADSAngularViewKickStrengthMin[6];								// 0x098C
		float m_ADSAngularViewKickStrengthMax[6];								// 0x09A4
		float m_ADSAngularViewKickPitchScale[6];								// 0x09BC
		int m_ADSAngularViewKickBullet[6];										// 0x09D4
		bool m_ADSAngularViewKickUseSet[6];										// 0x09EC
	private:
		char pad_09F2[0x0002];													// 0x09F2
	public:
		float m_HipAngularGunKickDir[6];										// 0x09F4
		float m_HipAngularGunKickDev[6];										// 0x0A0C
		float m_HipAngularGunKickStrengthMin[6];								// 0x0A24
		float m_HipAngularGunKickStrengthMax[6];								// 0x0A3C
		float m_HipAngularGunKickPitchScale[6];									// 0x0A54
		float m_ADSAngularGunKickDir[6];										// 0x0A6C
		float m_ADSAngularGunKickDev[6];										// 0x0A84
		float m_ADSAngularGunKickStrengthMin[6];								// 0x0A9C
		float m_ADSAngularGunKickStrengthMax[6];								// 0x0AB4
		float m_ADSAngularGunKickPitchScale[6];									// 0x0ACC
		int m_ADSAngularGunKickBullet[6];										// 0x0AE4
		bool m_ADSAngularGunKickUseSet[6];										// 0x0AFC
	private:
		char pad_0B02[0x0002];													// 0x0B02
	public:
		float m_HipViewKickReturnAccelScale;									// 0x0B04
		float m_ADSViewKickReturnAccelScale;									// 0x0B08
		float m_HipViewKickReturnSpeedCurveScale;								// 0x0B0C
		float m_ADSViewKickReturnSpeedCurveScale;								// 0x0B10
		float m_HipGunKickReturnAccelScale;										// 0x0B14
		float m_ADSGunKickReturnAccelScale;										// 0x0B18
		float m_HipGunKickReturnSpeedCurveScale;								// 0x0B1C
		float m_ADSGunKickReturnSpeedCurveScale;								// 0x0B20
		float m_HipSpreadStandMoveMax;											// 0x0B24
		float m_HipSpreadDuckedMoveMax;											// 0x0B28
		float m_HipSpreadProneMoveMax;											// 0x0B2C
		float m_HipSpreadSprintMoveMax;											// 0x0B30
		float m_HipSpreadInAirMoveMax;											// 0x0B34
		float m_SlideSpreadMoveMax;												// 0x0B38
		WeaponOffsetCurveDescription m_WeaponOffsetCurveHoldFireSlow;			// 0x0B3C
		WeaponOffsetCurveDescription m_WeaponOffsetCurveHoldFireFast;			// 0x0B5C
		WeaponOffsetCurveDescription m_WeaponOffsetCurveAds;					// 0x0B7C
		WeaponOffsetCurveDescription m_WeaponOffsetCurveAlwaysOn;				// 0x0B9C
		WeaponOffsetCurveDescription m_WeaponOffsetCurveKick;					// 0x0BBC
		WeaponOffsetCurveDescription m_WeaponOffsetCurveSnapDecay;				// 0x0BDC
		int m_NumWeaponOffsetPatterns;											// 0x0BFC
		WeaponOffsetPatternDescription* m_WeaponOffsetPatterns;					// 0x0C00
		int m_NumWeaponOffsetPatternsKickOrSnapDecay;							// 0x0C08
	private:
		char pad_0C0C[0x0004];													// 0x0C0C
	public:
		WeaponOffsetPatternDescription** m_WeaponOffsetPatternsKickOrSnapDecay;	// 0x0C10
		float m_FightDist;														// 0x0C18
		float m_MaxDist;														// 0x0C1C
		const char* m_AccuracyGraphName[2];										// 0x0C20
		vec2_t* m_OriginalAccuracyGraphKnots[2];								// 0x0C30
		unsigned __int16 m_OriginalAccuracyGraphKnotCount[2];					// 0x0C40
		int m_PositionReloadTransTime;											// 0x0C44
		float m_LeftArc;														// 0x0C48
		float m_RightArc;														// 0x0C4C
		float m_TopArc;															// 0x0C50
		float m_BottomArc;														// 0x0C54
		float m_VisualPitchLimitTop;											// 0x0C58
		float m_VisualPitchLimitBottom;											// 0x0C5C
		bool m_SoftLeftRightArc;												// 0x0C60
	private:
		char pad_0C61[0x0003];													// 0x0C61
	public:
		float m_Accuracy;														// 0x0C64
		float m_AISpread;														// 0x0C68
		float m_PlayerSpread;													// 0x0C6C
		float m_MinTurnSpeed[2];												// 0x0C70
		float m_MaxTurnSpeed[2];												// 0x0C78
		float m_PitchConvergenceTime;											// 0x0C80
		float m_YawConvergenceTime;												// 0x0C84
		float m_SuppressTime;													// 0x0C88
		float m_SuppressTimeTargetKilled;										// 0x0C8C
		float m_AIReturnToDefaultSpeed[2];										// 0x0C90
		float m_MaxRange;														// 0x0C98
		float m_AnimHorRotateInc;												// 0x0C9C
		float m_PlayerPositionDist;												// 0x0CA0
	private:
		char pad_0CA4[0x0004];													// 0x0CA4
	public:
		const char* m_UseHintString;											// 0x0CA8
		const char* m_DropHintString;											// 0x0CB0
		unsigned int m_UseHintStringIndex;										// 0x0CB8
		unsigned int m_DropHintStringIndex;										// 0x0CBC
		float m_HorizViewJitter;												// 0x0CC0
		float m_VertViewJitter;													// 0x0CC4
		bool m_EnableViewBounceFire;											// 0x0CC8
	private:
		char pad_0CC9[0x0003];													// 0x0CC9
	public:
		float m_ViewBounceFireDecay;											// 0x0CCC
		float m_ViewBounceFireFrequency;										// 0x0CD0
		float m_ViewBounceFirePitchScale;										// 0x0CD4
		float m_ViewBounceFireRollScale;										// 0x0CD8
		float m_ScanSpeed;														// 0x0CDC
		float m_ScanAccel;														// 0x0CE0
		int m_ScanPauseTime;													// 0x0CE4
		const char* m_Script;													// 0x0CE8
		float m_ADSSpeedMs[2];													// 0x0CF0
		float m_ADSAccelSec[2];													// 0x0CF8
		bool m_DeferDamageToParentVehicle;										// 0x0D00
		bool m_UseSteppedExplosionDamage;										// 0x0D01
	private:
		char pad_0D02[0x0002];													// 0x0D02
	public:
		float m_DestabilizationRateTime;										// 0x0D04
		float m_DestabilizationCurvatureMax;									// 0x0D08
		int m_DestabilizeDistance;												// 0x0D0C
		float m_RoboTechMaxPitch;												// 0x0D10
		float m_RoboTechMaxYaw;													// 0x0D14
		float m_RoboTechFrequency;												// 0x0D18
		float m_RoboTechVariancePitch;											// 0x0D1C
		float m_RoboTechVarianceYaw;											// 0x0D20
		float m_RoboTechVarianceFrequency;										// 0x0D24
		float* m_LocationDamageMultipliers;										// 0x0D28
		unsigned __int8* m_HitLocPriorityMap;									// 0x0D30
		float m_UnitTypeMultipliers[7];											// 0x0D38
	private:
		char pad_0D54[0x0002];													// 0x0D54
	public:
		RumbleInfo* m_FireRumble;												// 0x0D58
		RumbleInfo* m_MeleeImpactRumble;										// 0x0D60
		float m_HeatAccumulationPerShot;										// 0x0D68
		float m_HeatDissipationPerSecond;										// 0x0D6C
		float m_HeatSmokeStartThreshold;										// 0x0D70
		float m_HeatSmokeStopThreshold;											// 0x0D74
		bool m_HeatIsOpenBolt;													// 0x0D78
	private:
		char pad_0D79[0x0003];													// 0x0D79
	public:
		tracerStyle_t m_TracerStyle;											// 0x0D7C
		TracerDef* m_TracerType;												// 0x0D80
		TracerDef* m_OverchargeTracerType;										// 0x0D88
		LaserDef* m_LaserTypeViewModel;											// 0x0D90
		LaserDef* m_LaserTypeViewModelAlt;										// 0x0D98
		LaserDef* m_LaserTypeFriendly;											// 0x0DA0
		LaserDef* m_LaserTypeEnemy;												// 0x0DA8
		bool m_TurretADSEnabled;												// 0x0DB0
	private:
		char pad_0DB1[0x0003];													// 0x0DB1
	public:
		float m_TurretADSTime;													// 0x0DB4
		float m_TurretFov;														// 0x0DB8
		float m_TurretFovADS;													// 0x0DBC
		float m_TurretScopeZoomRate;											// 0x0DC0
		float m_TurretScopeZoomMin;												// 0x0DC4
		float m_TurretScopeZoomMax;												// 0x0DC8
		float m_TurretOverheatPenalty;											// 0x0DCC
		SndAliasLookup m_TurretOverheatSound;									// 0x0DD0
		FxCombinedDef m_TurretOverheatEffect;									// 0x0DD8
		RumbleInfo* m_TurretBarrelSpinRumble;									// 0x0DE0
		float m_TurretBarrelSpinSpeed;											// 0x0DE8
		float m_TurretBarrelSpinUpTime;											// 0x0DEC
		float m_TurretBarrelSpinDownTime;										// 0x0DF0
	private:
		char pad_0DF4[0x0004];													// 0x0DF4
	public:
		SndAliasLookup m_TurretBarrelSpinMaxSnd;								// 0x0DF8
		SndAliasLookup m_TurretBarrelSpinUpSnd[4];								// 0x0E00
		SndAliasLookup m_TurretBarrelSpinDownSnd[4];							// 0x0E20
		SndAliasLookup m_MissileConeSoundAlias;									// 0x0E40
		SndAliasLookup m_MissileConeSoundAliasAtBase;							// 0x0E48
		float m_MissileConeSoundRadiusAtTop;									// 0x0E50
		float m_MissileConeSoundRadiusAtBase;									// 0x0E54
		float m_MissileConeSoundHeight;											// 0x0E58
		float m_MissileConeSoundOriginOffset;									// 0x0E5C
		float m_MissileConeSoundVolumeScaleAtCore;								// 0x0E60
		float m_MissileConeSoundVolumeScaleAtEdge;								// 0x0E64
		float m_MissileConeSoundVolumeScaleCoreSize;							// 0x0E68
		float m_MissileConeSoundPitchAtTop;										// 0x0E6C
		float m_MissileConeSoundPitchAtBottom;									// 0x0E70
		float m_MissileConeSoundPitchTopSize;									// 0x0E74
		float m_MissileConeSoundPitchBottomSize;								// 0x0E78
		float m_MissileConeSoundCrossfadeTopSize;								// 0x0E7C
		float m_MissileConeSoundCrossfadeBottomSize;							// 0x0E80
		bool m_MeleeOverrideValues;												// 0x0E84
	private:
		char pad_0E85[0x0003];													// 0x0E85
	public:
		float m_AimAutoMeleeLerp;												// 0x0E88
		float m_AimAutoMeleeRegionHeight;										// 0x0E8C
		float m_AimAutoMeleeRegionWidth;										// 0x0E90
		float m_AimAutoMeleeMaxPitchMovement;									// 0x0E94
		float m_AimAutoMeleeMaxYawMovement;										// 0x0E98
		float m_PlayerMeleeHeight;												// 0x0E9C
		float m_PlayerMeleeWidth;												// 0x0EA0
		float m_PlayerMeleeRangeStanding;										// 0x0EA4
		float m_PlayerMeleeRangeCrouched;										// 0x0EA8
		float m_PlayerMeleeRangeProne;											// 0x0EAC
		float m_PlayerMeleeRangeChargeStanding;									// 0x0EB0
		float m_PlayerMeleeRangeChargeCrouched;									// 0x0EB4
		float m_PlayerMeleeChargeHeightTolerance;								// 0x0EB8
		bool m_ShieldAllowFiring;												// 0x0EBC
	private:
		char pad_0EBD[0x0003];													// 0x0EBD
	public:
		offhandShieldMaxSpeed_t m_ShieldMaxSpeed;								// 0x0EC0
		bool m_ShieldAlwaysDisplay;												// 0x0EC4
	private:
		char pad_0EC5[0x0003];													// 0x0EC5
	public:
		Gesture* m_ShieldDeployGesture;											// 0x0EC8
		Gesture* m_ShieldFireWeapGesture;										// 0x0ED0
		Gesture* m_ShieldDeployWhileFiring;										// 0x0ED8
		Gesture* m_ShieldRetractWhileFiring;									// 0x0EE0
		Gesture* m_ShieldBashGesture;											// 0x0EE8
		FxCombinedDef m_ShieldMeleeFx;											// 0x0EF0
		float m_ShieldMeleeFxDelay;												// 0x0EF8
		float m_HitEarthquakeScale;												// 0x0EFC
		float m_HitEarthquakeDuration;											// 0x0F00
		float m_HitEarthquakeRadius;											// 0x0F04
		RumbleInfo* m_ShieldHitRumble;											// 0x0F08
		float m_MissEarthquakeScale;											// 0x0F10
		float m_MissEarthquakeDuration;											// 0x0F14
		float m_MissEarthquakeRadius;											// 0x0F18
	private:
		char pad_0F1C[0x0004];													// 0x0F1D
	public:
		RumbleInfo* m_ShieldMissRumble;											// 0x0F20
		offhandShieldButton_t m_ShieldDeployButton;								// 0x0F28
		bool m_ShieldUsesEnergy;												// 0x0F2C
	private:
		char pad_0F2D[0x0003];													// 0x0F2D
	public:
		float m_ShieldMaxEnergy;												// 0x0F30
		float m_ShieldConsumptionRate;											// 0x0F34
		float m_ShieldMeleeEnergyCost;											// 0x0F38
		float m_ShieldMeleeHitEnergyCost;										// 0x0F3C
		float m_ReactiveMotionRadiusScale;										// 0x0F40
		float m_ReactiveMotionFrequencyScale;									// 0x0F44
		float m_ReactiveMotionAmplitudeScale;									// 0x0F48
		float m_ReactiveMotionFalloff;											// 0x0F4C
		float m_ReactiveMotionLifetime;											// 0x0F50
		unsigned __int8 m_TransientBaseViewFlags;								// 0x0F54
		unsigned __int8 m_TransientBaseWorldFlags;								// 0x0F55
		bool m_HasAnyTransientModels;											// 0x0F56
		bool m_BlendFireAnimations;												// 0x0F57
		bool m_SharedAmmo;														// 0x0F58
		bool m_LockOnSupported;													// 0x0F59
		bool m_RequireLockonToFire;												// 0x0F5A
		bool m_IsAirburstWeapon;												// 0x0F5B
		bool m_BigExplosion;													// 0x0F5C
		bool m_NoADSWhenMagEmpty;												// 0x0F5D
		bool m_AvoidDropCleanup;												// 0x0F5E
		bool m_AllowGrenadeSwitching;											// 0x0F5F
		bool m_InheritsPerks;													// 0x0F60
		bool m_ForceUse;														// 0x0F61
		bool m_LadderWeapon;													// 0x0F62
		bool m_ExecutionVictimHiddenWeapon;										// 0x0F63
		bool m_CrosshairColorChange;											// 0x0F64
		bool m_RifleBullet;														// 0x0F65
		bool m_EnergyBullet;													// 0x0F66
		bool m_IncendiaryBullet;												// 0x0F67
		bool m_ArmorPiercing;													// 0x0F68
		bool m_Impaling;														// 0x0F69
		bool m_BoltAction;														// 0x0F6A
		bool m_AimDownSight;													// 0x0F6B
		bool m_CanHoldBreath;													// 0x0F6C
		bool m_MeleeOnly;														// 0x0F6D
		bool m_SupportsAlternateMelee;											// 0x0F6E
		bool m_RechamberWhileAds;												// 0x0F6F
		bool m_ReloadWhileAds;													// 0x0F70
		bool m_BulletExplosiveDamage;											// 0x0F71
		bool m_CookOffHold;														// 0x0F72
		bool m_OverCookIsNotLethal;												// 0x0F73
		bool m_ReticleSpin45;													// 0x0F74
		bool m_ClipOnly;														// 0x0F75
		bool m_DoesNotConsumeAmmo;												// 0x0F76
		bool m_RemoveWeaponOnEmpty;												// 0x0F77
		bool m_NoAmmoPickup;													// 0x0F78
		bool m_ADSFireOnly;														// 0x0F79
		bool m_CancelAutoHolsterWhenEmpty;										// 0x0F7A
		bool m_DisableSwitchToWhenEmpty;										// 0x0F7B
		bool m_SuppressAmmoPrimaryDisplay;										// 0x0F7C
		bool m_SuppressAmmoReserveDisplay;										// 0x0F7D
		LaserSettings m_LaserSettings;											// 0x0F7E
		bool m_MarkableViewModel;												// 0x0F88
		bool m_IsPredictedProjectile;											// 0x0F89
	private:
		char pad_0F8A[0x0002];													// 0x0F8A
	public:
		int m_ClientTrajectoryBlendOutTime;										// 0x0F8C
		int m_ServerTrajectoryBlendInTime;										// 0x0F90
		DualWieldType m_DualWieldType;											// 0x0F94
		bool m_FlipKillIcon;													// 0x0F98
		bool m_NoPartialReload;													// 0x0F99
		bool m_ReloadDisabled;													// 0x0F9A
		bool m_BlocksProne;														// 0x0F9B
		bool m_Silenced;														// 0x0F9C
		bool m_DoNotSuppressAI;													// 0x0F9D
		bool m_IsRollingGrenade;												// 0x0F9E
		bool m_DropGrenadeHeldOnDeath;											// 0x0F9F
		bool m_ProjExplosionEffectForceNormalUp;								// 0x0FA0
		bool m_ProjExplosionEffectInheritParentDirection;						// 0x0FA1
		bool m_ProjImpactExplode;												// 0x0FA2
		bool m_SpawnProjAtMuzzle;												// 0x0FA3
		bool m_CorrectBulletTrajectory;											// 0x0FA4
	private:
		char pad_0FA5[0x0003];													// 0x0FA5
	public:
		float m_MaxCorrectionAngle;												// 0x0FA8
		bool m_DisableProjectileCrumpleCheck;									// 0x0FAC
		bool m_ProjTrajectoryEvents;											// 0x0FAD
		bool m_ProjWhizByEnabled;												// 0x0FAE
		bool m_StickToPlayers;													// 0x0FAF
		bool m_StickToVehicles;													// 0x0FB0
		bool m_StickToTurrets;													// 0x0FB1
		bool m_StickToNonStick;													// 0x0FB2
		bool m_ProjEnableMissileStickiness;										// 0x0FB3
		bool m_EnableMissileRicochet;											// 0x0FB4
		bool m_ThrownSideways;													// 0x0FB5
		bool m_DisableFiring;													// 0x0FB6
		bool m_FiresOnWeaponSwitch;												// 0x0FB7
		bool m_DisableHolding;													// 0x0FB8
		bool m_TimedDetonation;													// 0x0FB9
	private:
		char pad_0FBA[0x0002];													// 0x0FBA
	public:
		float m_MissileRicochetMinAngleOfIncidence;								// 0x0FBC
		float m_MissileCrumpleMinSpeed;											// 0x0FC0
		WeapDetonateType m_DetonateType;										// 0x0FC4
		XModel* m_DetonatorWorldModel;											// 0x0FC8
		int m_ExplosiveDamageDelay;												// 0x0FD0
		int m_FuseTime;															// 0x0FD4
		int m_AIFuseTime;														// 0x0FD8
		int m_MaxHoldTime;														// 0x0FDC
		GrenadeRotationParams m_RotationParams;									// 0x0FE0
		bool m_HoldButtonToThrow;												// 0x1014
		bool m_AutoHold;														// 0x1015
		bool m_InfiniteHold;													// 0x1016
		bool m_FreezeMovementWhenFiring;										// 0x1017
		bool m_OffhandAllowsSprint;												// 0x1018
		bool m_ThermalScope;													// 0x1019
		bool m_ThermalToggle;													// 0x101A
		bool m_OutlineEnemies;													// 0x101B
		bool m_OutlineDepthTest;												// 0x101C
		bool m_OutlineFill;														// 0x101D
	private:
		char pad_101E[0x0001];													// 0x101E
	public:
		float m_EnemyOutlineR;													// 0x1020
		float m_EnemyOutlineG;													// 0x1024
		float m_EnemyOutlineB;													// 0x1028
		float m_EnemyOutlineA;													// 0x102C
		float m_AllyOutlineR;													// 0x1030
		float m_AllyOutlineG;													// 0x1034
		float m_AllyOutlineB;													// 0x1038
		float m_AllyOutlineA;													// 0x103C
		bool m_DepthScan;														// 0x1040
	private:
		char pad_1041[0x0003];													// 0x1041
	public:
		float m_DepthScanThickness;												// 0x1044
		float m_DepthScanR;														// 0x1048
		float m_DepthScanG;														// 0x104C
		float m_DepthScanB;														// 0x1050
		float m_DepthScanA;														// 0x1054
		float m_DepthScanOutlineThickness;										// 0x1058
		float m_DepthScanOutlineR;												// 0x105C
		float m_DepthScanOutlineG;												// 0x1060
		float m_DepthScanOutlineB;												// 0x1064
		float m_DepthScanOutlineA;												// 0x1068
		bool m_DepthScanOverlay;												// 0x106C
	private:
		char pad_106D[0x0003];													// 0x106D
	public:
		float m_DepthScanOverlayStrength;										// 0x1070
		float m_DepthScanOverlayXTiles;											// 0x1074
		float m_DepthScanOverlayYTiles;											// 0x1078
		float m_DepthScanOverlayXScroll;										// 0x107C
		float m_DepthScanOverlayYScroll;										// 0x1080
		float m_BlurSceneAdsInFraction;											// 0x1084
		float m_BlurSceneAdsOutFraction;										// 0x1088
		bool m_AltModeSameWeapon;												// 0x108C
		bool m_PlayAltGesturesForOffhandWeapons;								// 0x108D
		bool m_TurretBarrelSpinEnabled;											// 0x108E
		bool m_MissileConeSoundEnabled;											// 0x108F
		bool m_MissileConeSoundPitchShiftEnabled;								// 0x1090
		bool m_MissileConeSoundCrossfadeEnabled;								// 0x1091
		bool m_OffhandHoldIsCancelable;											// 0x1092
		bool m_DoNotAllowAttachmentsToOverrideSpread;							// 0x1093
		bool m_UseScopeDrift;													// 0x1094
		bool m_AlwaysShatterGlassOnImpact;										// 0x1095
		bool m_JumpSpread;														// 0x1096
		bool m_NoFullViewModelAnimations;										// 0x1097
		float m_KillcamOffset;													// 0x1098
		bool m_UseDualFOV;														// 0x109C
		bool m_ShowViewModelInDualFOV;											// 0x109D
		bool m_SyncedFOVInDualFOV;												// 0x109E
		bool m_DisableDrop;														// 0x109F
		bool m_PreferredDrop;													// 0x10A0
	private:
		char pad_10A1[0x0007];													// 0x10A1
	public:
		Gesture* m_GestureAnimation;											// 0x10A8
		float m_GestureFireStateTime;											// 0x10B0
	private:
		char pad_10B4[0x0004];													// 0x10B4
	public:
		Gesture* m_GesturePullback;												// 0x10B8
		Gesture* m_GesturePullbackAlt;											// 0x10C0
		float m_MinPullbackTime;												// 0x10C8
		float m_MinPullbackToThrowBlendTime;									// 0x10CC
		float m_MaxPullbackToThrowBlendTime;									// 0x10D0
	private:
		char pad_10D4[0x0004];													// 0x10D4
	public:
		Gesture* m_GestureThrow;												// 0x10D8
		Gesture* m_GestureThrowAlt;												// 0x10E0
		float m_GestureFireTime;												// 0x10E8
	private:
		char pad_10EC[0x0004];													// 0x10EC
	public:
		Gesture* m_GestureDetonate;												// 0x10F0
		Gesture* m_GestureDetonateAlt;											// 0x10F8
		float m_GestureDetonationTime;											// 0x1100
		bool m_GesturesDisablePrimary;											// 0x1104
	private:
		char pad_1105[0x0003];													// 0x1105
	public:
		FxCombinedDef m_CameraFireEffect;										// 0x1108
		float m_CameraFireEffectDurationSec;									// 0x1110
		float m_ChangedFireTime;												// 0x1114
		float m_ChangedFireTimeAkimbo;											// 0x1118
		int m_ChangedFireTimeNumBullets;										// 0x111C
		WeaponChargeType m_ChargeType;											// 0x1120
		float m_ChargeGain;														// 0x1124
		float m_ChargeCostPerShot;												// 0x1128
		float m_ChargeLossWhenIdle;												// 0x112C
		float m_ChargeEmptyCooldown;											// 0x1130
		float m_ChargeFireAtMaxDamageMultiplier;								// 0x1134
		int m_ChargeMeterEffectBoneCount;										// 0x1138
	private:
		char pad_113C[0x0004];													// 0x113C
	public:
		FxCombinedDef m_ChargeMeterEffect;										// 0x1140
		SndAliasLookup m_ChargeUpSound;											// 0x1148
		SndAliasLookup m_ChargeDownSound;										// 0x1150
		SndAliasLookup m_ChargeUpSoundPlayer;									// 0x1158
		SndAliasLookup m_ChargeDownSoundPlayer;									// 0x1160
		SndAliasLookup m_ChargeDownToUpSound;									// 0x1168
		SndAliasLookup m_ChargeDownToUpSoundPlayer;								// 0x1170
		SndAliasLookup m_ChargeUpToDownSound;									// 0x1178
		SndAliasLookup m_ChargeUpToDownSoundPlayer;								// 0x1180
		SndAliasLookup m_ChargeMaxSound;										// 0x1188
		SndAliasLookup m_ChargeMaxSoundPlayer;									// 0x1190
		bool m_ChargeHudReveal;													// 0x1198
	private:
		char pad_1199[0x0007];													// 0x1199
	public:
		RumbleInfo* m_ChargeRumble;												// 0x11A0
		scr_string_t m_StowTag;													// 0x11A8
	private:
		char pad_11AC[0x0004];													// 0x11AC
	public:
		XModel* m_StowOffsetModel;												// 0x11B0
		scr_string_t m_StowOffsetAttachTag;										// 0x11B8
		WeaponSlot m_Slot;														// 0x11BC
		float m_MaxTargetAngle;													// 0x11C0
		bool m_SpaceshipSecondaryWeapon;										// 0x11C4
	private:
		char pad_11C5[0x0003];													// 0x11C5
	public:
		float m_ImpulseFieldRadius;												// 0x11C8
		float m_ImpulseFieldInitialSpeed;										// 0x11CC
		float m_ImpulseFieldMaxSpeed;											// 0x11D0
		float m_ImpulseFieldAcceleration;										// 0x11D4
		float m_ImpulseFieldInAirImpulseMultiplier;								// 0x11D8
		float m_ImpulseFieldInAirImpulseMultiplierInterpTime;					// 0x11DC
		float m_ImpulseFieldSlideMultiplier;									// 0x11E0
		float m_ImpulseFieldSlideMultiplierInterpTime;							// 0x11E4
		bool m_ImpulseFieldIsPush;												// 0x11E8
		bool m_ImpulseFieldAffectsFriendlies;									// 0x11E9
		bool m_ImpulseFieldAffectsSelf;											// 0x11EA
		bool m_ImpulseFieldAffectsProne;										// 0x11EB
		bool m_RegenerationEnabled;												// 0x11EC
	private:
		char pad_11ED[0x0003];													// 0x11ED
	public:
		int m_RegenerationTimeMs;												// 0x11F0
		int m_RegenerationAddTimeMs;											// 0x11F4
		int m_RegenerationAmount;												// 0x11F8
		bool m_RegenerationConsumeStock;										// 0x11FC
		bool m_RegenerationDisableWhileFiring;									// 0x11FD
	private:
		char pad_11FE[0x0002];													// 0x11FE
	public:
		DeployType m_DeployType;												// 0x1200
		bool m_DeployRequireOnWalkableSurface;									// 0x1204
		bool m_DeployRequireOnNavMesh;											// 0x1205
		bool m_DeployRequireSkyAbove;											// 0x1206
		bool m_DeployRequireNoOverhang;											// 0x1207
		bool m_DeployAlwaysUpright;												// 0x1208
		bool m_DeployEdgeSnap;													// 0x1209
	private:
		char pad_120A[0x0002];													// 0x120A
	public:
		float m_DeployCylinderRadius;											// 0x120C
		float m_DeployCylinderHeight;											// 0x1210
		float m_DeployMaxDistance;												// 0x1214
		float m_DeployMaxHeightAboveEye;										// 0x1218
		float m_DeployEffectHeightOffset;										// 0x121C
		float m_DeployMaxSlope;													// 0x1220
	private:
		char pad_1224[0x0004];													// 0x1224
	public:
		FxCombinedDef m_DeployEffect;											// 0x1228
		ParticleGroupID m_DeployValidGroupId;									// 0x1230
		ParticleGroupID m_DeployIndoorGroupId;									// 0x1234
		ParticleGroupID m_DeployInvalidGroupId;									// 0x1238
		ParticleGroupID m_DeployOutOfRangeGroupId;								// 0x123C
		unsigned int m_NumAnimOverrides;										// 0x1240
	private:
		char pad_1244[0x0004];													// 0x1244
	public:
		AnimOverride* m_AnimOverrides;											// 0x1248
		/*
		CarryAnimOverride m_CarryAnimOverrides[5];								// 0x1250
		*/
		char m_CarryAnimOverrides[0x0078];										// 0x1250		
		unsigned int m_NumSfxOverrides;											// 0x12C8
	private:
		char pad_12CC[0x0004];													// 0x12CC
	public:
		SFXOverride* m_SFXOverrides;											// 0x12D0
		unsigned int m_NumVFXOverrides;											// 0x12D8
	private:
		char pad_12DC[0x0004];													// 0x12DC
	public:
		VFXOverride* m_VFXOverrides;											// 0x12E0
		float m_ReactiveEmitterDelay;											// 0x12E8
		float m_GrenadeDangerIconDistance;										// 0x12EC
		float m_BulletDirGunAngleModifierIdleHip;								// 0x12F0
		float m_BulletDirGunAngleModifierIdleAds;								// 0x12F4
		float m_BulletDirGunAngleModifierGunKickHip;							// 0x12F8
		float m_BulletDirGunAngleModifierGunKickAds;							// 0x12FC
		float m_BulletDirGunAngleModifierGunTiltHip;							// 0x1300
		float m_BulletDirGunAngleModifierGunTiltAds;							// 0x1304
		float m_ViewClampPitchCatchUpTimeSec;									// 0x1308
		float m_ViewClampYawCatchUpTimeSec;										// 0x130C
		bool m_MountTopEnable;													// 0x1310
		bool m_MountTopYawClamp;												// 0x1311
	private:
		char pad_1312[0x0002];													// 0x1312
	public:
		float m_MountTopYawMax;													// 0x1314
		float m_MountTopGunKickScale;											// 0x1318
		float m_MountTopGunCenterScale;											// 0x131C
		float m_MountTopViewKickScale;											// 0x1320
		float m_MountTopViewCenterScale;										// 0x1324
		float m_MountTopGunIdleMotionScale;										// 0x1328
		float m_MountTopViewIdleMotionScale;									// 0x132C
		int m_MountTopEnterDurationMs;											// 0x1330
		int m_MountTopExitDurationMs;											// 0x1334
		float m_MountTopEdgeToEyeDistanceForward;								// 0x1338
		float m_MountTopEdgeToEyeDistanceAbove;									// 0x133C
		bool m_MountSideEnable;													// 0x1340
		bool m_MountSideTransitionEnable;										// 0x1341
	private:
		char pad_1342[0x0002];													// 0x1342
	public:
		float m_MountSideRoll;													// 0x1344
		float m_MountSideRollStartFrac;											// 0x1348
		float m_MountSideRollEndFrac;											// 0x134C
		float m_MountSideGunKickScale;											// 0x1350
		float m_MountSideGunCenterScale;										// 0x1354
		float m_MountSideViewKickScale;											// 0x1358
		float m_MountSideViewCenterScale;										// 0x135C
		float m_MountSideGunIdleMotionScale;									// 0x1360
		float m_MountSideViewIdleMotionScale;									// 0x1364
		int m_MountSideEnterDurationMs;											// 0x1368
		int m_MountSideExitDurationMs;											// 0x136C
		float m_MountSideEdgeToEyeDistanceForward;								// 0x1370
		float m_MountSideEdgeToEyeDistanceAbove;								// 0x1374
		float m_MountViewModelOffset;											// 0x1378
		float m_MountFOVScale;													// 0x137C
		RumbleInfo* m_MountRumble;												// 0x1380
		WeaponOffsetPatternScaleInfo m_MountWeaponOffsetPatternScaleInfo;		// 0x1388
		float m_ADSFireMotionBlur;												// 0x1398
		int m_ADSFireMotionBlurDurationMs;										// 0x139C
		float m_ADSFireMotionBlurDecayExponent;									// 0x13A0
		float m_HipFireMotionBlur;												// 0x13A4
		int m_HipFireMotionBlurDurationMs;										// 0x13A8
		float m_HipFireMotionBlurDecayExponent;									// 0x13AC
		float m_ADSCameraShakeRotationScale;									// 0x13B0
		float m_ADSCameraShakeTranslationScale;									// 0x13B4
		AdvancedIdleSettings m_AdvancedIdleSettings;							// 0x13B8
		WeaponOffsetPatternScaleInfo m_CrouchedWeaponOffsetPatternScaleInfo;	// 0x1450
		WeaponOffsetPatternScaleInfo m_ProneWeaponOffsetPatternScaleInfo;		// 0x1460
		BallisticInfo m_BallisticInfo;											// 0x1470
		HyperBurstInfo m_HyperBurstInfo;										// 0x1498
	private:
		char pad_14A4[0x0004];													// 0x14A4
	public:
		WeaponEntityNotify* m_NotifyTypes[2];									// 0x14A8
		float m_DLCFloat[6];													// 0x14B8
		bool m_DLCBool[3];														// 0x14D0
		bool m_EnableWeaponInspect;												// 0x14D3
		bool m_StowedOcclusionTestEnabled;										// 0x14D4
		bool m_IgnoreMinTracerSpawnDistance;									// 0x14D5
		bool m_TracerOverrideEnabled;											// 0x14D6
		bool m_BoltActionReloadIncludesRechamber;								// 0x14D7
	};
	ENGINE_ASSERT_SZ(WeaponDef, 0x14D8);
}
