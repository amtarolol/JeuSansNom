//
// Created by amtarolol on 26/10/22.
//

#include <iostream>
#include "../Header/SystemProjectiles.h"


SystemProjectiles::SystemProjectiles() = default;


void SystemProjectiles::setLimite(int nouvLimite) {
    limite = nouvLimite;
}


void SystemProjectiles::update(float clock) {
    for (int i = 0; i < projectiles.size(); ++i)
    {
        Projectiles& p = projectiles[i];
        if (p.mouvement(clock) != 0){
            projectiles.erase(projectiles.begin()+i);
        }
    }

}


void SystemProjectiles::addProjectile(sf::Vector2f origine, sf::Vector2f mouseLocation) {
    projectiles.push_back(Projectiles(origine, mouseLocation, 3.f));
}

void SystemProjectiles::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    for (int i = 0; i!= projectiles.size(); ++i){
        target.draw(projectiles[i].getProjectile(), states);
    }
}

std::vector<Projectiles> SystemProjectiles::getProjectiles() {
    return projectiles;
}

SystemProjectiles::~SystemProjectiles() {

}







