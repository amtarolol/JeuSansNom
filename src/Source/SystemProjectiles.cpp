//
// Created by amtarolol on 26/10/22.
//

#include <iostream>
#include "../Header/SystemProjectiles.h"


SystemProjectiles::SystemProjectiles() = default;


void SystemProjectiles::setLimite(int nouvLimite) {
    limite = nouvLimite;
}


void SystemProjectiles::MyUpdate() {

    for (int i = 0; i < projectiles.size(); ++i)
    {
        projectiles[i]->MyUpdate();
        if (projectiles[i]->isToDestroy()){
            projectiles.erase(projectiles.begin()+i);
        }
    }
}

void SystemProjectiles::addProjectile(sf::Vector2f origine, sf::Vector2f mouseLocation) {
    projectiles.push_back(std::make_unique<Projectiles>(origine, mouseLocation, 3.f));
}

void SystemProjectiles::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    for (const auto & projectile : projectiles){
        target.draw(*projectile, states);
    }
}

std::vector<std::unique_ptr<Projectiles>>* SystemProjectiles::getProjectiles() {
    return &projectiles;
}

SystemProjectiles::~SystemProjectiles() = default;







