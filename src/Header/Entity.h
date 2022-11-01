//
// Created by amtarolol on 22/10/22.
//

#include <SFML/Graphics.hpp>
#include <memory>

#pragma once


class Entity : public sf::RectangleShape {

public:

    virtual void MyUpdate();

    virtual float getPv();
    virtual float getPvMax();
    virtual float getGiveDamage();
    virtual void takeDamage(float damage);

protected:

    virtual void mouvement();


    float pv = 1.f;
    float vitesse = 1.f;
    float pvMax = 1.f;
    float giveDamage = 1.f; // uniquement pour les monstres, dégàts donnés au joueur

    float cooldownDamage = 1.f; // pour éviter que les monstres one-shot le joueur

};


