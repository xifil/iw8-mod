#include "addr_utils.hpp"
#include "functions.hpp"
#include "structs.h"

#include "engine/iw8/ClActiveClient.hpp"
#include "engine/iw8/SvClient.hpp"
#include "engine/iw8/usercmd_s.hpp"

#include "game/game.hpp"

void* RtlAddVectoredExceptionHandler(LONG First, PVECTORED_EXCEPTION_HANDLER Handler) {
	utils::nt::library ntdll("ntdll.dll");
	ntdll.invoke<void*>("RtlAddVectoredExceptionHandler", First, Handler);
	return nullptr;
}

NTSTATUS NtContinue(PCONTEXT threadContext, BOOLEAN raiseAlert) {
	utils::nt::library ntdll("ntdll.dll");
	return ntdll.invoke<NTSTATUS>("NtContinue", threadContext, raiseAlert);
}

bool isSubStr(std::string str, std::string subStr)
{
	size_t pos = str.find(subStr);
	if (pos != std::string::npos)
	{
		return true;
	}
	return false;
}

float strToFloat(const std::string& str)
{
	float num = 0.0f;
	float fraction = 0.1f;
	bool isNegative = false;

	size_t i = 0;
	if (str[i] == '-')
	{
		isNegative = true;
		i++;
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10.0f + static_cast<float>(str[i] - '0');
		}
		else if (str[i] == '.')
		{
			i++;
			break;
		}
		else
		{
			break;
		}
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += (str[i] - '0') * fraction;
			fraction *= 0.1f;
		}
		else
		{
			break;
		}
	}

	if (isNegative)
	{
		num = -num;
	}

	return num;
}

#pragma region //game functions

void CG_DrawRotatedPicPhysical(uintptr_t scrPlace, float x, float y, float width, float height, float angle, const float* color, uintptr_t material) {
	auto func = reinterpret_cast<void(*)(uintptr_t scrPlace, float x, float y, float width, float height, float angle, const float* color, uintptr_t material)>(0x141695B20_g);
	func(scrPlace, x, y, width, height, angle, color, material);
}

bool Dvar_GetBoolSafe(const char* dvar)
{
	auto func = reinterpret_cast<bool(*)(const char*)>(0x1413E6820_g);
	return func(dvar);
}

unsigned int* GetRandSeed() {
	auto func = reinterpret_cast<unsigned int* (*)()>(0x1413DD630_g);
	return func();
}

unsigned __int64 Sys_Microseconds() {
	auto func = reinterpret_cast<unsigned __int64(*)()>(0x14148FC10_g);
	return func();
}

int I_irand(int min, int max) {
	auto func = reinterpret_cast<int(*)(int, int)>(0x1413DD8B0_g);
	return func(min, max);
}

unsigned __int64 I_atoui64_hex(const char* str) {
	auto func = reinterpret_cast<unsigned __int64(*)(const char*)>(0x1413F3310_g);
	return func(str);
}

unsigned __int64 I_atoui64(const char* str) {
	auto func = reinterpret_cast<unsigned __int64(*)(const char*)>(0x1413F3300_g);
	return func(str);
}

IW8::dvar_t* Dvar_FindVarByName(const char* dvarName) {
	auto func = reinterpret_cast<IW8::dvar_t*(*)(const char*)>(0x1413E63A0_g);
	return func(dvarName);
}

void CL_DrawText(const uintptr_t scrPlace, const char* text, int maxChars, IW8::GfxFont* font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float* color, int style) {
	auto func = reinterpret_cast<void(*)(const uintptr_t scrPlace, const char* text, int maxChars, IW8::GfxFont* font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float* color, int style)>(0x1415AAAA0_g);
	func(scrPlace, text, maxChars, font, x, y, horzAlign, vertAlign, xScale, yScale, color, style);
}

