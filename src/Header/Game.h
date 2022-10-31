//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Player.h"
#include "Ennemies/Zombies.h"
#include "SystemProjectiles.h"
#include "SystemEnnemy.h"
#include "GUI.h"



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
    void initSystemEnnemy();


    void getScreenSize();



    std::unique_ptr<sf::RenderWindow> window;
    std::shared_ptr<GUI> gui;
    std::shared_ptr<SystemProjectiles> systemProj;
    std::shared_ptr<Player> player;
    std::shared_ptr<SystemEnnemy> systemEnnemy;

    std::unique_ptr<sf::RectangleShape> spawn; // inutile, juste là pour avoir une référence

    std::vector<std::unique_ptr<Entity>> entites;


    unsigned int width = 0;
    unsigned int height = 0;
    int compteurfps = 1;


};

