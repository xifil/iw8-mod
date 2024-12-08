#include "addr_utils.hpp"
#include "inventory.h"
#include "game_inc.h"
#include "functions.hpp"

#include "engine/iw8/DDLContext.hpp"
#include "engine/iw8/DDLDef.hpp"
#include "engine/iw8/DDLState.hpp"
#include "engine/iw8/StringTable.hpp"
#include "engine/iw8/enums/DDLType.hpp"
#include "engine/iw8/enums/StatsGroup.hpp"
#include "engine/iw8/enums/StatsSource.hpp"

#include "game/game.hpp"

void SaveInventory() {
	IW8::DDLContext context;
	const IW8::DDLDef* ddlDef = nullptr;
	IW8::DDLState state;
	char buffer[200];
	char* navStrings[32]{};
	int navStringCount;
	char path[MAX_PATH + 1];
	strcpy(path, g_Pointers->m_Dvar_GetStringSafe("fs_homepath"));
	strcat(path, "\\players\\inventory.json");
	nlohmann::json inventoryJson;
	if (g_Pointers->m_CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_PRIVATELOADOUTS)) {
		ddlDef = context.m_Def;
		// start of operator customization related
		for (int i = 0; i < ddlDef->m_EnumCount; ++i) {
			if (!strcmp(ddlDef->m_EnumList[i].m_Name, "Operator")) {
				for (int j = 0; j < ddlDef->m_EnumList[i].m_MemberCount; ++j) {
					// get operator skins
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.skin", ddlDef->m_EnumList[i].m_Members[j]);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						int OP_opSkin = g_Pointers->m_DDL_GetInt(&state, &context);
						inventoryJson["Operator"]["OperatorSkin"][ddlDef->m_EnumList[i].m_Members[j]] = OP_opSkin;
					}
					// execution ids
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.execution", ddlDef->m_EnumList[i].m_Members[j]);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Operator"]["OperatorExecution"][ddlDef->m_EnumList[i].m_Members[j]] = g_Pointers->m_DDL_GetInt(&state, &context);
					}
					// voice lines
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.taunt", ddlDef->m_EnumList[i].m_Members[j]);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Operator"]["OperatorTaunt"][ddlDef->m_EnumList[i].m_Members[j]] = g_Pointers->m_DDL_GetInt(&state, &context);
					}
				}
			}
		}
		// selected operator
		for (int i = 0; i < 2; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.operators.%d", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["Operator"]["SelectedOperator"][i] = g_Pointers->m_DDL_GetEnum(&state, &context);
			}
		}
		// operator Index
		g_Pointers->m_DDL_GetRootState(&state, ddlDef);
		sprintf_s(buffer, "customizationSetup.selectedOperatorIndex");
		g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
		if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
			inventoryJson["Operator"]["OperatorIndex"] = g_Pointers->m_DDL_GetInt(&state, &context);
		}
		// operator watch
		g_Pointers->m_DDL_GetRootState(&state, ddlDef);
		sprintf_s(buffer, "customizationSetup.operatorWatch");
		g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
		if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
			inventoryJson["Operator"]["OperatorWatch"] = g_Pointers->m_DDL_GetInt(&state, &context);
		}
		// gesture wheel
		for (int i = 0; i < 8; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.radial.%d", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["GesturesAndSprays"][i] = {
					{ "GesturesAndSpraysName", g_Pointers->m_DDL_GetInt(&state, &context) }
				};
			}
		}
		// end of operator customization related

		// killstreak data
		for (int i = 0; i < 3; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.killstreakSetups.%d.killstreak", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["killstreak"][i] = {
					{ "killstreakName", g_Pointers->m_DDL_GetEnum(&state, &context) }
				};
			}
		}
		// field upgrades data
		for (int i = 0; i < 2; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.fieldUpgrades.%d", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["fieldUpgrades"][i] = {
					{ "fieldUpgradesName", g_Pointers->m_DDL_GetEnum(&state, &context) }
				};
			}
		}

		// start of weapon customization
		for (int i = 0; i < 10; ++i) {
			// get weapon
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.loadouts.%d.name", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				// test by getting loadout names
				inventoryJson["Loadouts"][i] = {
					{ "name", g_Pointers->m_DDL_GetString(&state, &context) }
				};
			}
			// loadoutPerks
			for (int b = 0; b < 3; ++b) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.loadoutPerks.%d", i, b);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["loadoutPerks"][b] = {
						{ "loadoutPerksName", g_Pointers->m_DDL_GetEnum(&state, &context) }
					};
				}
			}
			// equipment
			for (int a = 0; a < 2; ++a) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.equipmentSetups.%d.equipment", i, a);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["equipmentSetups"][a] = {
						{ "equipmentName", g_Pointers->m_DDL_GetEnum(&state, &context) }
					};
				}
			}
			for (int j = 0; j < 2; ++j) {
				// get camos
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.camo", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j] = {
						{ "camo", g_Pointers->m_DDL_GetEnum(&state, &context) }
					};
				}
				// get weapons
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.weapon", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "weapon", g_Pointers->m_DDL_GetEnum(&state, &context) });
				}
				// get variant ids
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.variantID", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "variantId", g_Pointers->m_DDL_GetInt(&state, &context) });
				}
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.lootItemID", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "lootItemID", g_Pointers->m_DDL_GetInt(&state, &context) });
				}
				for (int k = 0; k < 5; ++k) {
					// get attachments & variants
					std::string attachmentName;
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.attachment", i, j, k);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						attachmentName = g_Pointers->m_DDL_GetEnum(&state, &context);
					}

					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.variantID", i, j, k);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k] = { attachmentName.c_str(), g_Pointers->m_DDL_GetInt(&state, &context) };
					}
				}
				// get sticker data
				for (int k = 0; k < 4; ++k) {
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.sticker.%d", i, j, k);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Loadouts"][i]["weaponSetup"][j]["Sticker"][k] = {
							{ "StickerName", g_Pointers->m_DDL_GetEnum(&state, &context) }
						};
					}
				}
				// get reticle customization
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.reticle", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "reticleName", g_Pointers->m_DDL_GetEnum(&state, &context) });
				}
				// get charm data
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.cosmeticAttachment", i, j);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "cosmeticAttachmentName", g_Pointers->m_DDL_GetEnum(&state, &context) });
				}
			}
		}
		printf("Saved Inventory!\n");
	}
	else {
		Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_PRIVATELOADOUTS, called before initialized?");
	}

	if (g_Pointers->m_CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_NONGAME)) {
		ddlDef = (IW8::DDLDef*)context.m_Def;
		for (int i = 0; i < 2; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "nonGameData.customization_patch.%d", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["customizationPatch"][i] = {
					{ "customizationPatchName", g_Pointers->m_DDL_GetInt(&state, &context) }
				};
			}
		}
		for (int i = 0; i < 2; ++i) {
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "nonGameData.customization_background.%d", i);
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["customizationBackground"][i] = {
					{ "customizationBackgroundName", g_Pointers->m_DDL_GetInt(&state, &context) }
				};
			}
		}
		printf("Saved Customizations!\n");
	}
	else {
		Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_NONGAME, called before initialized?");
	}

	std::ofstream JsonOut(path);
	JsonOut << inventoryJson;

}

