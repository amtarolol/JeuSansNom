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
#include "X11/Xlib.h"

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
    void initWindow();
    void initGui();


    void getScreenSize();



    std::unique_ptr<sf::RenderWindow> window;
    std::shared_ptr<SystemProjectiles> system;
    std::shared_ptr<Player> player;
    std::unique_ptr<Projectiles> proj;

    std::vector<std::unique_ptr<Entity>> entites;


    unsigned int width = 0;
    unsigned int height = 0;
    int compteurfps = 1;


};

