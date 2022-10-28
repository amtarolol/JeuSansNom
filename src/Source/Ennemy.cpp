//
// Created by amtarolol on 27/10/22.
//

#include <ctgmath>
#include <iostream>
#include "../Header/Ennemy.h"


Ennemy::Ennemy(sf::Vector2f position, std::shared_ptr<Entity> target){

    pv = 100.f;
    vitesse = 1.5f;

    setSize(sf::Vector2f(5.f, 5.f));
    setFillColor(sf::Color::Yellow);
    setOrigin(getSize().x/2, getSize().y/2);
    setPosition(position);

    setTarget(target);

}

Ennemy::~Ennemy() = default;

void Ennemy::setTarget(std::shared_ptr<Entity> nouvTarget) {

    target = nouvTarget;

}

void Ennemy::mouvement() {

    sf::Vector2f targetPos = target->getPosition();
    sf::Vector2f myPos = getPosition();
    sf::Vector2f distance(targetPos.x - myPos.x, targetPos.y - myPos.y);
    float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    sf::Vector2f direction(distance/norme);

    move(direction * vitesse);
}


void Ennemy::MyUpdate() {
}





