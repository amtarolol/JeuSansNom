//
// Created by amtarolol on 27/10/22.
//

#include "SFML/Graphics.hpp"
#include "../Entity.h"
#pragma once


class Zombies : public Entity{


public:
    Zombies(sf::Vector2f position, std::shared_ptr<Entity> target);
    ~Zombies() override;

    void mouvement() override;
    void MyUpdate() override;

    void cooldown();
    void setTarget(std::shared_ptr<Entity> nouvTarget);

    float getCooldown();

private:

    std::shared_ptr<Entity> target;
    float giveDamage = 10.f;
    float taille = 5.f;


};

