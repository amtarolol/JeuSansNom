//
// Created by amtarolol on 26/10/22.
//

#include "SFML/Graphics.hpp"
#include "Projectiles.h"
#include <mutex>

#pragma once


class SystemProjectiles : public sf::Drawable
        {

public:
    SystemProjectiles();
    ~SystemProjectiles() override;

    void setLimite(int nouvLimite);
    void MyUpdate();
    void addProjectile(sf::Vector2f origine, sf::Vector2f mouseLocation);
    std::vector<std::unique_ptr<Projectiles>>* getProjectiles();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

    std::vector<std::unique_ptr<Projectiles>> projectiles;
    int limite = 5;
};
