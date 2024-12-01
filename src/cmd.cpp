#include "addr_utils.hpp"
#include "cmd.h"
#include "functions.hpp"
#include "engine/iw8/XAssetHeader.hpp"
#include "engine/iw8/enums/XAssetType.hpp"
#include "game/game.hpp"

void Cmd_Exec_Internal(bool isSuperUser)
{
	const char* cmdbuf;
	const char* file;
	auto DB_FindXAssetHeader = reinterpret_cast<uintptr_t(*)(IW8::XAssetType type, const char* givenName, int allowCreateDefault)>(0x1411AA890_g);
	auto DB_ReadRawFile = reinterpret_cast<const char* (*)(unsigned int a1, unsigned int a2, const char* a3, char a4)>(0x141297140_g);
	auto Core_strcpy_truncate = reinterpret_cast<bool(*)(char* dest, unsigned __int64 destsize, const char* src)>(0x142036A90_g);
	auto Com_DefaultExtension = reinterpret_cast<void(*)(char* path, int maxSize, const char* extension)>(0x1413F1AE0_g);
	char path[64];

	if (g_Pointers->m_cmd_args->m_Argc[g_Pointers->m_cmd_args->m_Nesting] == 2) {
		Core_strcpy_truncate(path, 64, *(g_Pointers->m_cmd_args->m_Argv[g_Pointers->m_cmd_args->m_Nesting] + 1));
		Com_DefaultExtension(path, 64, ".cfg");
		if (DB_FindXAssetHeader(IW8::XAssetType::ASSET_TYPE_RAWFILE, path, 0)) {
			if (!DB_ReadRawFile(0, g_Pointers->m_cmd_args->m_ControllerIndex[g_Pointers->m_cmd_args->m_Nesting], path, isSuperUser)) {
				if (g_Pointers->m_cmd_args->m_Argc[g_Pointers->m_cmd_args->m_Nesting] <= 1) {
					file = "";
				}
				else {
					file = *(g_Pointers->m_cmd_args->m_Argv[g_Pointers->m_cmd_args->m_Nesting] + 1);
				}
				printf("couldn't exec %s\n", file);
			}
		}
		else {
			g_Pointers->m_FS_ReadFile(path, (void**)&cmdbuf);
			Cbuf_AddText(cmdbuf);
		}
	}
	else {
		printf(0, "exec <filename> : execute a script file\n");
	}
}