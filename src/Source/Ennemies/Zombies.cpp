//
// Created by amtarolol on 27/10/22.
//

#include <ctgmath>
#include <iostream>
#include "../../Header/Ennemies/Zombies.h"


Zombies::Zombies(sf::Vector2f position, std::shared_ptr<Entity> target){

    // variables de la classe Entity
    pv = 30.f;
    vitesse = 2.f;
    giveDamage = 10;

    sf::Vector2f size(taille,taille);
    entity = std::make_shared<sf::RectangleShape>(size);
    //


    entity->setFillColor(sf::Color::Yellow);
    entity->setOrigin(size.x/2, size.y/2);
    entity->setPosition(position);

    setTarget(target); // cible du zombie où il va aller

}

Zombies::~Zombies() = default;

void Zombies::setTarget(std::shared_ptr<Entity> nouvTarget) {

    target = nouvTarget;

}

void Zombies::mouvement() {

    sf::Vector2f targetPos = target->getEntity()->getPosition();
    sf::Vector2f myPos = entity->getPosition();
    sf::Vector2f distance(targetPos.x - myPos.x, targetPos.y - myPos.y);
    float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    sf::Vector2f direction(distance/norme);

    entity->move(direction * vitesse);
}


void Zombies::MyUpdate() {

    float fps = 1.f / 60.f;

    if (actualCooldown > 0){
        actualCooldown -= fps;
    }
    mouvement();

}

void Zombies::cooldown() {
    actualCooldown = cooldownDamage;
}


float Zombies::getCooldown() {
    return actualCooldown;
}





