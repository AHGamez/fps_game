# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Enhanced DebugHUD with performance metrics tracking
  - Min/Max FPS tracking
  - Average frame time calculation
  - Session time counter
  - Total frames counter
  - Detailed performance statistics
- Enhanced ParticleSystem with multiple particle types
  - MUZZLE_FLASH: Orange/yellow particles for weapon firing
  - SPARK: Yellow sparks for impact effects
  - SMOKE: Gray smoke particles with rising behavior
  - EXPLOSION: Spherical particle distribution for explosions
- Particle type-specific behaviors
  - Different lifetimes and sizes per type
  - Type-specific physics (smoke rises, explosions expand)
  - Enhanced visual variety
- Active particle counter for performance monitoring
- Frame time tracking for performance analysis
- Multi-type particle emission on weapon fire (muzzle flash + sparks + smoke)

## [1.0.0] - 2026-06-25

### Added
- Complete FPS game implementation with C++ and OpenGL
- Fixed timestep game loop for consistent physics
- WASD movement controls
- Mouse look camera system
- Shooting mechanics with cooldown system
- Weapon reload functionality (R key)
- AABB collision detection system
- Room-based map with obstacles
- FPS counter display
- Crosshair rendering
- Particle system for muzzle flash effects
- Debug HUD (toggle with F1) showing:
  - FPS counter
  - Player position and rotation
  - Forward vector
  - Ammunition count
  - Reload progress
- Player physics with gravity and jumping (Space key)
- SDL2 window management
- OpenGL rendering pipeline

### Technical Details
- Fixed timestep: 60 FPS target
- Player movement speed: 5 units/second
- Jump force: 7 units
- Gravity: -20 units/second²
- Weapon fire rate: 5 rounds/second
- Magazine capacity: 30 rounds
- Reload time: 2 seconds
- Mouse sensitivity: 0.1
- Particle system: 1000 max particles

## [1.0.0] - 2026-06-25

### Initial Release
- Project structure established
- Core game systems implemented
- Basic FPS gameplay functional
