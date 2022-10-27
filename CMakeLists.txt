cmake_minimum_required(VERSION 3.23)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ src/main.cpp
        src/Source/Player.cpp
        src/Header/Player.h
        src/Source/Entity.cpp
        src/Header/Entity.h src/Source/SystemProjectile.cpp src/Source/Game.cpp src/Header/Game.h src/Source/Projectiles.cpp src/Header/Projectiles.h src/Source/SystemProjectiles.cpp src/Header/SystemProjectiles.h)



set(SFML_DIR "/home/amtarolol/Bureau/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    # SFML version >= 2.5
    #In SFML Version 2.5 or later, ${SFML_LIBRARIES}, ${SFML_DEPENDENCIES}, ${SFML_INCLUDE_DIR} no longer exist. Specify libraries individually.
    target_link_libraries(${PROJECT_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()


# Install target
#install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


