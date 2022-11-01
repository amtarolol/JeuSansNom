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
    Player(sf::Vector2f position, std::shared_ptr<SystemProjectiles> systemProjectiles, std::shared_ptr<sf::RenderWindow> window);
    ~Player() override;

    void MyUpdate() override;
    void incrementKills();
    int getKills() const;


private:

    void mouvement() override;

    std::shared_ptr<SystemProjectiles> systemProj;
    std::shared_ptr<sf::RenderWindow> window;

    int kills = 0;


};

