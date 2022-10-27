//
// Created by amtarolol on 22/10/22.
//

#include <SFML/Graphics.hpp>

#pragma once


class Entity : public sf::Shape {

public:
    Entity(sf::Vector2f position);
    void mouvement();
    void update(sf::Time clock);

private:
    sf::Vector2f position;
    sf::Vector2f velocite;

};


