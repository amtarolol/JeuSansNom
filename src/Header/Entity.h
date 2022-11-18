//
// Created by amtarolol on 22/10/22.
//

#include <memory>
#include <mutex>
#include "Component.h"

#pragma once


class Entity : public Component {

public:

    virtual float getPv();
    virtual float getPvMax();
    virtual float getGiveDamage();
    virtual void takeDamage(float damage);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    std::shared_ptr<sf::Shape> getEntity();

protected:

    virtual void mouvement();


    float pv = 1.f;
    float vitesse = 1.f;
    float pvMax = 1.f;
    float giveDamage = 1.f; // uniquement pour les monstres, dégàts donnés au joueur

    float cooldownDamage = 1.f; // pour éviter que les monstres one-shot le joueur
    float actualCooldown = 0.f;


    std::shared_ptr<sf::Shape> entity;

};


