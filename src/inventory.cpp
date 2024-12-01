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

void SaveInventory()
{
	auto DDL_MoveToPath = reinterpret_cast<bool(*)(const IW8::DDLState * fromState, IW8::DDLState * toState, int depth, const char** path)>(0x142052430_g);
	//auto Com_DDL_ConvertNavStringToHash = reinterpret_cast<int(*)(const char*)>(0x14129EE80_g);
	//auto LiveStorage_InitializeDDLStateForStatsGroup = reinterpret_cast<void(*)(const DDLDef * def, DDLState * state, int statsGroup)>(0x1410CAD70_g);
	//auto Com_PlayerData_GetStatsBlob = reinterpret_cast<int(*)(int)>(0x1410CA7A0_g);
	//auto DDL_GetType = reinterpret_cast<IW8::DDLType(*)(const IW8::DDLState*)>(0x142051DD0_g);
	auto DDL_GetString = reinterpret_cast<const char* (*)(const IW8::DDLState* state, const IW8::DDLContext* ddlContext)>(0x142051CD0_g);
	auto DDL_GetEnum = reinterpret_cast<const char* (*)(const IW8::DDLState* state, const IW8::DDLContext* ddlContext)>(0x1420519E0_g);
	auto DDL_GetInt = reinterpret_cast<int(*)(const IW8::DDLState* state, const IW8::DDLContext* ddlContext)>(0x142051BF0_g);
	auto DDL_GetRootState = reinterpret_cast<IW8::DDLState*(*)(IW8::DDLState* result, const IW8::DDLDef* ddlDef)>(0x142051C70_g);
	auto CL_PlayerData_GetDDLBuffer = reinterpret_cast<bool(*)(IW8::DDLContext* context, int controllerIndex, IW8::StatsSource statsSource, IW8::StatsGroup statsGroup)>(0x1415C7940_g);
	//auto Com_DDL_LoadAsset = reinterpret_cast<const IW8::DDLDef * (*)(const char* fileName)>(0x14129F3B0_g);
	auto Com_ParseNavStrings = reinterpret_cast<bool(*)(const char* pStr, const char** navStrings, int navStringMax, int* navStringCount)>(0x1412A02E0_g);
	//auto Com_DDL_CreateContext = reinterpret_cast<bool(*)(void* buffer, int len, const IW8::DDLDef * def, IW8::DDLContext* const ddlContext, uintptr_t a5, void* userData)>(0x14129EEC0_g);

	IW8::DDLContext context;
	IW8::DDLDef* ddlDef;
	IW8::DDLState state;
	char buffer[200];
	char* navStrings[32]{};
	int navStringCount;
	char path[MAX_PATH + 1];
	strcpy(path, g_Pointers->m_Dvar_GetStringSafe("fs_homepath"));
	strcat(path, "\\players\\inventory.json");
	nlohmann::json inventoryJson;
	if (CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_PRIVATELOADOUTS)) {
		ddlDef = (IW8::DDLDef*)context.m_Def;
		// start of operator customization related
		for (int i = 0; i < ddlDef->m_EnumCount; ++i) {
			if (!strcmp(ddlDef->m_EnumList[i].m_Name, "Operator")) {
				for (int j = 0; j < ddlDef->m_EnumList[i].m_MemberCount; ++j) {
					// get operator skins
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.skin", ddlDef->m_EnumList[i].m_Members[j]);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						int OP_opSkin = DDL_GetInt(&state, &context);
						inventoryJson["Operator"]["OperatorSkin"][ddlDef->m_EnumList[i].m_Members[j]] = OP_opSkin;
					}
					// execution ids
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.execution", ddlDef->m_EnumList[i].m_Members[j]);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Operator"]["OperatorExecution"][ddlDef->m_EnumList[i].m_Members[j]] = DDL_GetInt(&state, &context);
					}
					// voice lines
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.taunt", ddlDef->m_EnumList[i].m_Members[j]);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Operator"]["OperatorTaunt"][ddlDef->m_EnumList[i].m_Members[j]] = DDL_GetInt(&state, &context);
					}
				}
			}
		}
		// selected operator
		for (int i = 0; i < 2; ++i) {
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.operators.%d", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["Operator"]["SelectedOperator"][i] = DDL_GetEnum(&state, &context);
			}
		}
		// operator Index
		DDL_GetRootState(&state, ddlDef);
		sprintf_s(buffer, "customizationSetup.selectedOperatorIndex");
		Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
		if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
			inventoryJson["Operator"]["OperatorIndex"] = DDL_GetInt(&state, &context);
		}
		// operator watch
		DDL_GetRootState(&state, ddlDef);
		sprintf_s(buffer, "customizationSetup.operatorWatch");
		Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
		if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
			inventoryJson["Operator"]["OperatorWatch"] = DDL_GetInt(&state, &context);
		}
		// gesture wheel
		for (int i = 0; i < 8; ++i) {
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.radial.%d", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["GesturesAndSprays"][i] = { {"GesturesAndSpraysName", DDL_GetInt(&state, &context)} };
			}
		}
		// end of operator customization related

		// killstreak data
		for (int i = 0; i < 3; ++i) {
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.killstreakSetups.%d.killstreak", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["killstreak"][i] = { {"killstreakName", DDL_GetEnum(&state, &context)} };
			}
		}
		// field upgrades data
		for (int i = 0; i < 2; ++i) {
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.fieldUpgrades.%d", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["fieldUpgrades"][i] = { {"fieldUpgradesName", DDL_GetEnum(&state, &context)} };
			}
		}

		// start of weapon customization
		for (int i = 0; i < 10; ++i) {
			// get weapon
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "squadMembers.loadouts.%d.name", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				// test by getting loadout names
				inventoryJson["Loadouts"][i] = { {"name", DDL_GetString(&state, &context)} };
			}
			// loadoutPerks
			for (int b = 0; b < 3; ++b) {
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.loadoutPerks.%d", i, b);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["loadoutPerks"][b] = { {"loadoutPerksName", DDL_GetEnum(&state, &context)} };
				}
			}
			// equipment
			for (int a = 0; a < 2; ++a) {
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.equipmentSetups.%d.equipment", i, a);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["equipmentSetups"][a] = { {"equipmentName", DDL_GetEnum(&state, &context)} };
				}
			}
			for (int j = 0; j < 2; ++j) {
				// get camos
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.camo", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j] = { {"camo", DDL_GetEnum(&state, &context)} };
				}
				// get weapons
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.weapon", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "weapon", DDL_GetEnum(&state, &context) });
				}
				// get variant ids
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.variantID", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "variantId", DDL_GetInt(&state, &context) });
				}
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.lootItemID", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "lootItemID", DDL_GetInt(&state, &context) });
				}
				for (int k = 0; k < 5; ++k) {
					// get attachments & variants
					std::string attachmentName;
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.attachment", i, j, k);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						attachmentName = DDL_GetEnum(&state, &context);
					}

					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.variantID", i, j, k);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k] = { attachmentName.c_str(), DDL_GetInt(&state, &context) };
					}
				}
				// get sticker data
				for (int k = 0; k < 4; ++k) {
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.sticker.%d", i, j, k);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
						inventoryJson["Loadouts"][i]["weaponSetup"][j]["Sticker"][k] = {
							{ "StickerName", DDL_GetEnum(&state, &context) }
						};
					}
				}
				// get reticle customization
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.reticle", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "reticleName", DDL_GetEnum(&state, &context) });
				}
				// get charm data
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.cosmeticAttachment", i, j);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
					inventoryJson["Loadouts"][i]["weaponSetup"][j].push_back({ "cosmeticAttachmentName", DDL_GetEnum(&state, &context) });
				}
			}
		}
		printf("Saved Inventory!\n");
	}
	else {
		Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_PRIVATELOADOUTS, called before initialized?");
	}

	if (CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_NONGAME))
	{
		ddlDef = (IW8::DDLDef*)context.m_Def;
		for (int i = 0; i < 2; ++i)
		{
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "nonGameData.customization_patch.%d", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["customizationPatch"][i] = {
					{ "customizationPatchName", DDL_GetInt(&state, &context) }
				};
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "nonGameData.customization_background.%d", i);
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings)) {
				inventoryJson["customizationBackground"][i] = {
					{ "customizationBackgroundName", DDL_GetInt(&state, &context) }
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

void LoadInventory()
{
	//auto Cmd_LocalControllerIndex = reinterpret_cast<int(*)()>(0x141298040_g);
	//auto LiveStorage_GetActiveStatsSource = reinterpret_cast<int(*)(int)>(0x1412A1EB0_g);
	//auto LiveStorage_CreateDDLContext = reinterpret_cast<bool(*)(const int controllerIndex, int statsGroup, int statsSource, IW8::DDLContext * context, uintptr_t a5, void* userData)>(0x1412A13C0_g);
	auto DDL_MoveToPath = reinterpret_cast<bool(*)(const IW8::DDLState * fromState, IW8::DDLState * toState, int depth, const char** path)>(0x142052430_g);
	//auto Com_DDL_ConvertNavStringToHash = reinterpret_cast<int(*)(const char*)>(0x14129EE80_g);
	//auto LiveStorage_InitializeDDLStateForStatsGroup = reinterpret_cast<void(*)(const DDLDef * def, DDLState * state, int statsGroup)>(0x1410CAD70_g);
	//auto Com_PlayerData_GetStatsBlob = reinterpret_cast<int(*)(int)>(0x1410CA7A0_g);
	//auto DDL_GetType = reinterpret_cast<IW8::DDLType(*)(const IW8::DDLState*)>(0x142051DD0_g);
	//auto DDL_GetString = reinterpret_cast<const char* (*)(const IW8::DDLState * state, const IW8::DDLContext * ddlContext)>(0x142051CD0_g);
	//auto DDL_GetEnum = reinterpret_cast<const char* (*)(const IW8::DDLState * state, const IW8::DDLContext * ddlContext)>(0x1420519E0_g);
	//auto DDL_GetInt = reinterpret_cast<int(*)(const IW8::DDLState * state, const IW8::DDLContext * ddlContext)>(0x142051BF0_g);
	auto DDL_GetRootState = reinterpret_cast<IW8::DDLState * (*)(IW8::DDLState * result, const IW8::DDLDef * ddlDef)>(0x142051C70_g);
	auto CL_PlayerData_GetDDLBuffer = reinterpret_cast<bool(*)(IW8::DDLContext * context, int controllerIndex, IW8::StatsSource statsSource, IW8::StatsGroup statsGroup)>(0x1415C7940_g);
	//auto Com_DDL_LoadAsset = reinterpret_cast<const IW8::DDLDef * (*)(const char* fileName)>(0x14129F3B0_g);
	auto Com_ParseNavStrings = reinterpret_cast<bool(*)(const char* pStr, const char** navStrings, int navStringMax, int* navStringCount)>(0x1412A02E0_g);
	//auto Com_DDL_CreateContext = reinterpret_cast<bool(*)(void* buffer, int len, const IW8::DDLDef * def, IW8::DDLContext* const ddlContext, uintptr_t a5, void* userData)>(0x14129EEC0_g);
	//auto StringTable_GetColumnValueForRow = reinterpret_cast<const char* (*)(IW8::StringTable*, int, int)>(0x1413E2B40_g);
	auto DDL_SetInt = reinterpret_cast<void (*)(IW8::DDLState * param_1, IW8::DDLContext * param_2, int param_3)>(0x142052820_g);
	auto DDL_SetEnum = reinterpret_cast<bool(*)(IW8::DDLState * param_1, IW8::DDLContext * param_2, const char* param_3)>(0x142052710_g);
	auto DDL_SetString = reinterpret_cast<bool(*)(IW8::DDLState * param_1, IW8::DDLContext * param_2, const char* param_3)>(0x1420528D0_g);

	IW8::DDLContext context;
	IW8::DDLDef* ddlDef;
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
		if (CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_PRIVATELOADOUTS)) {
			ddlDef = (IW8::DDLDef*)context.m_Def;
			// start of operator customization related
			for (int i = 0; i < ddlDef->m_EnumCount; ++i)
			{
				if (!strcmp(ddlDef->m_EnumList[i].m_Name, "Operator")) {
					for (int j = 0; j < ddlDef->m_EnumList[i].m_MemberCount; ++j)
					{
						// operator skins
						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.skin", ddlDef->m_EnumList[i].m_Members[j]);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorSkin"][ddlDef->m_EnumList[i].m_Members[j]]);
						}
						// execution ids
						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.execution", ddlDef->m_EnumList[i].m_Members[j]);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorExecution"][ddlDef->m_EnumList[i].m_Members[j]]);
						}

						// voice lines
						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "customizationSetup.operatorCustomization.%s.taunt", ddlDef->m_EnumList[i].m_Members[j]);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorTaunt"][ddlDef->m_EnumList[i].m_Members[j]]);
						}
					}
				}
			}
			// selected operator
			for (int i = 0; i < 2; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "customizationSetup.operators.%d", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetEnum(&state, &context, inventoryJson["Operator"]["SelectedOperator"][i].get<std::string>().c_str());
				}
			}
			// operator Index
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.selectedOperatorIndex");
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
			{
				DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorIndex"]);
			}

			// operator watch
			DDL_GetRootState(&state, ddlDef);
			sprintf_s(buffer, "customizationSetup.operatorWatch");
			Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
			if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
			{
				DDL_SetInt(&state, &context, inventoryJson["Operator"]["OperatorWatch"]);
			}
			// gesture wheel
			for (int i = 0; i < 8; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "customizationSetup.radial.%d", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetInt(&state, &context, inventoryJson["GesturesAndSprays"][i]["GesturesAndSpraysName"]);

				}
			}
			// end of operator customization related

			// killstreak data
			for (int i = 0; i < 3; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.killstreakSetups.%d.killstreak", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetEnum(&state, &context, inventoryJson["killstreak"][i]["killstreakName"].get<std::string>().c_str());
				}
			}
			// field upgrades data
			for (int i = 0; i < 2; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.fieldUpgrades.%d", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetEnum(&state, &context, inventoryJson["fieldUpgrades"][i]["fieldUpgradesName"].get<std::string>().c_str());
				}
			}

			// start of weapon customization
			for (int i = 0; i < 10; ++i) {
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "squadMembers.loadouts.%d.name", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetString(&state, &context, inventoryJson["Loadouts"][i]["name"].get<std::string>().c_str());
				}
				// loadoutPerks
				for (int b = 0; b < 3; ++b)
				{
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.loadoutPerks.%d", i, b);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["loadoutPerks"][b]["loadoutPerksName"].get<std::string>().c_str());

					}
				}
				// equipment
				for (int a = 0; a < 2; ++a)
				{
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.equipmentSetups.%d.equipment", i, a);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["equipmentSetups"][a]["equipmentName"].get<std::string>().c_str());
					}
				}
				for (int j = 0; j < 2; ++j) {
					// set camo
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.camo", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["camo"].get<std::string>().c_str());
					}
					// set weapon
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.weapon", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["weapon"].get<std::string>().c_str());
					}
					// set variantid
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.variantID", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["variantId"]);
					}
					// set lootItemId
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.lootItemID", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["lootItemID"]);
					}
					for (int k = 0; k < 5; ++k) {
						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.attachment", i, j, k);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k][0].get<std::string>().c_str());
						}

						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.attachmentSetup.%d.variantID", i, j, k);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetInt(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["attachments"][k][1]);
						}
					}
					// set sticker data
					for (int k = 0; k < 4; ++k) {
						DDL_GetRootState(&state, ddlDef);
						sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.sticker.%d", i, j, k);
						Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
						if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
						{
							DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["Sticker"][k]["StickerName"].get<std::string>().c_str());
						}
					}
					// set reticle customization
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.reticle", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["reticleName"].get<std::string>().c_str());

					}
					// set charm data
					DDL_GetRootState(&state, ddlDef);
					sprintf_s(buffer, "squadMembers.loadouts.%d.weaponSetups.%d.cosmeticAttachment", i, j);
					Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
					if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
					{
						DDL_SetEnum(&state, &context, inventoryJson["Loadouts"][i]["weaponSetup"][j]["cosmeticAttachmentName"].get<std::string>().c_str());

					}
				}
			}
			printf("Loaded Inventory!\n");
		}
		else {
			Com_SetErrorMessage("[DLL ERROR] Couldn't get DDLBuffer for STATSGROUP_PRIVATELOADOUTS, called before initialized?");
		}

		if (CL_PlayerData_GetDDLBuffer(&context, 0, IW8::StatsSource::STATS_OFFLINE, IW8::StatsGroup::STATSGROUP_NONGAME))
		{
			ddlDef = (IW8::DDLDef*)context.m_Def;
			for (int i = 0; i < 2; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "nonGameData.customization_patch.%d", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetInt(&state, &context, inventoryJson["customizationPatch"][i]["customizationPatchName"]);
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				DDL_GetRootState(&state, ddlDef);
				sprintf_s(buffer, "nonGameData.customization_background.%d", i);
				Com_ParseNavStrings(buffer, (const char**)navStrings, 32, &navStringCount);
				if (DDL_MoveToPath(&state, &state, navStringCount, (const char**)navStrings))
				{
					DDL_SetInt(&state, &context, inventoryJson["customizationBackground"][i]["customizationBackgroundName"]);
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