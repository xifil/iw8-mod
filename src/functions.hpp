#pragma once
#include "Main.hpp"
#include "engine/iw8/cmd_function_s.hpp"
#include "engine/iw8/CmdArgs.hpp"
#include "engine/iw8/dvar_t.hpp"
#include "engine/iw8/gameTypeInfo.hpp"
#include "engine/iw8/gentity_s.hpp"
#include "engine/iw8/GfxFont.hpp"
#include "engine/iw8/lua_State.hpp"
#include "engine/iw8/mapInfo.hpp"
#include "engine/iw8/Weapon.hpp"
#include "engine/iw8/XAssetHeader.hpp"
#include "engine/iw8/enums/XAssetType.hpp"

struct scrContext_t;

namespace Dvars {
	extern IW8::dvar_t* player_name;
	extern IW8::dvar_t* sv_cheats;
	extern IW8::dvar_t* spawn_br_gas;
	extern IW8::dvar_t* show_watermark;
	extern IW8::dvar_t* player_sustainAmmo;
	extern IW8::dvar_t* print_debug;
	extern IW8::dvar_t* weap_impactType;
	extern IW8::dvar_t* weap_dismembermentAlwaysEnabled;
	extern IW8::dvar_t* g_dumpScripts;
}

extern IW8::cmd_function_s set_byte_f_VAR;
extern IW8::cmd_function_s set_short_f_VAR;
extern IW8::cmd_function_s set_int_f_VAR;
extern IW8::cmd_function_s set_float_f_VAR;
extern IW8::cmd_function_s set_pointer_f_VAR;
extern IW8::cmd_function_s quit_f_VAR;
extern IW8::cmd_function_s openmenu_f_VAR;
extern IW8::cmd_function_s addbot_f_VAR;
extern IW8::cmd_function_s addTestClient_f_VAR;
extern IW8::cmd_function_s ddldump_f_VAR;
extern IW8::cmd_function_s weapondefdump_f_VAR;
extern IW8::cmd_function_s view_vehicle_ents_f_VAR;
extern IW8::cmd_function_s loadout_save_f_VAR;
extern IW8::cmd_function_s FastRestart_f_VAR;
extern IW8::cmd_function_s MapRestart_f_VAR;
extern IW8::cmd_function_s omnvar_set_f_VAR;
extern IW8::cmd_function_s omnvar_dump_f_VAR;
extern IW8::cmd_function_s unlockall_f_VAR;
extern IW8::cmd_function_s dump_weapdefs_f_VAR;
extern IW8::cmd_function_s load_weapdef_f_VAR;

void* RtlAddVectoredExceptionHandler(LONG First, PVECTORED_EXCEPTION_HANDLER Handler);
NTSTATUS NtContinue(PCONTEXT threadContext, BOOLEAN raiseAlert);

bool isSubStr(std::string str, std::string subStr);
float strToFloat(const std::string& str);

#pragma region //game functions

void CG_DrawRotatedPicPhysical(uintptr_t scrPlace, float x, float y, float width, float height, float angle, const float* color, uintptr_t material);

inline bool file_exists(const char* name) {
	struct stat buffer;
	return (stat(name, &buffer) == 0);
}

bool Dvar_GetBoolSafe(const char* dvar);

unsigned int* GetRandSeed();
unsigned __int64 Sys_Microseconds();
int I_irand(int min, int max);
unsigned __int64 I_atoui64_hex(const char* str);
unsigned __int64 I_atoui64(const char* str);
IW8::dvar_t* Dvar_FindVarByName(const char* dvarName);

void CL_DrawText(const uintptr_t scrPlace, const char* text, int maxChars, IW8::GfxFont* font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float* color, int style);
IW8::dvar_t* Dvar_RegisterString(const char* dvarName, const char* value, unsigned int flags, const char* description);
IW8::dvar_t* Dvar_RegisterBool(const char* dvarName, bool value, unsigned int flags, const char* description);
IW8::dvar_t* Dvar_RegisterInt(const char* dvarName, bool value, int min, int max, unsigned int flags, const char* description);

