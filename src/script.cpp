#include "addr_utils.hpp"
#include "script.h"
#include "game_inc.h"
#include "functions.hpp"
#include "engine/iw8/ScriptFile.hpp"
#include "engine/iw8/enums/XAssetType.hpp"

void Load_ScriptFile_Detour(int streamStart)
{
	auto DB_PatchMem_PushAsset = reinterpret_cast<void(*)(size_t len, IW8::ScriptFile* script)>(0x140D8D860_g);
	auto Load_Stream = reinterpret_cast<void(*)(int streamStart, void* ptr, size_t size)>(0x1411B2A20_g);
	auto DB_PushStreamPos = reinterpret_cast<void(*)(int param_1)>(0x1411B2570_g);
	auto Load_XString = reinterpret_cast<void(*)(int param_1)>(0x140DD3400_g);
	auto DB_PopStreamPos = reinterpret_cast<void(*)(void)>(0x1411B24C0_g);
	auto DB_PatchMem_PopAsset = reinterpret_cast<void(*)(void)>(0x140D8D850_g);
	auto DB_ReadXFile = reinterpret_cast<void(*)(void* ptr, size_t size)>(0x1411A85D0_g);

	IW8::ScriptFile** varScriptFile = reinterpret_cast<IW8::ScriptFile**>(0x145D43670_g);
	char** varXString = reinterpret_cast<char**>(0x145D417C0_g);
	char** varConstChar = reinterpret_cast<char**>(0x145D417B0_g);
	char** varbyte = reinterpret_cast<char**>(0x145D415D8_g);
	char** g_streamPosGlob_pos = reinterpret_cast<char**>(0x14D120C00_g);

	char* backup;
	IW8::ScriptFile* scriptfile;

	DB_PatchMem_PushAsset(static_cast<size_t>(IW8::XAssetType::ASSET_TYPE_SCRIPTFILE), *varScriptFile);
	Load_Stream(streamStart, *varScriptFile, sizeof(IW8::ScriptFile));
	DB_PushStreamPos(5);

	char* xStringBackup = *varXString;
	*varXString = reinterpret_cast<char*>(*varScriptFile);
	Load_XString(1);
	*varXString = xStringBackup;
	DB_PushStreamPos(6);

	scriptfile = *varScriptFile;

	backup = *varConstChar;

	printf("[Load_ScriptFile] loading %s\n", scriptfile->m_Name);
	std::string filepath = "script.gscbin";
	bool scriptgscbin = false;

	if (!strcmp(scriptfile->m_Name, "1892") && file_exists("script.gscbin")) {
		scriptgscbin = true;
	}
	else {
		std::string scriptname = scriptfile->m_Name;
		if (isSubStr(scriptname, ".gsc")) {
			filepath = "donetsk/scripts/" + scriptname + "bin";
		}
		else { // numbered scriptfiles like "1892"
			filepath = "donetsk/scripts/" + scriptname + ".gscbin";
		}
	}

	if (file_exists(filepath.c_str()) || scriptgscbin)
	{
		std::ifstream script;
		script.open(filepath, std::ios::binary | std::ios::ate);
		int size = (int)script.tellg();
		script.seekg(0, std::ios::beg);

		char* customScript = new char[size];
		script.read(customScript, size);
		script.seekg(0, std::ios::beg);

		while (script.get() != '\0'); // read past the name
		int vars[3] = { 0 };
		script.read((char*)vars, sizeof(int) * 3); //read header info

		if (scriptfile->m_Buffer != NULL)
		{
			*varConstChar = *g_streamPosGlob_pos;
			scriptfile->m_Buffer = *varConstChar;

			char* dummyMem = new char[scriptfile->m_CompressedLen];
			DB_ReadXFile(dummyMem, scriptfile->m_CompressedLen);
			delete[scriptfile->m_CompressedLen] dummyMem;

			memmove(*g_streamPosGlob_pos, customScript + (int)script.tellg(), vars[0]);

			*g_streamPosGlob_pos = *g_streamPosGlob_pos + vars[0];
			scriptfile->m_CompressedLen = vars[0];
		}
		*varConstChar = backup;
		scriptfile->m_Len = vars[1];

		DB_PopStreamPos();
		DB_PushStreamPos(6);

		scriptfile = *varScriptFile;
		backup = *varbyte;

		if (scriptfile->m_Bytecode != NULL)
		{
			*varbyte = *g_streamPosGlob_pos;
			scriptfile->m_Bytecode = (unsigned char*)*varbyte;

			char* dummyMem = new char[scriptfile->m_BytecodeLen];
			DB_ReadXFile(dummyMem, scriptfile->m_BytecodeLen);
			delete[scriptfile->m_BytecodeLen] dummyMem;

			memmove(*g_streamPosGlob_pos, customScript + vars[0] + (int)script.tellg(), vars[2]);

			*g_streamPosGlob_pos = *g_streamPosGlob_pos + vars[2];
			scriptfile->m_BytecodeLen = vars[2];
		}
		*varbyte = backup;

		delete[size] customScript;
		script.close();
	}
	else
	{
		if (scriptfile->m_Buffer != NULL)
		{
			*varConstChar = *g_streamPosGlob_pos;
			scriptfile->m_Buffer = *varConstChar;
			Load_Stream(0, *varConstChar, scriptfile->m_CompressedLen);
		}
		*varConstChar = backup;

		DB_PopStreamPos();
		DB_PushStreamPos(6);

		scriptfile = *varScriptFile;
		backup = *varbyte;
		if (scriptfile->m_Bytecode != NULL)
		{
			*varbyte = *g_streamPosGlob_pos;
			scriptfile->m_Bytecode = (unsigned char*)*varbyte;
			Load_Stream(0, *varbyte, scriptfile->m_BytecodeLen);
		}
		*varbyte = backup;
	}

	DB_PopStreamPos();
	DB_PopStreamPos();
	DB_PatchMem_PopAsset();
}
