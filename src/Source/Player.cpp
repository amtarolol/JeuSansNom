//
// Created by amtarolol on 10/10/22.
//

#include <utility>

#include "../Header/Player.h"


Player::Player(sf::Vector2f position, std::shared_ptr<sf::RenderWindow> window) {

    // variables protected de la classe Entity
    pv = 100.f;
    vitesse = 2.f;
    pvMax = 100.f;

    sf::Vector2f size(taille, taille);

    entity = std::make_shared<sf::RectangleShape>(size);
    //


    entity->setFillColor(sf::Color::Green);
    entity->setOrigin(size.x/2, size.y/2);
    entity->setPosition(position);

    armementJoueur = std::make_shared<ArmementJoueur>();

    this->window = window;
}


Player::~Player() = default;


void Player::MyUpdate() {
    mouvement();

    armementJoueur->MyUpdate();

}


void Player::mouvement() {


    sf::Vector2i pixel = sf::Mouse::getPosition(*window);
    sf::Vector2f mouse(window->mapPixelToCoords(pixel));


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        entity->move(-vitesse, 0.f);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        entity->move(vitesse, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        entity->move(0.f, -vitesse);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        entity->move(0.f, vitesse);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        armementJoueur->addProjectile(entity->getPosition(), mouse);
    }
}

int Player::getKills() const {
    return kills;
}

void Player::incrementKills() {
    kills++;
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*armementJoueur);
    target.draw(*entity);
}

std::shared_ptr<ArmementJoueur> Player::getArmement() {
    return armementJoueur;
}






