//
// Created by amtarolol on 31/10/22.
//
#include "SFML/Graphics.hpp"
#include <memory>
#include "Player.h"
#include "ArmementJoueur.h"
#include "SystemEnnemy.h"

#pragma once


class SystemCollision {

public:
    SystemCollision(std::shared_ptr<Player> player, std::shared_ptr<SystemEnnemy> systemEnnemy);
    ~SystemCollision();
    void MyUpdate();


private:

    void collisionAvecPlayer();
    void collisionProjectiles();


    std::shared_ptr<Player> player;
    std::shared_ptr<ArmementJoueur> systemProj;
    std::shared_ptr<SystemEnnemy> systemEnnemy;


};


