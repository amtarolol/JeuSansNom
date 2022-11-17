//
// Created by amtarolol on 26/10/22.
//

#include <iostream>
#include "../Header/ArmementJoueur.h"


ArmementJoueur::ArmementJoueur() = default;



void ArmementJoueur::MyUpdate() {


    for (int i = 0; i < projectiles.size(); ++i)
    {
        projectiles[i]->MyUpdate();
        if (projectiles[i]->isToDestroy()){
            projectiles.erase(projectiles.begin()+i);
        }
    }

}

void ArmementJoueur::addProjectile(sf::Vector2f origine, sf::Vector2f mouseLocation) {

    projectiles.push_back(std::make_unique<Projectiles>(origine, mouseLocation, 3.f));

}

void ArmementJoueur::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    // pas de texture pour nos projectiles (possibles changements)
    states.texture = NULL;

    for (const auto & projectile : projectiles){
        target.draw(*projectile, states);
    }
}

std::vector<std::unique_ptr<Projectiles>>* ArmementJoueur::getProjectiles() {
    return &projectiles;
}

ArmementJoueur::~ArmementJoueur() = default;







