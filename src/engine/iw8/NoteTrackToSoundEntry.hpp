#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class NoteTrackToSoundEntry {
	public:
		std::uint32_t m_NumSoundMappings;			// 0x0000
		scr_string_t m_Attachment;					// 0x0004
		scr_string_t* m_NoteTrackSoundMapKeys;		// 0x0008
		scr_string_t* m_NoteTrackSoundMapValues;	// 0x0010
	};
	ENGINE_ASSERT_SZ(NoteTrackToSoundEntry, 0x0018);
}
