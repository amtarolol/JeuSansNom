//
// Created by amtarolol on 22/10/22.
//


#include <iostream>
#include "../Header/Entity.h"

void Entity::mouvement() {
}

void Entity::MyUpdate() {

}

float Entity::getPv() {
    return pv;
}

float Entity::getPvMax() {
    return pvMax;
}

void Entity::takeDamage(float damage) {
    pv -= damage;
}

float Entity::getGiveDamage() {
    return giveDamage;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}

std::shared_ptr<sf::Shape> Entity::getEntity() {
    return entity;
}



