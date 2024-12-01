<!--# Deprecation Notice
This project is unmaintained and no longer supported. Support regarding this project will be instantly dismissed with no help given.

---

<p align="center">
  <img src="/github/assets/donetskbanner.png?raw=true" />
</p>

---

<p align="center">
  <img src="https://img.shields.io/github/v/release/ProjectDonetsk/Donetsk?style=for-the-badge&color=6437c4&include_prereleases">
  <a href="https://discord.gg/banabyte"><img src="https://img.shields.io/discord/945420505157083208?color=6437c4&label=discord&logo=discord&logoColor=ffffff&style=for-the-badge"></a>
  <img src="https://img.shields.io/github/languages/code-size/ProjectDonetsk/Donetsk?style=for-the-badge&color=6437c4&label=size">
</p>

## About
Project Donetsk is an attempt to create a modder-friendly Modern Warfare 2019 with a server browser and GSC.

**The project is currently in beta. Bugs and issues are expected.**

## Features
- Custom content (maps, weapons, cosmetics).
- Server browser.

## Common Issues
- ```Failed to initialize TACT client: E_STORAGE_INIT (25), Invalid build info ```
  - Right click on game folder and uncheck "read-only"
- ```Fatal Error (Of any variety)```
  - Right click on game folder and uncheck "read-only"
- ```DirectX call failed with error: DX ERROR UNKNOWN[OX8000FFFF]. ```
  - This is a DirectX error. The best solution is to reinstall Windows from a recovery USB, but you may have some sucess in simply repairing your Windows installation
-->

[![License](https://img.shields.io/gitlab/license/xifil/iw8-mod.svg)](https://gitlab.com/xifil/iw8-mod/-/blob/develop/LICENSE)
[![Open Issues](https://img.shields.io/gitlab/issues/open/xifil/iw8-mod.svg)](https://gitlab.com/xifil/iw8-mod/-/issues)
[![Discord](https://img.shields.io/discord/769966964030046298?color=%237289DA&label=members&logo=discord&logoColor=%23FFFFFF)](https://discord.gg/dPzJajt)

# iw8-mod

<p align="center">
  <img src="assets/github/banner.png?raw=true" />
</p>

NOTE: You must legally own [Call of Duty®: Modern Warfare](https://store.steampowered.com/app/2000950/) to run this mod. Cracked/Pirated versions of the game are **NOT** supported.

## Compile from source

- Clone the Git repo. Do NOT download it as ZIP, that won't work.
- Update the submodules and run `premake5 vs2022` or simply use the delivered `generate.bat`.
- Build via solution file in `iw8_vs2022.sln`.
<!--
### Premake arguments

| Argument                    | Description                                    |
|:----------------------------|:-----------------------------------------------|
| `--copy-to=PATH`            | Optional, copy the EXE to a custom folder after build, define the path here if wanted. |
| `--dev-build`               | Enable development builds of the client. |

<br/>-->

## Disclaimer

This software has been created purely for the purposes of
academic research. It is not intended to be used to attack
other systems. Project maintainers are not responsible or
liable for misuse of the software. Use responsibly.

## Usage

iw8-mod is currently unusable on the newest version (v1.67)
of Call of Duty®: Modern Warfare, you are required to have
the Season 2 version (v1.20) with the left-over debug
executable, `game_dx12_ship_replay.exe`. Once built, replace
`discord_game_sdk.dll` in your game directory and run
`game_dx12_ship_replay.exe`.

## Credits

- [Donetsk](https://github.com/ProjectDonetsk/Donetsk) - base project
- [s1x-client](https://github.com/HeartbeatingForCenturies/s1x-client) - heavy inspiration

