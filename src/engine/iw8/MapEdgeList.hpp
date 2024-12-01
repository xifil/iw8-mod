#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/EdgeAdjacency.hpp"
#include "engine/iw8/EdgeAdjacencyMetadata.hpp"
#include "engine/iw8/FlaggedEdgeMetadata.hpp"
#include "engine/iw8/float4.hpp"
#include "engine/iw8/PMROctreeMetadata.hpp"
#include "engine/iw8/PMROctreeNodeSet.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class MapEdgeList {
	public:
		const char* m_Name;								// 0x0000
		vec3_t m_Mins;									// 0x0008
		vec3_t m_Maxs;									// 0x0014
		std::uint32_t m_TransientIndex;					// 0x0020
		std::uint32_t m_DynamicQueryTypes;				// 0x0024
		std::uint32_t m_StaticQueryTypes;				// 0x0028
		std::uint32_t m_NumDynamicEdges;				// 0x002C
		std::uint32_t m_NumStaticEdges;					// 0x0030
		bool m_Valid;									// 0x0034
	private:
		char pad_0035[0x0003];							// 0x0035
	public:
		std::uint32_t m_NumEdges;						// 0x0038
	private:
		char pad_003C[0x0004];							// 0x003C
	public:
		float4(*m_Edges)[2];							// 0x0040
		FlaggedEdgeMetadata* m_EdgeMetadata;			// 0x0048
		std::uint32_t m_NumEdgeOctrees;					// 0x0050
	private:
		char pad_0054[0x0004];							// 0x0054
	public:
		PMROctreeMetadata* m_EdgeOctrees;				// 0x0058
		std::uint32_t m_NumEdgeOctreeNodeSet;			// 0x0060
	private:
		char pad_0064[0x0004];							// 0x0064
	public:
		PMROctreeNodeSet* m_EdgeOctreeNodeSets;			// 0x0068
		std::uint32_t m_NumEdgeIndices;					// 0x0070
	private:
		char pad_0074[0x0004];							// 0x0074
	public:
		std::uint32_t* m_EdgeIndices;					// 0x0078
		std::uint32_t m_NumEdgeAdjacencyMetadata;		// 0x0080
	private:
		char pad_0084[0x0004];							// 0x0084
	public:
		EdgeAdjacencyMetadata* m_EdgeAdjacencyMetadata;	// 0x0088
		std::uint32_t m_NumEdgeAdjacency;				// 0x0090
	private:
		char pad_0094[0x0004];							// 0x0094
	public:
		EdgeAdjacency* m_EdgeAdjacency;					// 0x0098
	};
	ENGINE_ASSERT_SZ(MapEdgeList, 0x00A0);
}