void LoadInventory() {
	IW8::DDLContext context;
	const IW8::DDLDef* ddlDef = nullptr;
	IW8::DDLState state;
	char buffer[200];
	char* navStrings[32]{};
	int navStringCount;
	char path[MAX_PATH + 1];
	strcpy(path, g_Pointers->m_Dvar_GetStringSafe("fs_homepath"));
	strcat(path, "\\players\\inventory.json");
	if (file_exists(path)) {
		std::ifstream jsonPath(path);
		nlohmann::json inventoryJson = nlohmann::json::parse(jsonPath);
		if (g_Pointers->m_CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_PRIVATELOADOUTS)) {
			ddlDef = context.m_Def;

			// start of operator customization related
			for (int i = 0; i < ddlDef->m_EnumCount; ++i) {
				if (!strcmp(ddlDef->m_EnumList[i].m_Name, "Operator")) {
					for (int j = 0; j < ddlDef->m_EnumList[i].m_MemberCount; ++j) {
						// operator skins
						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.skin", ddlDef->m_EnumList[i].m_Members[j]);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorSkin"][ddlDef->m_EnumList[i].m_Members[j]]);
						}

						// execution ids
						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.execution", ddlDef->m_EnumList[i].m_Members[j]);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorExecution"][ddlDef->m_EnumList[i].m_Members[j]]);
						}

						// voice lines
						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.taunt", ddlDef->m_EnumList[i].m_Members[j]);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorTaunt"][ddlDef->m_EnumList[i].m_Members[j]]);
						}
					}
				}
			}

			// selected operator
			for (int i = 0; i < 2; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "customizationSetup.operators.%d", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Operator"]["SelectedOperator"][i].get<std::string>().c_str());
				}
			}

			// operator Index
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.selectedOperatorIndex");
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorIndex"]);
			}

			// operator watch
			g_Pointers->m_DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.operatorWatch");
			g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorWatch"]);
			}

			// gesture wheel
			for (int i = 0; i < 8; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "customizationSetup.radial.%d", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["GesturesAndSprays"][i]["GesturesAndSpraysName"]);
				}
			}

			// end of operator customization related

			// killstreak data
			for (int i = 0; i < 3; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.killstreakSetups.%d.killstreak", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["killstreak"][i]["killstreakName"].get<std::string>().c_str());
				}
			}

			// field upgrades data
			for (int i = 0; i < 2; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.fieldUpgrades.%d", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["fieldUpgrades"][i]["fieldUpgradesName"].get<std::string>().c_str());
				}
			}

			// start of weapon customization
			for (int i = 0; i < 10; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.name", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetString(&state, &context, inventoryJson["Loadouts"][i]["name"].get<std::string>().c_str());
				}

				// loadoutPerks
				for (int b = 0; b < 3; ++b) {
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.loadoutPerks.%d", i, b);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["loadoutPerks"][b]["loadoutPerksName"].get<std::string>().c_str());
					}
				}

				// equipment
				for (int a = 0; a < 2; ++a) {
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.equipmentSetups.%d.equipment", i, a);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["equipmentSetups"][a]["equipmentName"].get<std::string>().c_str());
					}
				}

				for (int j = 0; j < 2; ++j) {
					// set camo
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.camo", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["camo"].get<std::string>().c_str());
					}

					// set weapon
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.weapon", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["weapon"].get<std::string>().c_str());
					}

					// set variantid
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.variantID", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["variantId"]);
					}

					// set lootItemId
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.lootItemID", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["lootItemID"]);
					}
					for (int k = 0; k < 5; ++k) {
						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.attachment", i, j, k);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k][0].get<std::string>().c_str());
						}

						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.variantID", i, j, k);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k][1]);
						}
					}

					// set sticker data
					for (int k = 0; k < 4; ++k) {
						g_Pointers->m_DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.sticker.%d", i, j, k);
						g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
							g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["Sticker"][k]["StickerName"].get<std::string>().c_str());
						}
					}

					// set reticle customization
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.reticle", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["reticleName"].get<std::string>().c_str());
					}

					// set charm data
					g_Pointers->m_DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.cosmeticAttachment", i, j);
					g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						g_Pointers->m_DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["cosmeticAttachmentName"].get<std::string>().c_str());
					}
				}
			}
			printf("Loaded Inventory!\n");
		}
		else {
			Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_PRIVATELOADOUTS, called before initialized?");
		}

		if (g_Pointers->m_CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_NONGAME)) {
			ddlDef = (IW8::DDLDef*)context.m_Def;
			for (int i = 0; i < 2; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "nonGameData.customization_patch.%d", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["customizationPatch"][i]["customizationPatchName"]);
				}
			}
			for (int i = 0; i < 2; ++i) {
				g_Pointers->m_DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "nonGameData.customization_background.%d", i);
				g_Pointers->m_Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (g_Pointers->m_DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					g_Pointers->m_DDL_SetInt(&state, &context, inventoryJson["customizationBackground"][i]["customizationBackgroundName"]);
				}
			}
			printf("Loaded Customizations!\n");
		}
		else {
			Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_NONGAME, called before initialized?");
		}
	}
	else {
		// Com_SetErrorMessage("[DLL ERROR] Attempted to load inventory from \"players/inventory.json\" but file does not exist. Use 'saveinv' to save your inventory.");
		printf("Attempted to load inventory from \"players/inventory.json\" but file does not exist\n");
	}
}