IW8::dvar_t* Dvar_RegisterString(const char* dvarName, const char* value, unsigned int flags, const char* description) {
	auto func = reinterpret_cast<IW8::dvar_t*(*)(const char* dvarName, const char* value, unsigned int flags, const char* description)>(0x1413E7A70_g);
	return func(dvarName, value, flags, description);
}

IW8::dvar_t* Dvar_RegisterBool(const char* dvarName, bool value, unsigned int flags, const char* description) {
	auto func = reinterpret_cast<IW8::dvar_t*(*)(const char* dvarName, bool value, unsigned int flags, const char* description)>(0x1413E7670_g);
	return func(dvarName, value, flags, description);
}

IW8::dvar_t* Dvar_RegisterInt(const char* dvarName, bool value, int min, int max, unsigned int flags, const char* description) {
	auto func = reinterpret_cast<IW8::dvar_t*(*)(const char* dvarName, bool value, int min, int max, unsigned int flags, const char* description)>(0x1413E7A00_g);
	return func(dvarName, value, min, max, flags, description);
}

void LUI_CoD_LuaCall_ExecNow(IW8::lua_State* luaVM, const char* str) {
	g_Pointers->m_lua_getfield(luaVM, -10002, "Engine");
	g_Pointers->m_lua_getfield(luaVM, -1, "DAGFFDGFII");
	g_Pointers->m_lua_remove(luaVM, -2);
	g_Pointers->m_lua_pushstring(luaVM, str);
	g_Pointers->m_LuaShared_PCall(luaVM, 1, 1);
}

void Cbuf_AddText(const char* cmd) {
	if (g_Pointers->m_LUI_luaVM && *g_Pointers->m_LUI_luaVM) {
		LUI_CoD_LuaCall_ExecNow(*g_Pointers->m_LUI_luaVM, cmd);
	}
}

const char* lua_tolstring(uintptr_t L, int idx, size_t* len) {
	auto func = reinterpret_cast<const char* (*)(uintptr_t, int, size_t*)>(0x142084950_g);
	return func(L, idx, len);
}

void lua_pushboolean(uintptr_t L, int b) {
	auto func = reinterpret_cast<void(*)(uintptr_t, int)>(0x142083E80_g);
	func(L, b);
}

void lua_pushvalue(uintptr_t L, int idx) {
	auto func = reinterpret_cast<void(*)(uintptr_t, int)>(0x142084200_g);
	func(L, idx);
}

void lua_pushinteger(uintptr_t L, int n) {
	auto func = reinterpret_cast<void(*)(uintptr_t, int)>(0x142083FE0_g);
	func(L, n);
}

void lua_settop(uintptr_t L, int idx) {
	auto func = reinterpret_cast<void(*)(uintptr_t, int)>(0x142084790_g);
	func(L, idx);
}

bool lua_isstring(uintptr_t L, int idx) {
	auto func = reinterpret_cast<bool(*)(uintptr_t, int)>(0x142083A30_g);
	return func(L, idx);
}

bool CG_DObjGetWorldBoneMatrix(uintptr_t pose, uintptr_t obj, int boneIndex, uintptr_t outTagMat, float* outOrigin) {
	auto func = reinterpret_cast<bool(*)(uintptr_t pose, uintptr_t obj, int boneIndex, uintptr_t outTagMat, float* outOrigin)>(0x1416A59D0_g);
	return func(pose, obj, boneIndex, outTagMat, outOrigin);
}

void CG_DrawLine(float X1, float Y1, float X2, float Y2, const float* color, float Width) {
	float X, Y, Angle, L1, L2, H1;
	H1 = Y2 - Y1;
	L1 = X2 - X1;
	L2 = sqrtf(L1 * L1 + H1 * H1);
	X = X1 + ((L1 - L2) / 2);
	Y = Y1 + (H1 / 2);
	Angle = atan(H1 / L1) * (180 / 3.14159265358979323846);
	CG_DrawRotatedPicPhysical(0x14EF2DEA0_g, X, Y, L2, Width, Angle, color, *reinterpret_cast<uintptr_t*>(0x152C465A0_g));
}

