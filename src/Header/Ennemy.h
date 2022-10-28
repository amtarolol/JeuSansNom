//
// Created by amtarolol on 27/10/22.
//

#include "SFML/Graphics.hpp"
#include "Entity.h"
#pragma once


class Ennemy : public Entity{


public:
    Ennemy(sf::Vector2f position, std::shared_ptr<Entity> target);
    ~Ennemy();

    void mouvement() override;
    void MyUpdate() override;

    void setTarget(std::shared_ptr<Entity> nouvTarget);

private:

    std::shared_ptr<Entity> target;
    float giveDamage = 10.f;


};

