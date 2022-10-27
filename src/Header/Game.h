//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../Source/SystemProjectile.cpp"
#include <iostream>
#include <memory>

#pragma once


class Game {

public:
    Game();
    ~Game();

    int jouer();
    void setLimiteProj(int nouvLimite);

private:

    void events();
    void update();
    void show();

    void initVariable();
    void initThread();



    //sf::RenderWindow *window;
    std::unique_ptr<sf::RenderWindow> window;
    //std::shared_ptr<SystemProjectiles> system;
    SystemProjectiles* system;
    std::unique_ptr<Player> player;
    std::unique_ptr<Projectiles> proj;

};

