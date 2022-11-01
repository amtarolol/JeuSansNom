//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"

#pragma once


class Projectiles : public sf::CircleShape{

public:
    Projectiles(sf::Vector2f origine, sf::Vector2f mouseLocation, float lifeTime);
    ~Projectiles() override;

    void MyUpdate();
    bool isToDestroy() const;
    void destroy();
    float getDamage();


private:

    int mouvement();

    sf::Vector2f velocity;
    float accel = 300.f;
    float lifetime;

    float damage = 5.f;
    bool toDestroy = false;
};

