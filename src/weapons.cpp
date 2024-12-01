#include "addr_utils.hpp"
#include "weapons.h"
#include "game_inc.h"
#include "functions.hpp"
#include "engine/iw8/WeaponCompleteDef.hpp"
#include "game/game.hpp"

void PM_WeaponUseAmmo_Detour(__int64 playerstate, IW8::Weapon* weapon, char a3, int a4, int hand) {
	bool sv_cheats = Dvar_GetBoolSafe("sv_cheats");

	if (!(Dvars::player_sustainAmmo->m_Current.m_Enabled && sv_cheats)) {
		PM_WeaponUseAmmo.stub<void>(playerstate, weapon, a3, a4, hand);
	}
}

void CG_OverrideImpactEffectType_Detour(uintptr_t localClientNum, unsigned int sourceEntityNum, int* fxImpactType) { // 0x141733CD0_g
	if (Dvars::weap_impactType->m_Current.m_Integer != -1) {
		int impactType = Dvars::weap_impactType->m_Current.m_Integer;
		fxImpactType[2] = impactType;
		//33 = red, 34 = blue, 35 = pink, 36 = green
	}
	// cg_overrideimpacteffecttype.stub<__int64>(localClientNum, sourceEntityNum, fxImpactType);
	cg_overrideimpacteffecttype.stub<void>(localClientNum, sourceEntityNum, fxImpactType);
}

bool BG_GetWeaponDismembermentEnabled_Detour(IW8::Weapon* weapon, bool alt) {
	if (Dvars::weap_dismembermentAlwaysEnabled->m_Current.m_Enabled == true) {
		return true;
	}
	return bg_getweapondismembermentenabled.stub<bool>(weapon, alt);
}

IW8::TracerDef* GetTracerDef(const char* asset) {
	IW8::TracerDef* tracerDef = DB_FindXAssetHeader(IW8::XAssetType::ASSET_TYPE_TRACER, asset, 0).m_TracerDef;
	if (tracerDef) {
		return tracerDef;
	}
	return 0;
}

void Dump_WeaponDef() {
	char path[MAX_PATH + 1];
	strcpy(path, g_Pointers->m_Dvar_GetStringSafe("fs_homepath"));
	strcat(path, "\\players\\weapondef.json");
	bool inFrontend = *(bool*)(0x1459D1750_g);
	if (!inFrontend) {
		nlohmann::json weaponDefJson;
		IW8::WeaponCompleteDef** bg_weaponCompleteDefs = (IW8::WeaponCompleteDef**)(0x14C6EC870_g);
		for (int i = 0; i < 550; i++) {
			IW8::WeaponCompleteDef* weap = bg_weaponCompleteDefs[i];
			if (!weap) {
				continue;
			}
			if (strstr(weap->m_InternalName, "iw8") && !strstr(weap->m_InternalName, "watch") && !strstr(weap->m_InternalName, "execution") && !strstr(weap->m_InternalName, "plyr")) {
				// WeaponCompleteDef
				weaponDefJson[weap->m_InternalName]["vfxImpactType"] = weap->m_VFXImpactType;
				weaponDefJson[weap->m_InternalName]["iClipSize"] = weap->m_ClipSize;
				weaponDefJson[weap->m_InternalName]["penetrateMultiplier"] = weap->m_PenetrateMultiplier;

				// ZoomSettings
				weaponDefJson[weap->m_InternalName]["zoomSetting"]["weapon"]["adsZoomFov"] = weap->m_ZoomSettings.m_Weapon.m_ADSZoomFov;

				// WeaponDamageInfo
				for (int i = 0; i < 3; ++i) {
					weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["minDamage"] = weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_MinDamage;
					weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid1Damage"] = weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid1Damage;
					weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid2Damage"] = weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid2Damage;
					weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid3Damage"] = weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid3Damage;
					weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["damage"] = weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Damage;
				}

				// spread
				weaponDefJson[weap->m_InternalName]["playerSpread"] = weap->m_WeapDef->m_PlayerSpread;
				weaponDefJson[weap->m_InternalName]["hipSpreadStandMax"] = weap->m_WeapDef->m_HipSpreadStandMax;

				weaponDefJson[weap->m_InternalName]["adsMoveSpeedScale"] = weap->m_WeapDef->m_ADSMoveSpeedScale;
				weaponDefJson[weap->m_InternalName]["fAdsIdleAmount"] = weap->m_WeapDef->m_ADSIdleAmount;
				weaponDefJson[weap->m_InternalName]["adsSpeedMs_0"] = weap->m_WeapDef->m_ADSSpeedMs[0];

				// WeaponDef
				weaponDefJson[weap->m_InternalName]["ladderWeapon"] = weap->m_WeapDef->m_LadderWeapon;
				weaponDefJson[weap->m_InternalName]["canHoldBreath"] = weap->m_WeapDef->m_CanHoldBreath;
				weaponDefJson[weap->m_InternalName]["iFireTime"] = weap->m_WeapDef->m_FireTime;
				weaponDefJson[weap->m_InternalName]["bBoltAction"] = weap->m_WeapDef->m_BoltAction;
				weaponDefJson[weap->m_InternalName]["fireType"] = weap->m_WeapDef->m_FireType;
				weaponDefJson[weap->m_InternalName]["iStartAmmo"] = weap->m_WeapDef->m_StartAmmo;
				weaponDefJson[weap->m_InternalName]["iMaxAmmo"] = weap->m_WeapDef->m_MaxAmmo;
				if (weap->m_WeapDef->m_TracerType) {
					weaponDefJson[weap->m_InternalName]["tracerType"] = weap->m_WeapDef->m_TracerType->m_Name;
				}
			}
		}
		std::ofstream JsonOut(path);
		JsonOut << weaponDefJson;
	}
	else {
		Com_SetErrorMessage("[DLL ERROR] Must be in-game to dump WeaponDef.");
	}
}

