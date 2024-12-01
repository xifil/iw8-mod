#include "Main.hpp"
#include "hooks/hooks.hpp"

#include "functions.hpp"

void DumpGscScript(std::ofstream& stream, IW8::ScriptFile* scriptFile) {
	std::string buffer;
	buffer.append(scriptFile->m_Name, strlen(scriptFile->m_Name) + 1);

	buffer.append(reinterpret_cast<char*>(&scriptFile->m_CompressedLen), 4);
	buffer.append(reinterpret_cast<char*>(&scriptFile->m_Len), 4);
	buffer.append(reinterpret_cast<char*>(&scriptFile->m_BytecodeLen), 4);
	buffer.append(scriptFile->m_Buffer, scriptFile->m_CompressedLen);
	buffer.append((char*)scriptFile->m_Bytecode, scriptFile->m_BytecodeLen);

	stream << buffer;
}

void Hooks::ProcessScriptFile_Detour(void* scrContext, IW8::ScriptFile* scriptFile) {
	// leftover comment from original Donetsk, what even is 1892.gscbin?

	/*if (scriptFile) {
		if (strcmp(scriptFile->name, "1892") == 0) {
			std::ofstream gscbinFile("1892.gscbin", std::ios::out | std::ios::binary);
			if (gscbinFile.is_open()) {
				DumpGscScript(gscbinFile, scriptFile);
				gscbinFile.close();
			}
		}
	}*/

	if (Dvars::g_dumpScripts->m_Current.m_Enabled) {
		std::string scriptFileStr = "";
		if (isSubStr(scriptFile->m_Name, ".gsc")) {
			scriptFileStr = "gsc_dump/" + std::string(scriptFile->m_Name) + "bin";
		}
		else {
			scriptFileStr = "gsc_dump/" + std::string(scriptFile->m_Name) + ".gscbin";
		}

		size_t lastSlash = scriptFileStr.find_last_of("/");
		if (lastSlash != std::string::npos && isSubStr(scriptFile->m_Name, "/")) {
			std::filesystem::create_directories(scriptFileStr.substr(0, lastSlash));
		}

		std::ofstream gscbinFile(scriptFileStr, std::ios::out | std::ios::binary);
		if (gscbinFile.is_open()) {
			DumpGscScript(gscbinFile, scriptFile);
			gscbinFile.close();
		}
	}

	g_ProcessScriptFile.stub<void>(scrContext, scriptFile);
}