void CG_DrawBone(int entIndex, uintptr_t ent, int from, int to, const float* color) {
	IW8::vec3_t bone1, bone2;
	IW8::vec2_t fromPos, toPos;
	char tmat33[0x24];
	short* clientObjMap = (short*)(0x14D45EC60_g);
	uintptr_t s_objBuf = *reinterpret_cast<uintptr_t*>(0x14D45EC50_g);
	uintptr_t dobj = s_objBuf + (0x150 * clientObjMap[entIndex]);

	IW8::ScreenPlacement* scrPlace = reinterpret_cast<IW8::ScreenPlacement*>(0x14EF2DEA0_g);

	if (CG_DObjGetWorldBoneMatrix(ent, dobj, from, (uintptr_t)&tmat33, bone1.v) && CG_DObjGetWorldBoneMatrix(ent, dobj, to, (uintptr_t)&tmat33, bone2.v)) {
		if (g_Pointers->m_CG_WorldPosToScreenPosReal(IW8::LocalClientNum_t::LOCAL_CLIENT_0, scrPlace, &bone1, &fromPos)
				&& g_Pointers->m_CG_WorldPosToScreenPosReal(IW8::LocalClientNum_t::LOCAL_CLIENT_0, scrPlace, &bone2, &toPos)) {
			CG_DrawLine(fromPos.x, fromPos.y, toPos.x, toPos.y, color, 1);
		}
	}
}

void CG_DrawBones(int entIndex, uintptr_t ent, const float* color) {
	//spine
	CG_DrawBone(entIndex, ent, 41, 35, color);
	CG_DrawBone(entIndex, ent, 35, 7, color);
	CG_DrawBone(entIndex, ent, 7, 6, color);
	CG_DrawBone(entIndex, ent, 6, 30, color);
	CG_DrawBone(entIndex, ent, 30, 55, color);
	CG_DrawBone(entIndex, ent, 55, 54, color);
	CG_DrawBone(entIndex, ent, 54, 53, color);
	CG_DrawBone(entIndex, ent, 53, 2, color);

	//hips
	CG_DrawBone(entIndex, ent, 2, 63, color);
	CG_DrawBone(entIndex, ent, 2, 64, color);
}

bool CheatsOk(int entNum) {
	IW8::SvClient* ms_clients = *reinterpret_cast<IW8::SvClient**>(0x14E17F690_g + (8 * entNum));
	uintptr_t client = reinterpret_cast<uintptr_t>((*g_Pointers->m_g_entities)[entNum].m_Client);
	if (Dvars::sv_cheats->m_Current.m_Enabled) {
		return true;
	}
	else {
		ms_clients->SendServerCommand(IW8::svscmd_type::SV_CMD_CAN_IGNORE, "f \"Cheats are not enabled on this server!\"");
		return false;
	}
}

//ingame removed functions
void Cmd_Noclip_f(int entNum)
{
	IW8::SvClient* ms_clients = *reinterpret_cast<IW8::SvClient**>(0x14E17F690_g + (8 * entNum));
	uintptr_t client = reinterpret_cast<uintptr_t>((*g_Pointers->m_g_entities)[entNum].m_Client);
	if (client) {
		int v6 = *reinterpret_cast<int*>(client + 0x5DD0);
		if ((*reinterpret_cast<int*>(client + 0x5DD0) & 1) != 0) {
			v6 = *reinterpret_cast<int*>(client + 0x5DD0) & 0xFFFFFFFE;
			ms_clients->SendServerCommand(IW8::svscmd_type::SV_CMD_CAN_IGNORE, "f \"Noclip: ^1OFF\"");
		}
		else {
			v6 = *reinterpret_cast<int*>(client + 0x5DD0) | 1;
			ms_clients->SendServerCommand(IW8::svscmd_type::SV_CMD_CAN_IGNORE, "f \"Noclip: ^2ON\"");
		}
		*reinterpret_cast<int*>(client + 0x5DD0) = v6;
	}
}

