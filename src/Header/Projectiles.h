//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"

#pragma once


class Projectiles{

public:
    Projectiles(sf::Vector2f origine, sf::Vector2f mouseLocation, float lifeTime);
    ~Projectiles();

    int mouvement(float clock);
    sf::CircleShape getProjectile() const;


private:
    sf::Vector2f velocity;
    float accel = 300.f;
    float lifetime;
    sf::CircleShape proj;
};

