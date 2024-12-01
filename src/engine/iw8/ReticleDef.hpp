#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ReticleDef {
	public:
		const char* m_Name;					// 0x0000
		const char* m_WidgetName;			// 0x0008
		bool m_LockReticleToTag;			// 0x0010
		bool m_PrimaryAffectedByEMP;		// 0x0011
		bool m_SecondaryAffectedByEMP;		// 0x0012
	private:
		char pad_0013[0x0001];				// 0x0013
	public:
		float m_OffsetFromTag;				// 0x0014
		bool m_ScaleWithFOV;				// 0x0018
	private:
		char pad_0019[0x0003];				// 0x0019
	public:
		float m_PrimaryDefaultScale;		// 0x001C
		float m_SecondaryDefaultScale;		// 0x0020
	private:
		char pad_0024[0x0004];				// 0x0024
	public:
		const char* m_SecondaryWidgetName;	// 0x0028
		bool m_SecondaryLockReticleToTag;	// 0x0030
	private:
		char pad_0031[0x0003];				// 0x0031
	public:
		float m_SecondaryOffsetFromTag;		// 0x0034
		float m_NaturalDistance;			// 0x0038
		int m_NaturalFOV;					// 0x003C
		float m_MinReticleScale;			// 0x0040
		float m_MaxReticleScale;			// 0x0044
	};
	ENGINE_ASSERT_SZ(ReticleDef, 0x0048);
}