void Load_WeaponDef() {
	char path[MAX_PATH + 1];
	strcpy(path, g_Pointers->m_Dvar_GetStringSafe("fs_homepath"));
	strcat(path, "\\players\\weapondef.json");
	bool inFrontend = *(bool*)(0x1459D1750_g);
	if (!inFrontend) {
		if (file_exists(path)) {
			std::ifstream jsonPath(path);
			nlohmann::json weaponDefJson = nlohmann::json::parse(jsonPath);
			IW8::WeaponCompleteDef** bg_weaponCompleteDefs = (IW8::WeaponCompleteDef**)(0x14C6EC870_g);
			for (int i = 0; i < 550; i++) {
				IW8::WeaponCompleteDef* weap = bg_weaponCompleteDefs[i];
				if (!weap) {
					continue;
				}
				if (weaponDefJson.contains(weap->m_InternalName)) {
					// WeaponCompleteDef
					weap->m_VFXImpactType = weaponDefJson[weap->m_InternalName]["vfxImpactType"];
					weap->m_ClipSize = weaponDefJson[weap->m_InternalName]["iClipSize"];
					weap->m_PenetrateMultiplier = weaponDefJson[weap->m_InternalName]["penetrateMultiplier"];

					// ZoomSettings
					weap->m_ZoomSettings.m_Weapon.m_ADSZoomFov = weaponDefJson[weap->m_InternalName]["zoomSetting"]["weapon"]["adsZoomFov"];

					// WeaponDef

					// WeaponDamageInfo
					for (int i = 0; i < 3; ++i) {
						weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_MinDamage = weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["minDamage"];
						weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid1Damage = weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid1Damage"];
						weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid2Damage = weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid2Damage"];
						weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Mid3Damage = weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["mid3Damage"];
						weap->m_WeapDef->m_DamageInfo.m_DamageData[i].m_Damage = weaponDefJson[weap->m_InternalName]["damageInfo"]["damageData"][i]["damage"];
					}

					// spread
					weap->m_WeapDef->m_PlayerSpread = weaponDefJson[weap->m_InternalName]["playerSpread"];
					weap->m_WeapDef->m_HipSpreadStandMax = weaponDefJson[weap->m_InternalName]["hipSpreadStandMax"];

					weap->m_WeapDef->m_ADSMoveSpeedScale = weaponDefJson[weap->m_InternalName]["adsMoveSpeedScale"];
					weap->m_WeapDef->m_ADSIdleAmount = weaponDefJson[weap->m_InternalName]["fAdsIdleAmount"];
					weap->m_WeapDef->m_ADSSpeedMs[0] = weaponDefJson[weap->m_InternalName]["adsSpeedMs_0"];

					weap->m_WeapDef->m_LadderWeapon = weaponDefJson[weap->m_InternalName]["ladderWeapon"];
					weap->m_WeapDef->m_CanHoldBreath = weaponDefJson[weap->m_InternalName]["canHoldBreath"];
					weap->m_WeapDef->m_FireTime = weaponDefJson[weap->m_InternalName]["iFireTime"];
					weap->m_WeapDef->m_BoltAction = weaponDefJson[weap->m_InternalName]["bBoltAction"];
					weap->m_WeapDef->m_FireType = weaponDefJson[weap->m_InternalName]["fireType"];
					weap->m_WeapDef->m_StartAmmo = weaponDefJson[weap->m_InternalName]["iStartAmmo"];
					weap->m_WeapDef->m_MaxAmmo = weaponDefJson[weap->m_InternalName]["iMaxAmmo"];

					if (weaponDefJson[weap->m_InternalName].contains("tracerType")) {
						weap->m_WeapDef->m_TracerType = GetTracerDef(weaponDefJson[weap->m_InternalName]["tracerType"].get<std::string>().c_str());
					}
				}
			}
		}
		else {
			Com_SetErrorMessage("[DLL ERROR] weapondef JSON is not present in players directory.");
		}
	}
	else {
		Com_SetErrorMessage("[DLL ERROR] Must be in-game to load custom WeaponDef.");
	}
}