void Cmd_God_f(int entNum)
{
	IW8::SvClient* ms_clients = *reinterpret_cast<IW8::SvClient**>(0x14E17F690_g + (8 * entNum));
	IW8::gentity_s ent = (*g_Pointers->m_g_entities)[entNum];
}

void SV_Cmd_ArgvBuffer(int arg, char* buffer, unsigned __int64 bufferLength) {
	auto func = reinterpret_cast<void(*)(int, char*, unsigned __int64)>(0x141298B40_g);
	func(arg, buffer, bufferLength);
}

void Cmd_ArgvBuffer(int arg, char* buffer, int bufferLength) {
	if (arg >= g_Pointers->m_cmd_args->m_Argc[g_Pointers->m_cmd_args->m_Nesting])
		strcpy_s(buffer, bufferLength, "");
	else
		strcpy_s(buffer, bufferLength, g_Pointers->m_cmd_args->m_Argv[g_Pointers->m_cmd_args->m_Nesting][arg]);
}

int Cmd_Argc() {
	return g_Pointers->m_cmd_args->m_Argc[g_Pointers->m_cmd_args->m_Nesting];
}

int SV_Cmd_Argc() {
	auto func = reinterpret_cast<int(*)()>(0x141298AF0_g);
	return func();
}

void Cmd_AddCommandInternal(const char* cmdName, void(__fastcall* function)(), IW8::cmd_function_s* allocedCmd) {
	auto func = reinterpret_cast<void(*)(const char*, void(__fastcall*)(), IW8::cmd_function_s*)>(0x1412965F0_g);
	func(cmdName, function, allocedCmd);
}

IW8::ClActiveClient* GetClActiveClient() {
	ms_activeClients = *reinterpret_cast<IW8::ClActiveClient**>(0x14EE854F8_g);
	return ms_activeClients;
}

int ClActiveClient_GetCmdNumber(IW8::ClActiveClient* activeClient) {
	return activeClient->m_CmdNumber.m_CmdNumber
		^ ((activeClient->m_LatencyDeviceState ^ (activeClient->m_CmdNumber.m_CmdNumber)
			* ((activeClient->m_LatencyDeviceState ^ activeClient->m_CmdNumber.m_CmdNumber) + 2)));
}

IW8::usercmd_s* CL_GetUserCmd(int cmdNumber) {
	ms_activeClients = *reinterpret_cast<IW8::ClActiveClient**>(0x14EE854F8_g);
	return &ms_activeClients->m_Cmds[cmdNumber & 0x7F];
}

void AddReliableCommand(uintptr_t _this, const char* commandBuffer, const int reliableCmdSize, int type) {
	auto func = reinterpret_cast<void(*)(uintptr_t, const char*, const int, int)>(0x1415E0440_g);
	func(_this, commandBuffer, reliableCmdSize, type);
}

unsigned int MSG_WriteReliableCommandToBuffer(const char* pszCommand, char* pszBuffer, unsigned int iBufferSize) {
	auto func = reinterpret_cast<unsigned int(*)(const char*, char*, unsigned int)>(0x1412DDBF0_g);
	return func(pszCommand, pszBuffer, iBufferSize);
}

void CL_Main_AddReliableCommand(const char* cmd) {
	uintptr_t ms_connections = *reinterpret_cast<uintptr_t*>(0x14EE85570_g);
	char buf[1024];
	int cmdSize = MSG_WriteReliableCommandToBuffer(cmd, buf, 1024);
	AddReliableCommand(ms_connections, buf, cmdSize, 0);
}

bool BG_Weapons_GetFullWeaponForName(const char* name, IW8::Weapon* outWeapon, IW8::Weapon* (*getWeaponFunc)(IW8::Weapon* result, const char*)) {
	auto func = reinterpret_cast<bool(*)(const char*, IW8::Weapon*, IW8::Weapon*(*)(IW8::Weapon* result, const char*))>(0x141158130_g);
	return func(name, outWeapon, getWeaponFunc);
}

