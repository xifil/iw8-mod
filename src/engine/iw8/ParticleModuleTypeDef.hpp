#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleModule.hpp"
#include "engine/iw8/ParticleModuleInitAtlas.hpp"
#include "engine/iw8/ParticleModuleInitAttributes.hpp"
#include "engine/iw8/ParticleModuleInitCameraOffset.hpp"
#include "engine/iw8/ParticleModuleInitCloud.hpp"
#include "engine/iw8/ParticleModuleInitFlare.hpp"
#include "engine/iw8/ParticleModuleInitGeoTrail.hpp"

namespace IW8 {
	union ParticleModuleTypeDef {
		ParticleModule m_ModuleBase;										// 0x0000
		ParticleModuleInitAtlas m_InitAtlas;								// 0x0000
		ParticleModuleInitAttributes m_InitAttributes;						// 0x0000
		//ParticleModuleInitBeam m_InitBeam;									// 0x0000
		ParticleModuleInitCameraOffset m_InitCameraOffset;					// 0x0000
		ParticleModuleInitCloud m_InitCloud;								// 0x0000
		//ParticleModuleInitDecal m_InitDecal;								// 0x0000
		ParticleModuleInitFlare m_InitFlare;								// 0x0000
		ParticleModuleInitGeoTrail m_InitGeoTrail;							// 0x0000
		//ParticleModuleInitKillWrapBox m_InitKillWrapBox;					// 0x0000
		//ParticleModuleInitLightOmni m_InitLightOmni;						// 0x0000
		//ParticleModuleInitLightSpot m_InitLightSpot;						// 0x0000
		//ParticleModuleInitMaterial m_InitMaterial;							// 0x0000
		//ParticleModuleInitMirrorTexture m_InitMirrorTexture;				// 0x0000
		//ParticleModuleInitModel m_InitModel;								// 0x0000
		//ParticleModuleInitOcclusionQuery m_InitOcclusionQuery;				// 0x0000
		//ParticleModuleInitOrientedSprite m_InitOrientedSprite;				// 0x0000
		//ParticleModuleInitParticleSim m_InitParticleSim;					// 0x0000
		//ParticleModuleInitPlayerFacing m_InitPlayerFacing;					// 0x0000
		//ParticleModuleInitRelativeVelocity m_InitRelativeVelocity;			// 0x0000
		//ParticleModuleInitRotation m_InitRotation;							// 0x0000
		//ParticleModuleInitRotation3D m_InitRotation3D;						// 0x0000
		//ParticleModuleInitRunner m_InitRunner;								// 0x0000
		//ParticleModuleInitSound m_InitSound;								// 0x0000
		//ParticleModuleInitSpawn m_InitSpawn;								// 0x0000
		//ParticleModuleInitSpawnShapeBox m_InitSpawnShapeBox;				// 0x0000
		//ParticleModuleInitSpawnShapeCylinder m_InitSpawnShapeCylinder;		// 0x0000
		//ParticleModuleInitSpawnShapeEllipsoid m_InitSpawnShapeEllipsoid;	// 0x0000
		//ParticleModuleInitSpawnShapeMesh m_InitSpawnShapeMesh;				// 0x0000
		//ParticleModuleInitSpawnShapeSphere m_InitSpawnShapeSphere;			// 0x0000
		//ParticleModuleInitTail m_InitTail;									// 0x0000
		//ParticleModuleInitVectorField m_InitVectorField;					// 0x0000
		//ParticleModuleInitVolumetric m_InitVolumetric;						// 0x0000
		//ParticleModuleInitDismember m_InitDismember;						// 0x0000
		//ParticleModuleAttractor m_Attractor;								// 0x0000
		//ParticleModuleColorGraph m_ColorGraph;								// 0x0000
		//ParticleModuleColorLerp m_ColorLerp;								// 0x0000
		//ParticleModuleEmissionGraph m_EmissionGraph;						// 0x0000
		//ParticleModuleEmissiveGraph m_EmissiveGraph;						// 0x0000
		//ParticleModuleShaderGraph m_ShaderGraph;							// 0x0000
		//ParticleModuleForce m_Force;										// 0x0000
		//ParticleModuleForceDragGraph m_ForceDragGraph;						// 0x0000
		//ParticleModuleGravity m_Gravity;									// 0x0000
		//ParticleModuleIntensityGraph m_IntensityGraph;						// 0x0000
		//ParticleModuleTemperatureGraph m_TemperatureGraph;					// 0x0000
		//ParticleModuleParentVelocityGraph m_ParentVelocityGraph;			// 0x0000
		//ParticleModulePhysicsLight m_PhysicsLight;							// 0x0000
		//ParticleModulePhysicsRayCast m_PhysicsRayCast;						// 0x0000
		//ParticleModulePositionGraph m_PositionGraph;						// 0x0000
		//ParticleModuleRotationGraph m_RotationGraph;						// 0x0000
		//ParticleModuleRotationGraph3D m_RotationGraph3D;					// 0x0000
		//ParticleModuleScaleByDistance m_ScaleByDistance;					// 0x0000
		//ParticleModuleSizeGraph m_SizeGraph;								// 0x0000
		//ParticleModuleSizeLerp m_SizeLerp;									// 0x0000
		//ParticleModuleVelocityGraph m_VelocityGraph;						// 0x0000
		//ParticleModuleVectorFieldGraph m_VectorFieldGraph;					// 0x0000
		//ParticleModuleTestAge m_TestAge;									// 0x0000
		//ParticleModuleTestBirth m_TestBirth;								// 0x0000
		//ParticleModuleTestDeath m_TestDeath;								// 0x0000
		//ParticleModuleTestGravity m_TestGravity;							// 0x0000
		//ParticleModuleTestImpact m_TestImpact;								// 0x0000
		//ParticleModuleTestPos m_TestPos;									// 0x0000
		//ParticleModuleTestTimeInState m_TestTimeInState;					// 0x0000

		char m_RawData[0x00E0];
	};
	ENGINE_ASSERT_SZ(ParticleModuleTypeDef, 0x00E0);
}
