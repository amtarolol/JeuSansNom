//
// Created by amtarolol on 10/10/22.
//

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ArmementJoueur.h"
#include <memory>


#pragma once

class Player : public Entity{

public:
    Player(sf::Vector2f position, std::shared_ptr<sf::RenderWindow> window);
    ~Player() override;

    void MyUpdate() override;
    void incrementKills();
    int getKills() const;
    std::shared_ptr<ArmementJoueur> getArmement();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

    void mouvement() override;

    std::shared_ptr<ArmementJoueur> armementJoueur;
    std::shared_ptr<sf::RenderWindow> window;

    int kills = 0;
    float taille = 10.f;


};

