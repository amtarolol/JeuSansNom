//
// Created by amtarolol on 24/10/22.
//

#include "../../Header/weapons/Projectiles.h"
#include <ctgmath>

Projectiles::Projectiles(sf::Vector2f origine, sf::Vector2f mouseLocation, float lifeTime) {

    setRadius(1.f);
    setPointCount(1000);
    setFillColor(sf::Color::Red);
    setOrigin(1.f/2.f, 1.f/2.f);
    setPosition(origine);

    sf::Vector2f distance(mouseLocation.x - origine.x, mouseLocation.y - origine.y);
    float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    sf::Vector2f direction(distance/norme);

    sf::Vector2f velo(direction * accel);


    this->velocity = velo;
    this->lifetime = lifeTime;

}

bool Projectiles::isToDestroy() const {
    return toDestroy;
}

int Projectiles::mouvement() {

    float fps = 1.f / 60.f;
    lifetime -= fps;

    if (lifetime <= 0){
        return 1;
    }
    move(velocity * fps);
    return 0;
}


void Projectiles::MyUpdate() {

    if (mouvement() == 1) {
        destroy();
    }
}

void Projectiles::destroy() {
    toDestroy = true;
}

float Projectiles::getDamage() {
    return damage;
}


Projectiles::~Projectiles() = default;