void Scr_AddString(scrContext_t* scrContext, const char* value) {
	auto func = reinterpret_cast<void(*)(scrContext_t*, const char*)>(0x141322D90_g);
	func(scrContext, value);
}

int SL_GetString(const char* value) {
	auto func = reinterpret_cast<int(*)(const char*)>(0x14131AE30_g);
	return func(value);
}

unsigned int GScr_ExecEntThread(IW8::gentity_s* ent, int handle, unsigned int paramcount) {
	auto func = reinterpret_cast<unsigned int(*)(IW8::gentity_s*, int, unsigned int)>(0x141257D70_g);
	return func(ent, handle, paramcount);
}

void Scr_FreeThread(scrContext_t* scrContext, unsigned int handle) {
	auto func = reinterpret_cast<void(*)(scrContext_t*, unsigned int)>(0x1413242E0_g);
	func(scrContext, handle);
}

int G_Weapon_GivePlayerWeapon(uintptr_t ps, uintptr_t scrContext, IW8::Weapon* weapon, int dualWield, int startInAltMode, int usedBefore) {
	auto func = reinterpret_cast<int(*)(uintptr_t, uintptr_t, IW8::Weapon*, int, int, int)>(0x14127C8B0_g);
	return func(ps, scrContext, weapon, dualWield, startInAltMode, usedBefore);
}

void G_Items_AddAmmo(uintptr_t ps, IW8::Weapon* weapon, bool isAlternate, int count, int fillClip) {
	auto func = reinterpret_cast<void(*)(uintptr_t, IW8::Weapon*, bool, int, int)>(0x141216860_g);
	func(ps, weapon, isAlternate, count, fillClip);
}

void G_Weapon_SelectWeapon(int clientNum, IW8::Weapon* weapon) {
	auto func = reinterpret_cast<void(*)(int, IW8::Weapon*)>(0x14127F840_g);
}

IW8::Weapon* BG_FindBaseWeaponForName(IW8::Weapon* result, const char* name) {
	auto func = reinterpret_cast<IW8::Weapon*(*)(IW8::Weapon*, const char*)>(0x1411570F0_g);
	return func(result, name);
}

scrContext_t* ScriptContext_Server() {
	auto func = reinterpret_cast<scrContext_t * (*)()>(0x1412E0E70_g);
	return func();
}

const char* SL_ConvertToString(int id) {
	auto func = reinterpret_cast<const char* (*)(int)>(0x14131AA20_g);
	return func(id);
}

IW8::XAssetHeader DB_FindXAssetHeader(IW8::XAssetType type, const char* givenName, int allowCreateDefault) {
	auto func = reinterpret_cast<IW8::XAssetHeader(*)(IW8::XAssetType, const char*, int)>(0x1411AA890_g);
	return func(type, givenName, allowCreateDefault);
}

void Com_SetErrorMessage(const char* errorMessage) {
    auto func = reinterpret_cast<void(*)(const char*)>(0x1412B3710_g);
    return func(errorMessage);
}

void GamerProfile_SetDataByName(unsigned int controllerIndex, const char* settingName, float settingValue)
{
	auto func = reinterpret_cast<void(*)(int, const char*, float)>(0x1415D8BD0_g);
	return func(controllerIndex, settingName, settingValue);
}

short* SV_ClientMP_AddTestClient()
{
	uintptr_t SV_ClientMP_AddTestClient_func_address = 0x14136e570_g;
	short* (__cdecl * SV_ClientMP_AddTestClient_func)(void) = (short* (__cdecl*)(void))SV_ClientMP_AddTestClient_func_address;

	return SV_ClientMP_AddTestClient_func();
}

short* SV_ClientMP_AddBot()
{
	auto func = reinterpret_cast<short*(*)(const char* bot_name, unsigned int head, unsigned int body, unsigned int helmet)>(0x14136E210_g);
	return func("DONETSK", 0, 0, 0);
}

