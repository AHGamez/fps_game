cmake_minimum_required(VERSION 3.10)
project(FPSGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)


# Include directories
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    
    ${CMAKE_SOURCE_DIR}/include
)

# Source files
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/Camera.cpp
    src/InputHandler.cpp
    src/Player.cpp
    src/Weapon.cpp
    src/Map.cpp
    src/Collision.cpp
    src/ParticleSystem.cpp
    src/DebugHUD.cpp
)

# Header files
set(HEADERS
    include/Game.h
    include/Window.h
    include/Renderer.h
    include/Camera.h
    include/InputHandler.h
    include/Player.h
    include/Weapon.h
    include/Map.h
    include/Collision.h
    include/ParticleSystem.h
    include/DebugHUD.h
    include/Vector3.h
)

# Create executable
add_executable(fps_game ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(fps_game
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    
)

# Platform-specific settings
if(UNIX AND NOT APPLE)
    target_link_libraries(fps_game GL GLU glut)
endif()

# Set output directory
set_target_properties(fps_game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Installation
install(TARGETS fps_game DESTINATION bin)
