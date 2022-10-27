//
// Created by amtarolol on 10/10/22.
//

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "SystemProjectiles.h"
#include <memory>

#pragma once

class Player{

public:
    Player(sf::Vector2f size);
    ~Player();
    void mouvement(sf::Vector2f mouse);
    void update();
    void setSystemProjectile(SystemProjectiles* nouvSystem);
    sf::RectangleShape getPlayer();


private:
    float pv = 100.f;
    float acceleration = 2.f;

    constexpr static const float FRIC = -0.5f;

    sf::Vector2f velo = sf::Vector2f (0,0);
    sf::RectangleShape player;
    //SystemProjectiles projs;
    int limiteProj;
    //std::shared_ptr<SystemProjectiles> system;
    SystemProjectiles* system;

};

