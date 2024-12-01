#include "Main.hpp"
#include "hooks/hooks.hpp"

int Hooks::DB_LoadXFile_Detour(const char* zoneName, uintptr_t zoneMem, uintptr_t assetList, int zoneFlags, bool wasPaused, int failureMode, uintptr_t outSignature) {
	printf("[DB_LoadXFile] loading fastfile %s...\n", zoneName);
	int res = g_DB_LoadXFile.stub<int>(zoneName, zoneMem, assetList, zoneFlags, wasPaused, failureMode, outSignature);
	if (res != 0) {
		printf("[DB_LoadXFile] warning: loaded fastfile %s with non-zero code %d.\n", zoneName, res);
	}
	return res;
}
