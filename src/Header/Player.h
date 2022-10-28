//
// Created by amtarolol on 10/10/22.
//

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "SystemProjectiles.h"
#include <memory>

#pragma once

class Player : public Entity{

public:
    Player(sf::Vector2f position);
    ~Player() override;
    void mouvement(sf::Vector2f mouse);

    void MyUpdate() override;
    void setSystemProjectile(std::shared_ptr<SystemProjectiles> nouvSystem);

private:
    std::shared_ptr<SystemProjectiles> system;

};

