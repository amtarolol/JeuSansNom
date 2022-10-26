//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Projectiles.h"
#include <ctgmath>

/*Projectiles::Projectiles(sf::Vector2f origine, sf::Vector2i mouseLocation, sf::Time lifeTime) {
    this->setFillColor(sf::Color::Red);
    this->setOrigin(origine);
    this->setPosition(origine);
    this->setRadius(2.f);

    sf::Vector2f distance(mouseLocation.x - origine.x, mouseLocation.y - origine.x);
    float norme = std::sqrt(powf(distance.x, 2) + powf(distance.y, 2));
    sf::Vector2f direction(distance.x / norme, distance.y / norme);

    sf::Vector2f velo(direction.x * 1, direction.y * 1);

    this->velocity = velo;
    this->lifetime = lifeTime;

    update();

}

int Projectiles::mouvement(sf::Time clock) {

    this->lifetime -= clock;

    if (this->lifetime <= sf::Time::Zero){
        return 1;
    }
    move(velocity * clock.asSeconds());

    return 0;
}

sf::Vector2f Projectiles::getPoint(std::size_t index) const {
    return this->getPosition();
}

std::size_t Projectiles::getPointCount() const {
    return 30;
}*/
