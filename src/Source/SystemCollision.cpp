//
// Created by amtarolol on 31/10/22.
//

#include "../Header/SystemCollision.h"

SystemCollision::SystemCollision(std::shared_ptr<Player> player, std::shared_ptr<SystemProjectiles> systemProj, std::shared_ptr<SystemEnnemy> systemEnnemy) {

    this->player = player;
    this->systemProj = systemProj;
    this->systemEnnemy = systemEnnemy;
}


void SystemCollision::MyUpdate() {

}



void SystemCollision::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}




void SystemCollision::collisionAvecPlayer() {

    sf::FloatRect PlayerBox = player->getGlobalBounds();





}

void SystemCollision::collisionProjectiles() {

}


SystemCollision::~SystemCollision() = default;




