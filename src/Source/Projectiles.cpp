//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Projectiles.h"
#include <ctgmath>

Projectiles::Projectiles(sf::Vector2f origine, sf::Vector2f mouseLocation, float lifeTime) {

    proj = sf::CircleShape(1.f, 1000);
    proj.setFillColor(sf::Color::Red);
    proj.setOrigin(1.f/2.f, 1.f/2.f);
    proj.setPosition(origine);

    sf::Vector2f distance(mouseLocation.x - origine.x, mouseLocation.y - origine.y);
    float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    sf::Vector2f direction(distance/norme);

    sf::Vector2f velo(direction * accel);


    this->velocity = velo;
    this->lifetime = lifeTime;

}

int Projectiles::mouvement(float clock) {

    lifetime -= clock;

    if (lifetime <= 0){
        return 1;
    }
    //proj.setPosition(proj.getPosition() +sf::Vector2f(velocity));
    proj.move(velocity * clock);
    return 0;
}


sf::CircleShape Projectiles::getProjectile() const {
    return proj;
}

Projectiles::~Projectiles() = default;

