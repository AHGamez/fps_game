# FPS Game - Visual Studio 2022 Edition

Welcome! This is a complete first-person shooter game ready to open in Visual Studio 2022.

## 🚀 Quick Start

### 1. Install Prerequisites
- **Visual Studio 2022 Community** (with "Desktop development with C++")
- **SDL2 Development Libraries** (see SETUP_INSTRUCTIONS.md)

### 2. Setup SDL2
Follow the detailed instructions in **SETUP_INSTRUCTIONS.md** to install SDL2.

**Quick Summary:**
1. Download SDL2-devel-VC.zip from https://github.com/libsdl-org/SDL/releases/latest
2. Extract it
3. Copy `include/` folder to `external/SDL2/include/`
4. Copy `lib/x64/` folder to `external/SDL2/lib/x64/`
5. Copy `SDL2.dll` to project root and bin folders

### 3. Open and Build
1. Double-click `fps_game.sln`
2. Select `x64` platform
3. Press `F7` to build
4. Press `F5` to run

## 📁 What's Included

```
fps_game_vs2022/
├── fps_game.sln              ← Open this in Visual Studio 2022
├── fps_game.vcxproj          ← Project file
├── fps_game.vcxproj.filters  ← File organization
├── SETUP_INSTRUCTIONS.md     ← IMPORTANT: Read this first!
├── README_VS2022.md          ← This file
├── include/                  ← 12 header files
├── src/                      ← 12 source files
├── external/SDL2/            ← Place SDL2 here (see instructions)
├── assets/                   ← Game assets
└── Documentation files       ← README, QUICKSTART, CHANGELOG, LICENSE
```

## 🎮 Game Features

- ✅ Fixed timestep game loop (60 FPS)
- ✅ WASD movement + mouse look
- ✅ Shooting with cooldown
- ✅ Reload system (R key)
- ✅ AABB collision detection
- ✅ Room map with obstacles
- ✅ FPS counter and crosshair
- ✅ Particle effects
- ✅ Debug HUD (F1)
- ✅ Jump and gravity physics

## 🎯 Controls

| Key | Action |
|-----|--------|
| W/A/S/D | Move forward/left/backward/right |
| Mouse | Look around |
| Left Mouse | Shoot |
| R | Reload |
| Space | Jump |
| F1 | Toggle Debug HUD |
| ESC | Quit |

## ⚠️ Important Notes

1. **Must install SDL2** - The project won't build without it. See SETUP_INSTRUCTIONS.md
2. **Use x64 platform** - Not x86/Win32
3. **Copy SDL2.dll** - Must be next to the .exe file
4. **OpenGL required** - Update graphics drivers if issues occur

## 🐛 Common Issues

### "Cannot find SDL.h"
➜ Install SDL2 following SETUP_INSTRUCTIONS.md

### "SDL2.dll not found"
➜ Copy SDL2.dll to the bin/Debug/ or bin/Release/ folder

### Project won't load
➜ Make sure you have Visual Studio 2022 with C++ tools installed

### Black screen or crash
➜ Update graphics drivers, ensure OpenGL support

## 📖 Documentation

- **SETUP_INSTRUCTIONS.md** - How to install SDL2 and build
- **README.md** - Original project README
- **QUICKSTART.md** - Detailed gameplay guide
- **CHANGELOG.md** - Version history and features

## 🔗 Links

- **GitHub Repository**: https://github.com/AHGamez/fps_game
- **SDL2 Download**: https://github.com/libsdl-org/SDL/releases
- **Visual Studio**: https://visualstudio.microsoft.com/vs/community/

## 📝 License

MIT License - See LICENSE file

## 🎉 Ready to Go!

After setting up SDL2 (5 minute process), you'll be ready to:
1. Build the project
2. Run the game
3. Start playing!

**For complete setup instructions, see SETUP_INSTRUCTIONS.md**

Happy coding! 🎮
