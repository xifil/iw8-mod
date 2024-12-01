#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImage.hpp"
#include "engine/iw8/GfxDecalVolumeMaterial.hpp"
#include "engine/iw8/LuaFile.hpp"
#include "engine/iw8/MapEnts.hpp"
#include "engine/iw8/RawFile.hpp"
#include "engine/iw8/ReticleDef.hpp"
#include "engine/iw8/ScriptFile.hpp"
#include "engine/iw8/TracerDef.hpp"
#include "engine/iw8/TTFDef.hpp"
#include "engine/iw8/WeaponCompleteDef.hpp"

namespace IW8 {
	union XAssetHeader {
		//PhysicsLibrary* m_physicsLibrary;				// 0x0000
		//PhysicsSFXEventAsset* m_physicsSFXEventAsset;	// 0x0000
		//PhysicsVFXEventAsset* m_physicsVFXEventAsset;	// 0x0000
		//PhysicsAsset* m_physicsAsset;					// 0x0000
		//PhysicsFXPipeline* m_physicsFXPipeline;			// 0x0000
		//PhysicsFXShape* m_physicsFXShape;				// 0x0000
		//PhysicsDebugData* m_physicsDebugData;			// 0x0000
		//XAnimParts* m_parts;							// 0x0000
		//XModelSurfs* m_modelSurfs;						// 0x0000
		//XModel* m_model;								// 0x0000
		//MayhemData* m_mayhem;							// 0x0000
		//Material* m_material;							// 0x0000
		//ComputeShader* m_computeShader;					// 0x0000
		//MaterialSerializedShader* m_serializedShader;	// 0x0000
		//MaterialTechniqueSet* m_techniqueSet;			// 0x0000
		GfxImage* m_Image;								// 0x0000
		//SndGlobals* m_soundGlobals;						// 0x0000
		//SndBankResident* m_soundBankResident;			// 0x0000
		//SndBankTransient* m_soundBankTransient;			// 0x0000
		//clipMap_t* m_clipMap;							// 0x0000
		//ComWorld* m_comWorld;							// 0x0000
		//GlassWorld* m_glassWorld;						// 0x0000
		//PathData* m_pathData;							// 0x0000
		//NavMeshData* m_navMeshData;						// 0x0000
		//TacticalGraphData* m_tacGraphData;				// 0x0000
		MapEnts* m_MapEnts;								// 0x0000
		//FxWorld* m_fxWorld;								// 0x0000
		//GfxWorld* m_gfxWorld;							// 0x0000
		//GfxWorldTransientZone* m_gfxWorldTransientZone;	// 0x0000
		//GfxIESProfile* m_iesProfile;					// 0x0000
		//GfxLightDef* m_lightDef;						// 0x0000
		//GfxGradingClut* m_gradingClut;					// 0x0000
		//GfxFogSpline* m_fogSpline;						// 0x0000
		//AnimationClass* m_animClass;					// 0x0000
		//PlayerAnimScript* m_playerAnim;					// 0x0000
		//Gesture* m_gesture;								// 0x0000
		//LocalizeEntry* m_localize;						// 0x0000
		//WeaponAttachment* m_attachment;					// 0x0000
		WeaponCompleteDef* m_Weapon;					// 0x0000
		//ParticleSystemDef* m_vfx;						// 0x0000
		//FxImpactTable* m_impactFx;						// 0x0000
		//SurfaceFxTable* m_surfaceFx;					// 0x0000
		RawFile* m_RawFile;								// 0x0000
		ScriptFile* m_ScriptFile;						// 0x0000
		//ScriptDebugData* m_scriptDebugData;				// 0x0000
		//StringTable* m_stringTable;						// 0x0000
		//LeaderboardDef* m_leaderboardDef;				// 0x0000
		//VirtualLeaderboardDef* m_virtualLeaderboardDef;	// 0x0000
		//DDLFile* m_ddlFile;								// 0x0000
		TracerDef* m_TracerDef;							// 0x0000
		//VehicleDef* m_vehDef;							// 0x0000
		//AddonMapEnts* m_addonMapEnts;					// 0x0000
		//NetConstStrings* m_netConstStrings;				// 0x0000
		LuaFile* m_LuaFile;								// 0x0000
		//ScriptableDef* m_scriptable;					// 0x0000
		//EquipmentSoundTable* m_equipSndTable;			// 0x0000
		//VectorField* m_vectorField;						// 0x0000
		//FxParticleSimAnimation* m_particleSimAnimation;	// 0x0000
		//StreamingInfo* m_streamingInfo;					// 0x0000
		//LaserDef* m_laserDef;							// 0x0000
		TTFDef* m_TTFDef;								// 0x0000
		//SuitDef* m_suitDef;								// 0x0000
		//SuitAnimPackage* m_suitAnimPackage;				// 0x0000
		//CameraDef* m_cameraDef;							// 0x0000
		//HudOutlineDef* m_hudOutlineDef;					// 0x0000
		//SpaceshipTargetDef* m_spaceshipTargetDef;		// 0x0000
		//RumbleInfo* m_rumble;							// 0x0000
		//RumbleGraph* m_rumbleGraph;						// 0x0000
		//WeaponAnimPackage* m_weaponAnimPackage;			// 0x0000
		//WeaponSFXPackage* m_weaponSFXPackage;			// 0x0000
		//WeaponVFXPackage* m_weaponVFXPackage;			// 0x0000
		//FootstepVFX* m_footstepVFX;						// 0x0000
		//BehaviorTree* m_behaviorTree;					// 0x0000
		//Animset* m_animset;								// 0x0000
		//ASM* m_asmAsset;								// 0x0000
		//XAnimProceduralBones* m_proceduralBones;		// 0x0000
		//XAnimDynamicBones* m_dynamicBones;				// 0x0000
		ReticleDef* m_ReticleDef;						// 0x0000
		//XAnimCurve* m_xanimCurve;						// 0x0000
		//CoverSelector* m_coverSelector;					// 0x0000
		//EnemySelector* m_enemySelector;					// 0x0000
		//ClientCharacter* m_clientCharacter;				// 0x0000
		//ClothAsset* m_clothAsset;						// 0x0000
		//CinematicMotionDef* m_cinematicMotion;			// 0x0000
		//AccessoryDef* m_accessory;						// 0x0000
		//LocDmgTable* m_locDmgTable;						// 0x0000
		//BulletPenetration* m_bulletPenetration;			// 0x0000
		//ScriptBundle* m_scriptBundle;					// 0x0000
		//BlendSpace2DDef* m_blendSpace2DDef;				// 0x0000
		//XCam* m_xcam;									// 0x0000
		//Camo* m_camo;									// 0x0000
		//XCompositeModelDef* m_compositeModel;			// 0x0000
		//XModelDetailCollision* m_modelDetailCollision;	// 0x0000
		//StreamKey* m_streamKey;							// 0x0000
		//StreamTreeOverride* m_streamTreeOverride;		// 0x0000
		//KeyValuePairs* m_keyValuePairs;					// 0x0000
		//StTerrain* m_stTerrain;							// 0x0000
		//NativeScriptPatchFile* m_nativeScriptPatch;		// 0x0000
		//CollisionTile* m_collisionTile;					// 0x0000
		//ExecutionDef* m_executionDef;					// 0x0000
		//CarryObjectDef* m_carryObjectDef;				// 0x0000
		//SoundBankListDef* m_soundBankListDef;			// 0x0000
		GfxDecalVolumeMaterial* m_DecalVolumeMaterial;	// 0x0000
		//GfxDecalVolumeMask* m_decalVolumeMask;			// 0x0000
		//DynEntityList* m_dynEntityList;					// 0x0000
		void* m_Data;									// 0x0000
		//FxWorldTransientZone* m_fxWorldTransientZone;	// 0x0000
		//DLogSchema* m_dlogSchema;						// 0x0000
		//MapEdgeList* m_mapEdgeList;						// 0x0000
	};
	ENGINE_ASSERT_SZ(XAssetHeader, 0x0008);
}
