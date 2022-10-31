//
// Created by amtarolol on 22/10/22.
//

#include <SFML/Graphics.hpp>
#include <memory>

#pragma once


class Entity : public sf::RectangleShape {

public:

    virtual void mouvement();
    virtual void MyUpdate();

    virtual float getPv();
    virtual float getPvMax();
    virtual void takeDamage(float damage);

protected:
    float pv = 1.f;
    float vitesse = 1.f;
    float pvMax = 1.f;

};


