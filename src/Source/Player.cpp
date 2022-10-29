//
// Created by amtarolol on 10/10/22.
//

#include <utility>

#include "../Header/Player.h"


Player::Player(sf::Vector2f position) {

    // variables protected de la classe Entity
    pv = 100.f;
    vitesse = 2.f;
    //


    setSize(sf::Vector2f(10.f, 10.f));
    setFillColor(sf::Color::Green);
    setOrigin(getSize().x/2, getSize().y/2);
    setPosition(position);
}


Player::~Player() = default;


void Player::MyUpdate() {
    //mouvement();

}


void Player::mouvement(sf::Vector2f mouse) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        move(-vitesse, 0.f);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        move(vitesse, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        move(0.f, -vitesse);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        move(0.f, vitesse);
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        rotate(30.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        system->addProjectile(getPosition(), mouse);
    }
}


void Player::setSystemProjectile(std::shared_ptr<SystemProjectiles> nouvSystem) {
    system = nouvSystem;
}


