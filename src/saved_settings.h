#pragma once
#include "json.hpp"
#include <string>

namespace saved_settings {
	void Save();
	void Load();

	inline std::string g_player_name = "Unknown Soldier";
	inline bool g_unlock_all_enabled = false;
}
