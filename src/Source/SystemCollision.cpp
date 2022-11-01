//
// Created by amtarolol on 31/10/22.
//

#include <iostream>
#include "../Header/SystemCollision.h"

SystemCollision::SystemCollision(std::shared_ptr<Player> player, std::shared_ptr<SystemProjectiles> systemProj, std::shared_ptr<SystemEnnemy> systemEnnemy) {

    this->player = player;
    this->systemProj = systemProj;
    this->systemEnnemy = systemEnnemy;
}


void SystemCollision::MyUpdate() {

    collisionAvecPlayer();
    collisionProjectiles();

}


void SystemCollision::collisionAvecPlayer() {

    sf::FloatRect PlayerBox = player->getGlobalBounds();

    for (auto & creature : *systemEnnemy->getEnnemies()){
        sf::FloatRect creatureBox = creature->getGlobalBounds();

        if (PlayerBox.intersects(creatureBox) && creature->getCooldown() <= 0) {
            player->takeDamage(creature->getGiveDamage());
            creature->cooldown();

        }
    }
}

void SystemCollision::collisionProjectiles() {

    for (auto & proj : *systemProj->getProjectiles()){

        sf::FloatRect projBox = proj->getGlobalBounds();

        for (auto & creature : *systemEnnemy->getEnnemies()){

            sf::FloatRect creatureBox = creature->getGlobalBounds();

            if (projBox.intersects(creatureBox)){
                creature->takeDamage(proj->getDamage());
                proj->destroy();
            }
        }
    }
}


SystemCollision::~SystemCollision() = default;




