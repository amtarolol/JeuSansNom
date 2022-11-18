//
// Created by amtarolol on 22/10/22.
//


#include "../Header/Entity.h"

void Entity::mouvement() {
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

std::shared_ptr<sf::Shape> Entity::getEntity() {
    return entity;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*entity);
}

