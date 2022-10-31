//
// Created by amtarolol on 31/10/22.
//
#include "SFML/Graphics.hpp"
#include <memory>
#include "Player.h"
#include "SystemProjectiles.h"

#pragma once


class SystemCollision : public sf::Drawable {

public:
    SystemCollision(std::shared_ptr<Player> player, std::shared_ptr<SystemProjectiles> systemProj);
    ~SystemCollision() override;
    void MyUpdate();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

    void collisionAvecPlayer();
    void collisionProjectiles();


    std::shared_ptr<Player> player;
    std::shared_ptr<SystemProjectiles> systemProj;
    //std::shared_ptr<SystemEnnemy> systemEnnemy;


};


