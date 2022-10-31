//
// Created by amtarolol on 31/10/22.
//

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "GUI.h"
#include "Ennemies/Zombies.h"

#include <random>
#include <memory>
#include <chrono>

#pragma once

class SystemEnnemy : public sf::Drawable  {

public:
    SystemEnnemy(std::shared_ptr<Player> player, std::shared_ptr<GUI> gui);
    ~SystemEnnemy() override;

    void MyUpdate();
    void generatorEnnemy();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<std::unique_ptr<Zombies>>* getEnnemies();


private:

    std::shared_ptr<Player> player;
    std::shared_ptr<GUI> gui;
    std::vector<std::unique_ptr<Zombies>> ennemies;

};



