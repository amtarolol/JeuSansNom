//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Player.h"
#include "Ennemy.h"
#include "SystemProjectiles.h"
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



    std::unique_ptr<sf::RenderWindow> window;
    std::shared_ptr<SystemProjectiles> system;
    std::shared_ptr<Player> player;
    std::unique_ptr<Projectiles> proj;

    std::vector<std::unique_ptr<Entity>> entites;


    float width = 1400.f;
    float height = 700.f;
    int compteurfps = 1;


};

