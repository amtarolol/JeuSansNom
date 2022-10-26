//
// Created by amtarolol on 10/10/22.
//

#include <SFML/Graphics.hpp>
#include "Entity.h"

#ifndef C___PLAYER_H
#define C___PLAYER_H


class Player{


public:
    Player(sf::Vector2f size);

    ~Player();
    void mouvement();
    sf::RectangleShape getPlayer();


private:
    float pv = 100.f;
    float acceleration = 2.f;

    constexpr static const float FRIC = -0.5f;

    sf::Vector2f velo = sf::Vector2f (0,0);
    sf::RectangleShape player;

};


#endif //C___PLAYER_H
