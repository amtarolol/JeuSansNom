cmake_minimum_required(VERSION 3.23)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ src/main.cpp
        src/Source/Player.cpp
        src/Header/Player.h
        src/Source/Entity.cpp
        src/Header/Entity.h src/Source/Game.cpp src/Header/Game.h src/Source/weapons/Projectiles.cpp src/Header/weapons/Projectiles.h src/Source/ArmementJoueur.cpp src/Header/ArmementJoueur.h src/Source/Ennemies/Zombies.cpp src/Header/Ennemies/Zombies.h src/Source/GUI.cpp src/Header/GUI.h src/Source/SystemCollision.cpp src/Header/SystemCollision.h src/Source/SystemEnnemy.cpp src/Header/SystemEnnemy.h src/Source/Component.cpp src/Header/Component.h)


set(SFML_DIR "rss/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    # SFML version >= 2.5
    #In SFML Version 2.5 or later, ${SFML_LIBRARIES}, ${SFML_DEPENDENCIES}, ${SFML_INCLUDE_DIR} no longer exist. Specify libraries individually.
    target_link_libraries(${PROJECT_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()


# pour openGL
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})





