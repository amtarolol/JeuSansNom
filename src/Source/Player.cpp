//
// Created by amtarolol on 10/10/22.
//

#include <utility>

#include "../Header/Player.h"


Player::Player(sf::Vector2f position, std::shared_ptr<SystemProjectiles> systemProjectiles, std::shared_ptr<sf::RenderWindow> window) {

    // variables protected de la classe Entity
    pv = 100.f;
    vitesse = 2.f;
    pvMax = 100.f;
    //

    setSize(sf::Vector2f(10.f, 10.f));
    setFillColor(sf::Color::Green);
    setOrigin(getSize().x/2, getSize().y/2);
    setPosition(position);

    systemProj = systemProjectiles;
    this->window = window;
}


Player::~Player() = default;


void Player::MyUpdate() {
    mouvement();

}


void Player::mouvement() {


    sf::Vector2i pixel = sf::Mouse::getPosition(*window);
    sf::Vector2f mouse(window->mapPixelToCoords(pixel));


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
        systemProj->addProjectile(getPosition(), mouse);

    }
}

int Player::getKills() const {
    return kills;
}

void Player::incrementKills() {
    kills++;
}