void LUI_CoD_LuaCall_ExecNow(IW8::lua_State* luaVM, const char* str);

void Cbuf_AddText(const char* cmd);

const char* lua_tolstring(uintptr_t L, int idx, size_t* len);

void lua_pushboolean(uintptr_t L, int b);
void lua_pushvalue(uintptr_t L, int idx);
void lua_pushinteger(uintptr_t L, int n);
void lua_settop(uintptr_t L, int idx);

bool lua_isstring(uintptr_t L, int idx);

bool CG_DObjGetWorldBoneMatrix(uintptr_t pose, uintptr_t obj, int boneIndex, uintptr_t outTagMat, float* outOrigin);

void CG_DrawLine(float X1, float Y1, float X2, float Y2, const float* color, float Width);
void CG_DrawBone(int entIndex, uintptr_t ent, int from, int to, const float* color);
void CG_DrawBones(int entIndex, uintptr_t ent, const float* color);

bool CheatsOk(int entNum);

void Cmd_Noclip_f(int entNum);

void Cmd_God_f(int entNum);

void SV_Cmd_ArgvBuffer(int arg, char* buffer, unsigned __int64 bufferLength);
void Cmd_ArgvBuffer(int arg, char* buffer, int bufferLength);
int Cmd_Argc();
int SV_Cmd_Argc();

void Cmd_AddCommandInternal(const char* cmdName, void(__fastcall* function)(), IW8::cmd_function_s* allocedCmd);

void AddReliableCommand(uintptr_t _this, const char* commandBuffer, const int reliableCmdSize, int type);
unsigned int MSG_WriteReliableCommandToBuffer(const char* pszCommand, char* pszBuffer, unsigned int iBufferSize);

void CL_Main_AddReliableCommand(const char* cmd);

bool BG_Weapons_GetFullWeaponForName(const char* name, IW8::Weapon* outWeapon, IW8::Weapon* (__fastcall* getWeaponFunc)(IW8::Weapon* result, const char*));

void Scr_AddString(scrContext_t* scrContext, const char* value);
unsigned int GScr_ExecEntThread(IW8::gentity_s* ent, int handle, unsigned int paramcount);
void Scr_FreeThread(scrContext_t* scrContext, unsigned int handle);

int G_Weapon_GivePlayerWeapon(uintptr_t ps, uintptr_t scrContext, IW8::Weapon* weapon, int dualWield, int startInAltMode, int usedBefore);
void G_Items_AddAmmo(uintptr_t ps, IW8::Weapon* weapon, bool isAlternate, int count, int fillClip);

void G_Weapon_SelectWeapon(int clientNum, IW8::Weapon* weapon);
IW8::Weapon* BG_FindBaseWeaponForName(IW8::Weapon* result, const char* name);

scrContext_t* ScriptContext_Server();

const char* SL_ConvertToString(int id);

IW8::XAssetHeader DB_FindXAssetHeader(IW8::XAssetType type, const char* givenName, int allowCreateDefault);

void Com_SetErrorMessage(const char* errorMessage);

void GamerProfile_SetDataByName(unsigned int controllerIndex, const char* settingName, float settingValue);

short* SV_ClientMP_AddTestClient();
short* SV_ClientMP_AddBot();
void GScr_Notify(short* ent, unsigned int stringValue, unsigned int paramcount);
int SL_GetString(const char* value);

void GScr_AddEntity(short* entity);

void SV_ClientMP_SpawnBotOrTestClient(short* entity);

uintptr_t G_GetEntityPlayerState(IW8::gentity_s* ent);

int G_Main_GetTime();

const char* _va(const char* format, ...);

void CopyStdString(const std::string& str, const char** target);

const char* GetMapName(const char* mapName);
const char* GetGameTypeName(const char* gameType);

#pragma endregion
