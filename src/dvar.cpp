#include "dvar.h"
#include "game_inc.h"
#include "functions.hpp"

bool CheatsEnabled() {
	return Dvars::sv_cheats->m_Current.m_Enabled;
}