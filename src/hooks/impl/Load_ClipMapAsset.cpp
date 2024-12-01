#include "Main.hpp"
#include "hooks/hooks.hpp"

void Hooks::Load_ClipMapAsset_Detour(IW8::XAssetHeader* clipMap) {
	g_Load_ClipMapAsset.stub<void>(clipMap);
}
