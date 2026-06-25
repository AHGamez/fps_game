# Quick Start Guide

## Prerequisites

Before building the FPS game, ensure you have the following installed:

- **CMake** (version 3.10 or higher)
- **C++ Compiler** with C++17 support (GCC, Clang, or MSVC)
- **SDL2** development libraries
- **OpenGL** development libraries
- **GLUT** (FreeGLUT on Linux, GLUT on macOS/Windows)

### Installing Dependencies

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install cmake build-essential libsdl2-dev libgl1-mesa-dev freeglut3-dev
```

#### macOS (using Homebrew)
```bash
brew install cmake sdl2
```

#### Windows
Download and install:
- [CMake](https://cmake.org/download/)
- [SDL2 Development Libraries](https://www.libsdl.org/download-2.0.php)
- Visual Studio with C++ support

## Building the Game

1. **Clone or navigate to the repository:**
   ```bash
   cd fps_game
   ```

2. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake:**
   ```bash
   cmake ..
   ```

4. **Build the project:**
   ```bash
   cmake --build .
   ```
   
   Or on Unix systems:
   ```bash
   make
   ```

5. **Run the game:**
   ```bash
   ./bin/fps_game
   ```
   
   Or on Windows:
   ```cmd
   bin\fps_game.exe
   ```

## Controls

### Movement
- **W** - Move forward
- **S** - Move backward
- **A** - Strafe left
- **D** - Strafe right
- **Space** - Jump

### Combat
- **Left Mouse Button** - Shoot
- **R** - Reload weapon

### Camera
- **Mouse** - Look around

### Interface
- **F1** - Toggle debug HUD
- **ESC** - Quit game

## Gameplay Tips

1. **Movement**: Use WASD keys to navigate the room. The camera follows your mouse movement.

2. **Combat**: Click the left mouse button to shoot. Watch your ammo counter in the top-left corner.

3. **Reloading**: Press R to reload when your magazine is empty or running low. Reloading takes 2 seconds.

4. **Collision**: You cannot walk through walls or obstacles. Use this to your advantage for cover.

5. **Debug Info**: Press F1 to see detailed information including:
   - Current FPS
   - Player position coordinates
   - Camera orientation (yaw/pitch)
   - Forward direction vector
   - Ammunition status

## Features

- **Fixed Timestep Game Loop**: Ensures consistent physics at 60 FPS
- **First-Person Camera**: Smooth mouse look with pitch clamping
- **Weapon System**: Automatic weapon with cooldown and reload mechanics
- **Particle Effects**: Muzzle flash particles when shooting
- **Collision Detection**: AABB-based collision with walls and obstacles
- **Room Map**: Explore a room with multiple colored obstacles
- **HUD Elements**: 
  - FPS counter
  - Ammunition display
  - Reload progress bar
  - Crosshair
  - Control hints
- **Debug Mode**: Comprehensive debug information overlay

## Troubleshooting

### Game won't compile
- Ensure all dependencies are properly installed
- Check that SDL2 and OpenGL libraries are in your system's library path
- Verify CMake can find all required packages

### Game crashes on startup
- Make sure your graphics drivers are up to date
- Verify OpenGL support is available on your system
- Check terminal/console for error messages

### Mouse not captured
- The game uses SDL's relative mouse mode
- If you lose mouse focus, press ESC to quit and restart
- Some window managers may interfere with mouse capture

### Poor performance
- Check your FPS in the top-left corner
- Ensure you're not running in software rendering mode
- Close other GPU-intensive applications

## Project Structure

```
fps_game/
├── include/           # Header files
│   ├── Camera.h
│   ├── Collision.h
│   ├── DebugHUD.h
│   ├── Game.h
│   ├── InputHandler.h
│   ├── Map.h
│   ├── ParticleSystem.h
│   ├── Player.h
│   ├── Renderer.h
│   ├── Vector3.h
│   ├── Weapon.h
│   └── Window.h
├── src/              # Source files
│   ├── Camera.cpp
│   ├── Collision.cpp
│   ├── DebugHUD.cpp
│   ├── Game.cpp
│   ├── InputHandler.cpp
│   ├── main.cpp
│   ├── Map.cpp
│   ├── ParticleSystem.cpp
│   ├── Player.cpp
│   ├── Renderer.cpp
│   ├── Weapon.cpp
│   └── Window.cpp
├── assets/           # Game assets (textures, sounds, etc.)
├── CMakeLists.txt    # Build configuration
├── LICENSE           # MIT License
├── README.md         # Project overview
├── CHANGELOG.md      # Version history
└── QUICKSTART.md     # This file
```

## Development

To modify or extend the game:

1. **Add new features**: Edit the relevant source files in `src/` and headers in `include/`
2. **Rebuild**: Run `make` or `cmake --build .` in the build directory
3. **Test**: Run the executable to verify your changes

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.
