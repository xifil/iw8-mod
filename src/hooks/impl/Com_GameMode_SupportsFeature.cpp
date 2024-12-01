#include "Main.hpp"
#include "functions.hpp"
#include "hooks/hooks.hpp"

bool Hooks::Com_GameMode_SupportsFeature_Detour(unsigned int featureID) {
	static IW8::dvar_t* timescale;

	if (featureID == 70 /* TIMESCALE_TWEAKING */) {
		if (timescale == nullptr) {
			timescale = Dvar_FindVarByName("timescale");
		}

		if (timescale->m_Current.m_Value != 1.f) {
			return true;
		}
	}

	if (featureID == 33 /* GRAVITY_CHANGE_ALLOWED */) {
		return true;
	}

	return g_Com_GameMode_SupportsFeature.stub<bool>(featureID);
}
