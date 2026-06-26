# FPS Game - Visual Studio 2022 Setup Instructions

## 📦 What You Have

This package contains a complete FPS game ready to open in Visual Studio 2022 Community Edition.

## 🔧 Prerequisites

### 1. Visual Studio 2022 Community Edition
Download from: https://visualstudio.microsoft.com/vs/community/

**During installation, make sure to select:**
- "Desktop development with C++"
- Windows 10 SDK (or Windows 11 SDK)

### 2. SDL2 Development Libraries for Windows
You need to download and install SDL2.

## 📥 Installing SDL2 (Required!)

### Option A: Easy Method (Recommended)

1. **Download SDL2 Development Libraries:**
   - Go to: https://github.com/libsdl-org/SDL/releases/latest
   - Download: `SDL2-devel-2.x.x-VC.zip` (Visual C++ version)

2. **Extract SDL2:**
   - Extract the ZIP file
   - You'll see a folder like `SDL2-2.x.x`

3. **Place SDL2 in the Project:**
   ```
   fps_game_vs2022/
   ├── external/
   │   └── SDL2/
   │       ├── include/     (copy the 'include' folder from SDL2)
   │       └── lib/
   │           └── x64/     (copy the 'lib/x64' folder from SDL2)
   ├── include/
   ├── src/
   └── fps_game.sln
   ```

4. **Copy SDL2.dll:**
   - From SDL2's `lib/x64/` folder, copy `SDL2.dll`
   - Paste it in: `fps_game_vs2022/` (same folder as the .sln file)
   - Also copy it to: `fps_game_vs2022/bin/Debug/` and `fps_game_vs2022/bin/Release/`

### Option B: vcpkg Method

```cmd
# Install vcpkg if you don't have it
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat

# Install SDL2
vcpkg install sdl2:x64-windows

# Integrate with Visual Studio
vcpkg integrate install
```

If using vcpkg, you'll need to modify the project properties:
1. Right-click the project → Properties
2. Under "Additional Include Directories", change to: `$(VcpkgRoot)\installed\x64-windows\include`
3. Under "Additional Library Directories", change to: `$(VcpkgRoot)\installed\x64-windows\lib`

## 🚀 Opening and Building the Project

### Step 1: Open the Solution
1. Navigate to the `fps_game_vs2022` folder
2. Double-click `fps_game.sln`
3. Visual Studio 2022 will open

### Step 2: Select Configuration
- At the top of Visual Studio, select:
  - **Platform**: `x64`
  - **Configuration**: `Debug` (for development) or `Release` (for final build)

### Step 3: Build
- Press `F7` or go to `Build` → `Build Solution`
- Wait for the build to complete

### Step 4: Run
- Press `F5` to run with debugging
- Or press `Ctrl+F5` to run without debugging

## 📁 Expected Directory Structure

After setup, your folder should look like:

```
fps_game_vs2022/
├── external/
│   └── SDL2/
│       ├── include/
│       │   └── SDL.h (and other headers)
│       └── lib/
│           └── x64/
│               ├── SDL2.lib
│               └── SDL2main.lib
├── include/           (12 header files)
├── src/               (12 source files)
├── assets/
│   ├── textures/
│   ├── sounds/
│   └── models/
├── bin/
│   ├── Debug/
│   │   └── SDL2.dll   (copy here)
│   └── Release/
│       └── SDL2.dll   (copy here)
├── SDL2.dll           (copy here)
├── fps_game.sln       (Visual Studio solution)
├── fps_game.vcxproj   (Visual Studio project)
├── README.md
├── QUICKSTART.md
├── CHANGELOG.md
└── LICENSE
```

## 🎮 Controls

Once the game is running:

| Key | Action |
|-----|--------|
| W/A/S/D | Move |
| Mouse | Look around |
| Left Mouse Button | Shoot |
| R | Reload |
| Space | Jump |
| F1 | Toggle Debug HUD |
| ESC | Quit |

## 🐛 Troubleshooting

### Problem: "Cannot open include file: 'SDL.h'"
**Solution:** 
- Make sure SDL2 is in the `external/SDL2/` folder
- Check that the path in project properties matches

### Problem: "Unable to start program" or "SDL2.dll not found"
**Solution:**
- Copy `SDL2.dll` to the same folder as `fps_game.sln`
- Copy `SDL2.dll` to `bin/Debug/` and `bin/Release/`

### Problem: "LNK2019: unresolved external symbol"
**Solution:**
- Make sure you're building for x64 (not x86)
- Verify SDL2.lib and SDL2main.lib are in `external/SDL2/lib/x64/`

### Problem: "error MSB8036: The Windows SDK version X was not found"
**Solution:**
- Right-click the project → Properties
- Go to General → Windows SDK Version
- Select your installed SDK version
- Or install the required SDK via Visual Studio Installer

### Problem: Black screen or crash on startup
**Solution:**
- Update your graphics drivers
- Make sure you have OpenGL support
- Check the Output window in Visual Studio for error messages

## 📝 Building for Release

For the final optimized build:

1. Select `Release` configuration (top toolbar)
2. Build the solution (`F7`)
3. Your executable will be in: `bin/Release/fps_game.exe`
4. Copy `SDL2.dll` to the same folder as the .exe
5. Distribute both files together

## 🔄 Switching to Enhanced Branch

This solution contains the base game. If you want the enhanced features:

1. Clone the repository:
   ```cmd
   git clone https://github.com/AHGamez/fps_game.git
   cd fps_game
   git checkout feature/enhanced-gameplay
   ```

2. Copy the updated files to this Visual Studio project
3. Rebuild

## 💡 Tips

- **Debug Mode**: Slower but with debugging symbols (use during development)
- **Release Mode**: Faster and optimized (use for distribution)
- **Output Window**: View debug messages and errors (View → Output)
- **Solution Explorer**: Navigate files (View → Solution Explorer)
- **Start Without Debugging**: `Ctrl+F5` - Game window stays open if it crashes

## 📞 Support

If you encounter issues:

1. Check this file first
2. Review QUICKSTART.md for game details
3. Ensure SDL2 is properly installed
4. Check Visual Studio Output window for errors
5. Visit: https://github.com/AHGamez/fps_game

## 🎉 That's It!

You should now be able to:
1. ✅ Open fps_game.sln in Visual Studio 2022
2. ✅ Build the project (after installing SDL2)
3. ✅ Run and play the game

Enjoy! 🎮
