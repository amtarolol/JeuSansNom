//
// Created by amtarolol on 31/10/22.
//

#include <iostream>
#include "../Header/SystemEnnemy.h"


const double pi = std::acos(-1);

SystemEnnemy::SystemEnnemy(std::shared_ptr<Player> player, std::shared_ptr<GUI> gui) {

    this->player = player;
    this->gui = gui;

}

void SystemEnnemy::MyUpdate() {

    for (auto & entite : ennemies){
        entite->MyUpdate();
    }

}

void SystemEnnemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    for (auto & entite : ennemies){
        target.draw(*entite);
    }

}

std::vector<std::unique_ptr<Zombies>>* SystemEnnemy::getEnnemies() {
    return &ennemies;
}

void SystemEnnemy::generatorEnnemy() {

    // variable pour avoir la plus grand distance du gui et la considéré comme notre valeur minimal (en dehors du gui donc)
    float miniRadius = std::max(gui->getSize().x, gui->getSize().y);
    float maxRadius = miniRadius + 10;
    sf::Vector2f guiCenter = gui->getCenter();


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // simulation d'un cercle tout autour du gui en tant que zone spawnable pour les ennemis
    std::uniform_int_distribution<int> getAngle(0,360);
    float angle = getAngle(generator) * (pi / 180) ;


    float minX = std::cos(angle) * miniRadius, minY = std::sin(angle) * miniRadius;
    float maxX = std::cos(angle) * maxRadius, maxY = std::sin(angle) * maxRadius;

    // génération de X et Y random dans la zone spawnable
    std::uniform_real_distribution<float> distributionX(minX, maxX);
    float x = distributionX(generator) + guiCenter.x;

    std::uniform_real_distribution<float> distributionY(minY, maxY);
    float y = distributionY(generator) + guiCenter.y;

    sf::Vector2f coord(x,y);

    ennemies.push_back(std::make_unique<Zombies>(coord, player));

}



SystemEnnemy::~SystemEnnemy() = default;
