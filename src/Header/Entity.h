//
// Created by amtarolol on 22/10/22.
//

#include <SFML/Graphics.hpp>

#ifndef C___ENTITY_H
#define C___ENTITY_H


class Entity {

public:
    Entity(sf::Vector2f position);
    void mouvement();
    void update(sf::Time clock);

private:
    sf::Vector2f position;
    sf::Vector2f velocite;

};


#endif //C___ENTITY_H
