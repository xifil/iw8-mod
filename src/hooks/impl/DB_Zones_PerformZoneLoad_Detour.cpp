#include "Main.hpp"
#include "hooks/hooks.hpp"

std::int64_t Hooks::DB_Zones_PerformZoneLoad_Detour(bool processingPreloadedFiles, bool isBaseMap, bool wasPaused, IW8::DB_FastFileFailureMode failureMode) {
	return g_DB_Zones_PerformZoneLoad.stub<std::int64_t>(processingPreloadedFiles, isBaseMap, wasPaused, IW8::DB_FastFileFailureMode::ALLOW_MISSING);
}
