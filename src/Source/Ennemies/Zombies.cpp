//
// Created by amtarolol on 27/10/22.
//

#include <ctgmath>
#include <iostream>
#include "../../Header/Ennemies/Zombies.h"


Zombies::Zombies(sf::Vector2f position, std::shared_ptr<Entity> target){

    // variables de la classe Entity
    pv = 30.f;
    vitesse = 1.5f;
    giveDamage = 10;

    //

    setSize(sf::Vector2f(taille, taille));
    setFillColor(sf::Color::Yellow);
    setOrigin(getSize().x/2, getSize().y/2);
    setPosition(position);

    setTarget(target); // cible du zombie où il va aller

}

Zombies::~Zombies() = default;

void Zombies::setTarget(std::shared_ptr<Entity> nouvTarget) {

    target = nouvTarget;

}

void Zombies::mouvement() {

    sf::Vector2f targetPos = target->getPosition();
    sf::Vector2f myPos = getPosition();
    sf::Vector2f distance(targetPos.x - myPos.x, targetPos.y - myPos.y);
    float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    sf::Vector2f direction(distance/norme);

    move(direction * vitesse);
}


void Zombies::MyUpdate() {

    mouvement();


}





