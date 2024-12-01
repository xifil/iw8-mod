#pragma once
#include "Main.hpp"
#include "engine/iw8/RawFile.hpp"
#include "engine/iw8/XAssetHeader.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"
#include "engine/iw8/enums/XAssetType.hpp"


inline utils::hook::detour db_findxassetheader;
IW8::XAssetHeader DB_FindXAssetHeader_Detour(IW8::XAssetType type, const char* givenName, int allowCreateDefault);

inline utils::hook::detour db_getrawbufferinflate;
const char* DB_GetRawBufferInflate_Detour(const char* file, char* buffer, int length);

inline IW8::SpawnPointEntityRecord* g_customSpawns;
inline char g_customEntityString[0xFFFFFFF];
inline utils::hook::detour load_mapentsasset;
void Load_MapEntsAsset_Detour(IW8::XAssetHeader* mapEnts);

inline char g_customBuffer[0x18000];
inline utils::hook::detour db_getrawbuffer;
void DB_GetRawBuffer_Detour(const IW8::RawFile* rawfile, char* buf, int size);

inline utils::hook::detour load_xmodelasset;
void Load_XModelAsset_Detour(IW8::XAssetHeader* model);