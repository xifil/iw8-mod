#include "saved_settings.h"
#include "functions.hpp"
#include <fstream>
#include <ostream>
#include <iostream>
#include "game/game.hpp"

namespace saved_settings {
    const char* GetPath() {
        return _va("%s\\%s", g_Pointers->m_Dvar_GetStringSafe("fs_homepath"), "iw8-mod.json");
    }

	void Save() {
        nlohmann::json jsonData;

        jsonData["player_name"] = g_player_name;
        jsonData["unlock_all_enabled"] = g_unlock_all_enabled;

        std::ofstream file(GetPath());
        if (file.is_open()) {
            file << jsonData.dump(4);
            file.close();
        }
	}

	void Load() {
        if (!std::filesystem::exists(GetPath())) {
            Save();
        }

        // Open the JSON file
        std::ifstream file(GetPath());
        if (!file.is_open()) {
            std::cerr << "Failed to open the file for reading!" << std::endl;
        }

        try {
            nlohmann::json jsonData;
            file >> jsonData;

            g_player_name = jsonData.value("player_name", g_player_name);
            g_unlock_all_enabled = jsonData.value("unlock_all_enabled", g_unlock_all_enabled);
        }
        catch (const nlohmann::json::exception& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }
	}
}
