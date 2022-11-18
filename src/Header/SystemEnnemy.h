//
// Created by amtarolol on 31/10/22.
//

#include "Component.h"
#include "Player.h"
#include "GUI.h"
#include "Ennemies/Zombies.h"

#include <random>
#include <memory>
#include <chrono>
#include <mutex>

#pragma once

class SystemEnnemy : public Component  {

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



