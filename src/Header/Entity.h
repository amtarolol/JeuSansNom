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

protected:
    float pv = 1.f;
    float vitesse = 1.f;

};


