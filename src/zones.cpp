#include "addr_utils.hpp"
#include "zones.h"
#include "game_inc.h"
#include "functions.hpp"
#include "game/game.hpp"

IW8::XAssetHeader DB_FindXAssetHeader_Detour(IW8::XAssetType type, const char* givenName, int allowCreateDefault)
{
	IW8::XAssetHeader temp = db_findxassetheader.stub<IW8::XAssetHeader>(type, givenName, allowCreateDefault);

	//if (type == ASSET_TYPE_XMODEL) {
	//	if (strcmp(temp.model->name, "head_mp_western_ghost_1_1") == 0) {
	//		return db_findxassetheader.stub<XAssetHeader>(type, "head_opforce_juggernaut", allowCreateDefault);
	//	}
	//	if (strcmp(temp.model->name, "mp_western_vm_arms_ghost_1_1") == 0) {
	//		return db_findxassetheader.stub<XAssetHeader>(type, "viewhands_opforce_juggernaut", allowCreateDefault);
	//	}
	//	if (strcmp(temp.model->name, "body_mp_western_ghost_1_1_lod1") == 0) {
	//		return db_findxassetheader.stub<XAssetHeader>(type, "body_opforce_juggernaut_mp_lod1", allowCreateDefault);
	//	}
	//	if (strcmp(temp.model->name, "military_carepackage_01_friendly") == 0) {
	//		return db_findxassetheader.stub<XAssetHeader>(type, "opforce_juggernaut_prop_static", allowCreateDefault);
	//	}
	//	if (strstr(temp.model->name, "veh8_mil_air_")) {
	//		return db_findxassetheader.stub<XAssetHeader>(type, "veh8_mil_air_acharlie130", allowCreateDefault);
	//	}
	//}

	return temp;
}

const char* DB_GetRawBufferInflate_Detour(const char* file, char* buffer, int length)
{
	char path[MAX_PATH + 1];
	memset(path, 0, MAX_PATH + 1);
	std::string filecontents;
	std::string curline;
	snprintf(path, MAX_PATH + 1, "%s\\players\\raw\\%s", g_Pointers->m_Dvar_GetStringSafe("fs_homepath"), file);
	if (file_exists(path)) {
		printf("[DB_GetRawBufferInflate] replacing file %s\n", file);
		std::ifstream myfile;
		myfile.open(path);
		filecontents = "";
		while (myfile) {
			std::getline(myfile, curline);
			filecontents += curline + "\n";
		}
		myfile.close();
		strcpy(buffer, filecontents.c_str());
		printf("[DB_GetRawBufferInflate] loading %s\n", path);
		return filecontents.c_str();
	}
	printf("[DB_GetRawBufferInflate] loading %s\n", file);
	return db_getrawbufferinflate.stub<const char*>(file, buffer, length);
}

void Load_MapEntsAsset_Detour(IW8::XAssetHeader* mapEnts)
{
	auto Scr_AllocGlobalString = reinterpret_cast<IW8::scr_string_t(*)(const char*)>(0x14131B2C0_g);
	char path[MAX_PATH + 1];
	snprintf(path, MAX_PATH + 1, "%s\\players\\raw\\%s", g_Pointers->m_Dvar_GetStringSafe("fs_homepath"), mapEnts->m_Image->m_Name);
	if (file_exists(path)) {
		printf("[Load_MapEntsAsset] loading %s\n", path);
		HANDLE mapEntsFile = CreateFileA(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(mapEntsFile, NULL);
		if (mapEntsFile != INVALID_HANDLE_VALUE)
		{
			memset(g_customEntityString, 0, 0xFFFFFFF);
			ReadFile(mapEntsFile, g_customEntityString, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
			mapEnts->m_MapEnts->m_EntityString = g_customEntityString;
			mapEnts->m_MapEnts->m_NumEntityChars = strlen(g_customEntityString) + 1;
			CloseHandle(mapEntsFile);
			memset(path, 0, MAX_PATH + 1);
			snprintf(path, MAX_PATH + 1, "%s\\players\\raw\\%s.spawnlist", g_Pointers->m_Dvar_GetStringSafe("fs_homepath"), mapEnts->m_Image->m_Name);
			if (!file_exists(path)) {
			}
			else {
				nlohmann::json json;
				std::ifstream file(path);
				file >> json;
				file.close();
				mapEnts->m_MapEnts->m_SpawnList.m_SpawnsCount = json["spawnList"]["spawnsCount"];
				for (int i = 0; i < mapEnts->m_MapEnts->m_SpawnList.m_SpawnsCount; i++) {
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Index = json["spawnList"][_va("spawns[%i]", i)]["index"];
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Name = Scr_AllocGlobalString(std::string(json["spawnList"][_va("spawns[%i]", i)]["name"]).c_str());
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Target = Scr_AllocGlobalString(std::string(json["spawnList"][_va("spawns[%i]", i)]["target"]).c_str());
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_ScriptNoteworthy = Scr_AllocGlobalString(std::string(json["spawnList"][_va("spawns[%i]", i)]["script_noteworthy"]).c_str());

					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Origin.v[0] = json["spawnList"][_va("spawns[%i]", i)]["origin"][0];
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Origin.v[1] = json["spawnList"][_va("spawns[%i]", i)]["origin"][1];
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Origin.v[2] = json["spawnList"][_va("spawns[%i]", i)]["origin"][2];

					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Angles.v[0] = json["spawnList"][_va("spawns[%i]", i)]["angles"][0];
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Angles.v[1] = json["spawnList"][_va("spawns[%i]", i)]["angles"][1];
					mapEnts->m_MapEnts->m_SpawnList.m_Spawns[i].m_Angles.v[2] = json["spawnList"][_va("spawns[%i]", i)]["angles"][2];
				}
			}
		}
	}

	printf("%s\n", mapEnts->m_MapEnts->m_ClientTrigger.m_TriggerString);

	load_mapentsasset.stub<void>(mapEnts);
}

void DB_GetRawBuffer_Detour(const IW8::RawFile* rawfile, char* buf, int size)
{
	char path[MAX_PATH + 1];
	snprintf(path, MAX_PATH + 1, "%s\\players\\raw\\%s", g_Pointers->m_Dvar_GetStringSafe("fs_homepath"), rawfile->m_Name);
	if (file_exists(path)) {
		HANDLE mapEntsFile = CreateFileA(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(mapEntsFile, NULL);
		if (mapEntsFile != INVALID_HANDLE_VALUE)
		{
			ReadFile(mapEntsFile, g_customBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
			CloseHandle(mapEntsFile);
			strcpy(buf, g_customBuffer);
			printf("replacing %s\n", rawfile->m_Name);
		}
		return;
	}

	db_getrawbuffer.stub<void>(rawfile, buf, size);
}

void Load_XModelAsset_Detour(IW8::XAssetHeader* model)
{
	load_xmodelasset.stub<void>(model);
}