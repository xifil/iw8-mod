[![License](https://img.shields.io/gitlab/license/xifil/iw8-mod.svg)](https://gitlab.com/xifil/iw8-mod/-/blob/master/LICENSE)
[![Open Issues](https://img.shields.io/gitlab/issues/open/xifil/iw8-mod.svg)](https://gitlab.com/xifil/iw8-mod/-/issues)
[![Discord](https://img.shields.io/discord/769966964030046298?color=%237289DA&label=members&logo=discord&logoColor=%23FFFFFF)](https://discord.gg/dPzJajt)

# iw8-mod

<p align="center">
  <img src="assets/github/banner.png?raw=true" />
</p>

NOTE: You must legally own [Call of Duty®: Modern Warfare](https://store.steampowered.com/app/2000950/) to run this mod. Cracked/Pirated versions of the game are **NOT** supported.

## Compile from source

- Clone the Git repo. Do NOT download it as ZIP, that won't work.
  > You can run
  > ```
  > git clone https://github.com/xifil/iw8-mod.git --recurse-submodules
  > ```
  > or
  > ```
  > git clone https://gitlab.com/xifil/iw8-mod.git --recurse-submodules
  > ```
  > depending on what Git you would like to use, however you always need the `--recurse-submodules` flag.
- Update the submodules and run `premake5 vs2019` or simply use the delivered `generate.bat`.
- Build via solution file in `iw8_vs2019.sln`.

> Currently `vs2022` isn't a valid configuration as any mutex will fail to lock and cause an access violation, if you think you can figure this out you are literally insane, I've tried and failed and nothing I do fixes this.

<!--
### Premake arguments

| Argument                    | Description                                    |
|:----------------------------|:-----------------------------------------------|
| `--copy-to=PATH`            | Optional, copy the EXE to a custom folder after build, define the path here if wanted. |
| `--dev-build`               | Enable development builds of the client. |

<br/>-->

## Download from Actions

GitHub Actions automatically builds the DLL file on each 
commit, you can find the latest build of iw8-mod 
[here](https://xifil.github.io/iw8-redirect).

## Disclaimer

This software has been created purely for the purposes of
academic research. It is not intended to be used to attack
other systems. Project maintainers are not responsible or
liable for misuse of the software. Use responsibly.

## Usage

<!--iw8-mod is currently unusable on the newest version (v1.67)
of Call of Duty®: Modern Warfare, you are required to have
the Season 2 version (v1.20) with the left-over debug
executable, `game_dx12_ship_replay.exe`. Once built, replace
`discord_game_sdk.dll` in your game directory and run
`game_dx12_ship_replay.exe`. Alternatively, you can build in
`ReleaseShip` and launch `ModernWarfare.exe`.-->

iw8-mod supports these versions of Modern Warfare:  
- 1.20.4.7623265 (ModernWarfare & game_dx12_ship_replay) <!-- They're the same exact thing -->
- 1.38.3.9489393
- 1.44.0.10435696

Support may be coming for:  
- 0.01.2.7089334
- 1.03.0.7209368

Keep in mind that only 1.20/replay fully works "online" right now, all other versions don't get past the main menu and crash after ~2 minutes due to anti-tampering mechanisms put in place by Infinity Ward.

The same `discord_game_sdk.dll` can be used for all the versions as it auto-detects the version based on the executable and calculates the signatures based on that.

## Credits

- [t6-mod](https://gitlab.com/xifil/t6-mod) - codebase
- [Donetsk](https://github.com/ProjectDonetsk/Donetsk) - documented code used throughout the project
- [mrondllsrc](https://github.com/Ma3axucTKa/mrondllsrc) - a few hooks and patches
- [s1x-client](https://github.com/HeartbeatingForCenturies/s1x-client) - heavy inspiration
- [String Dump](https://github.com/Sku-111/mw19-gsc-dump) - Modern Warfare 2019 hooks & DVars Dump
- [Alesky.](https://discord.com/users/266189430446882816) - art inspiration, the goat