void GScr_AddEntity(short* entity)
{
	auto GScr_AddEntity_func = reinterpret_cast<void(*)(short* ent)>(0x1412578a0_g);
	GScr_AddEntity_func(entity);
}

void GScr_Notify(short* ent, unsigned int stringValue, unsigned int paramcount) {
	reinterpret_cast<void(*)(short*, unsigned int, unsigned int)>(0x141259B30_g)(ent, stringValue, paramcount);
}

void SV_ClientMP_SpawnBotOrTestClient(short* entity)
{
	auto SV_ClientMP_SpawnBotOrTestClient_func = reinterpret_cast<void(*)(short* ent)>(0x141373640_g);
	SV_ClientMP_SpawnBotOrTestClient_func(entity);
}

uintptr_t G_GetEntityPlayerState(IW8::gentity_s* ent)
{
	uintptr_t cl = reinterpret_cast<uintptr_t>(ent->m_Client);

	// return &cl->ps;
	return cl; // client + 0x0 = playerstate
}

int G_Main_GetTime()
{
	return *(int*)0x14BC21730_g;
}

const char* _va(const char* format, ...)
{
	char _buf[2048];
	va_list ap;

	va_start(ap, format);
	vsnprintf(_buf, 2048, format, ap);
	_buf[2047] = 0;
	return _buf;
}

void CopyStdString(const std::string& str, const char** target) {
	if (!target) {
		return;
	}

	*target = new char[str.size() + 1];
	strcpy(const_cast<char*>(*target), str.data());
}

const char* GetMapName(const char* mapName) {
	IW8::mapInfo* info = g_Pointers->m_Com_GameInfo_GetMapInfoForLoadName(mapName);
	if (!info) {
		return "Unknown Map";
	}
	if (info->m_MapName[0] == '\x1F') {
		return "error";
	}
	return g_Pointers->m_SEH_StringEd_GetString(info->m_MapName);
}

const char* GetGameTypeName(const char* gameType) {
	IW8::gameTypeInfo* info = g_Pointers->m_Com_GameInfo_GetGameTypeForInternalName(gameType);
	if (!info) {
		return "Unknown Mode";
	}
	if (info->m_GameTypeName[0] == '\x1F') {
		return "error";
	}
	return g_Pointers->m_SEH_StringEd_GetString(info->m_GameTypeName);
}

#pragma endregion

namespace Dvars {
	IW8::dvar_t* player_name;
	IW8::dvar_t* sv_cheats;
	IW8::dvar_t* spawn_br_gas;
	IW8::dvar_t* show_watermark;
	IW8::dvar_t* player_sustainAmmo;
	IW8::dvar_t* print_debug;
	IW8::dvar_t* weap_impactType;
	IW8::dvar_t* weap_dismembermentAlwaysEnabled;
	IW8::dvar_t* g_dumpScripts;
}

IW8::cmd_function_s set_byte_f_VAR;
IW8::cmd_function_s set_short_f_VAR;
IW8::cmd_function_s set_int_f_VAR;
IW8::cmd_function_s set_float_f_VAR;
IW8::cmd_function_s set_pointer_f_VAR;
IW8::cmd_function_s quit_f_VAR;
IW8::cmd_function_s openmenu_f_VAR;
IW8::cmd_function_s addbot_f_VAR;
IW8::cmd_function_s addTestClient_f_VAR;
IW8::cmd_function_s ddldump_f_VAR;
IW8::cmd_function_s weapondefdump_f_VAR;
IW8::cmd_function_s view_vehicle_ents_f_VAR;
IW8::cmd_function_s loadout_save_f_VAR;
IW8::cmd_function_s FastRestart_f_VAR;
IW8::cmd_function_s MapRestart_f_VAR;
IW8::cmd_function_s omnvar_set_f_VAR;
IW8::cmd_function_s omnvar_dump_f_VAR;
IW8::cmd_function_s unlockall_f_VAR;
IW8::cmd_function_s dump_weapdefs_f_VAR;
IW8::cmd_function_s load_weapdef_f_VAR;
