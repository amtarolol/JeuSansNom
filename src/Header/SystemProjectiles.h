//
// Created by amtarolol on 26/10/22.
//

#include "SFML/Graphics.hpp"
#include "Projectiles.h"

#pragma once


class SystemProjectiles : public sf::Drawable
        {

public:
    SystemProjectiles();
    ~SystemProjectiles() override;

    void setLimite(int nouvLimite);
    void update(float clock);
    void addProjectile(sf::Vector2f origine, sf::Vector2f mouseLocation);
    std::vector<Projectiles> getProjectiles();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

    std::vector<Projectiles> projectiles;
    int limite = 5;
};
