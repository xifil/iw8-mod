#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/AudioPASpeaker.hpp"
#include "engine/iw8/AudioPropagationEdge.hpp"
#include "engine/iw8/AudioPropagationNode.hpp"
#include "engine/iw8/ClientTriggerBlend.hpp"
#include "engine/iw8/ClientTriggers.hpp"
#include "engine/iw8/cmodel_t.hpp"
#include "engine/iw8/CollMapLookupEntry.hpp"
#include "engine/iw8/CreateFxAssetData.hpp"
#include "engine/iw8/MapEdgeList.hpp"
#include "engine/iw8/MapTriggers.hpp"
#include "engine/iw8/ServerSideEffects.hpp"
#include "engine/iw8/SpatialPartition_Population_Node.hpp"
#include "engine/iw8/SpatialPartition_Population_TransientMap.hpp"
#include "engine/iw8/SpatialPartition_Tree.hpp"
#include "engine/iw8/SpawnerList.hpp"
#include "engine/iw8/SpawnGroup.hpp"
#include "engine/iw8/SpawnPointRecordList.hpp"
#include "engine/iw8/SplineRecordList.hpp"
#include "engine/iw8/enums/DynEntityListId.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class MapEnts {
	public:
		const char* m_Name;															// 0x0000
		char* m_EntityString;														// 0x0008
		int m_NumEntityChars;														// 0x0010
	private:
		char pad_0014[0x0004];														// 0x0014
	public:
		MapTriggers m_Trigger;														// 0x0018
		ClientTriggers m_ClientTrigger;												// 0x0068
		ClientTriggerBlend m_ClientTriggerBlend;									// 0x0118
		SpawnPointRecordList m_SpawnList;											// 0x0128
		SplineRecordList m_SplineList;												// 0x0138
		std::uint32_t m_HavokEntsShapeDataSize;										// 0x0148
	private:
		char pad_014C[0x0004];														// 0x014C
	public:
		char* m_HavokEntsShapeData;													// 0x0150
		std::uint32_t m_NumSubModels;												// 0x0158
	private:
		char pad_015C[0x0004];														// 0x015C
	public:
		cmodel_t* m_CModels;														// 0x0160
		std::uint32_t m_EdgeListUsedQueryTypes;										// 0x0168
		std::uint32_t m_NumEdgeLists;												// 0x016C
		MapEdgeList** m_EdgeLists;													// 0x0170
		SpatialPartition_Tree* m_EdgeListSpatialTree;								// 0x0178
		std::uint32_t m_NumClientModels;											// 0x0180
	private:
		char pad_0184[0x0004];														// 0x0184
	public:
		/*
		CM_ClientModel* m_ClientModels;												// 0x0188
		*/
		char m_ClientModels[0x0008];												// 0x0188
		std::uint32_t m_DynEntCount[2];												// 0x0190
		std::uint32_t m_DynEntCountTotal;											// 0x0198
		DynEntityListId m_DynEntityListsCount;										// 0x019C
	private:
		char pad_019E[0x0002];														// 0x019E
	public:
		DynEntityListId* m_DynEntListIds;											// 0x01A0
		std::uint16_t m_DynEntPhysicsSetupHead[2][2];								// 0x01A8
		std::uint16_t m_DynEntPhysicsSetupTail[2][2];								// 0x01B0
		std::uint16_t m_DynEntNoSpatialCount[2];									// 0x01B8
		std::uint16_t m_DynEntMaxClientHistoryCount;								// 0x01BC
		std::uint8_t m_DynEntMaxPosePartCount;										// 0x01BE
	private:
		char pad_01BF[0x0001];														// 0x01BF
	public:
		std::uint32_t m_DynEntsWithExtraPosePartsCount;								// 0x01C0
	private:
		char pad_01C4[0x0004];														// 0x01C4
	public:
		/*
		SpatialPartition_Population* m_DynEntSpatialPopulation[2];					// 0x01C8
		*/
		char m_DynEntSpatialPopulation[0x0010];										// 0x01C8
		SpatialPartition_Population_TransientMap* m_DynEntSpatialTransientMap[2];	// 0x01D8
		SpatialPartition_Population_Node m_DynEntNoSpatialList;						// 0x01E8
		std::uint32_t m_ClientEntAnchorCount;										// 0x01EC
		/*
		ClientEntAnchor* m_ClientEntAnchors;										// 0x01F0
		*/
		char m_ClientEntAnchors[0x0008];											// 0x01F0
		/*
		ScriptableMapEnts m_ScriptableMapEnts;										// 0x01F8
		*/
		char m_ScriptableMapEnts[0x00D8];											// 0x01F8
		SpawnGroup m_SpawnGroupLoot;												// 0x02D0
		/*
		ClientSideEffects m_ClientSideEffects;										// 0x0300
		*/
		char m_ClientSideEffects[0x0098];											// 0x0300
		CreateFxAssetData m_CreateFxAssetData;										// 0x0398
		std::uint32_t m_ExploderNameTotal;											// 0x03A8
	private:
		char pad_03AC[0x0004];														// 0x03AC
	public:
		scr_string_t* m_ExploderNames;												// 0x03B0
		ServerSideEffects m_ServerSideEffects;										// 0x03B8
		std::uint32_t m_CreateFxEffectTotal;										// 0x03C8
		std::uint32_t m_NumMayhemScenes;											// 0x03CC
		/*
		MayhemInstance* m_MayhemScenes;												// 0x03D0
		*/
		char m_MayhemScenes[0x0008];												// 0x03D0
		SpawnerList m_Spawners;														// 0x03D8
		std::uint32_t m_AudioPASpeakerCount;										// 0x03E8
	private:
		char pad_03EC[0x0004];														// 0x03EC
	public:
		AudioPASpeaker* m_AudioPASpeakers;											// 0x03F0
		std::uint32_t m_NumAudioPropNodes;											// 0x03F8
	private:
		char pad_03FC[0x0004];														// 0x03FC
	public:
		AudioPropagationNode* m_AudioPropNodes;										// 0x0400
		std::uint32_t m_NumAudioPropEdges;											// 0x0408
	private:
		char pad_040C[0x0004];														// 0x040C
	public:
		AudioPropagationEdge* m_AudioPropEdges;										// 0x0410
		std::uint32_t m_NumCollMaps;												// 0x0418
	private:
		char pad_041C[0x0004];														// 0x041C
	public:
		CollMapLookupEntry* m_CollMapLookups;										// 0x0420
	};
	ENGINE_ASSERT_SZ(MapEnts, 0x0428);
}
