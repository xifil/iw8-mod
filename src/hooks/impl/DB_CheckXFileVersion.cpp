#include "Main.hpp"
#include "hooks/hooks.hpp"

std::optional<std::uint32_t> s_ExpectedFileVersion;
bool Hooks::DB_CheckXFileVersion_Detour(const IW8::DB_FFHeader* header, const IW8::DBFileHandle* handle, const char* path, const char* baseFileForPatch) {
	bool og = g_DB_CheckXFileVersion.stub<bool>(header, handle, path, baseFileForPatch);
	if (og) {
		if (!s_ExpectedFileVersion.has_value() || s_ExpectedFileVersion.value() < header->m_XFileVersion) {
			s_ExpectedFileVersion = header->m_XFileVersion;
		}
	}
	else {
		if (s_ExpectedFileVersion.has_value()) {
			printf("[DB_CheckXFileVersion] warning: version mismatch on fastfile %s. (expected v%d, got v%d)\n", path,
				s_ExpectedFileVersion.value(), header->m_XFileVersion);
		}
		else {
			printf("[DB_CheckXFileVersion] warning: version mismatch on fastfile %s.\n", path);
		}
	}
	return og;
}
