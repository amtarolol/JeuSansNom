//
// Created by amtarolol on 10/10/22.
//

#include "../Header/Player.h"


Player::Player(sf::Vector2f size) {

    player = sf::RectangleShape(size);
    player.setFillColor(sf::Color::Green);
    player.setOrigin(size.x/2, size.y/2);
    //player.setPosition(100,100);
}




Player::~Player() {}

void Player::mouvement() {

    sf::Vector2f accel(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        player.move(-acceleration, 0.f);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player.move(acceleration, 0.f);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        player.move(0.f, -acceleration);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player.move(0.f, acceleration);
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        player.rotate(30.f);
    }

}


sf::RectangleShape Player::getPlayer() {
    return player;
}


