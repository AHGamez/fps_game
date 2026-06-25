# FPS Game

A complete first-person shooter game built with C++, SDL2, and OpenGL.

## Features

- **First-Person Controls**: WASD movement with mouse look
- **Weapon System**: Shooting with cooldown and reload mechanics
- **Physics**: Gravity, jumping, and AABB collision detection
- **Particle System**: Muzzle flash effects when shooting
- **Room Map**: Explore a room with colored walls and obstacles
- **HUD**: FPS counter, ammo display, crosshair, and reload progress
- **Debug Mode**: Toggle detailed debug information with F1
- **Fixed Timestep**: Consistent 60 FPS game loop

## Quick Start

See [QUICKSTART.md](QUICKSTART.md) for detailed build and run instructions.

### Build (Linux/macOS)
```bash
mkdir build && cd build
cmake ..
make
./bin/fps_game
```

## Controls

- **WASD** - Movement
- **Mouse** - Look around
- **Left Mouse Button** - Shoot
- **R** - Reload
- **Space** - Jump
- **F1** - Toggle debug HUD
- **ESC** - Quit

## Technical Details

- **Engine**: Custom C++ with SDL2 and OpenGL
- **Physics**: Fixed timestep at 60 FPS
- **Collision**: AABB-based collision detection
- **Rendering**: OpenGL immediate mode (for simplicity)

## Project Structure

- `include/` - Header files
- `src/` - Source implementation files
- `assets/` - Game assets (textures, sounds, models)
- `CMakeLists.txt` - Build configuration

## License

MIT License - see [LICENSE](LICENSE) file for details.

## Changelog

See [CHANGELOG.md](CHANGELOG.md) for version history and updates.
