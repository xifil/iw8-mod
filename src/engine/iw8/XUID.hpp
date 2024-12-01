#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/msg_t.hpp"

namespace IW8 {
	struct XUID {
		std::uint64_t m_ID;

		void Deserialize(const msg_t* msg);
		void Serialize(const msg_t* msg);
		XUID* FromHexString(const char* xuidString);
		XUID* FromMsg(const msg_t* msg);
		XUID* FromString(const char* xuidString);
		XUID* FromUInt64(std::uint64_t id);
		XUID* FromUniversalId(std::uint64_t id);

		std::uint64_t GetUniversalId();

		bool IsNull();
		bool IsValid();

		XUID* NullXUID();
		XUID* RandomXUID();

		const char* ToDevString();
		const char* ToHexString();
		const char* ToString();

		bool operator !=(const XUID* xuid);
		XUID* operator =(const XUID* xuid);
		bool operator ==(const XUID* xuid);
	};
}
