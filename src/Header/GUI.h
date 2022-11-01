//
// Created by amtarolol on 29/10/22.
//

#include "SFML/Graphics.hpp"
#include "Player.h"
#include <memory>
#pragma once

class GUI : public sf::View, public sf::Drawable {

public:
    GUI(std::shared_ptr<Player> player, unsigned int width, unsigned int height);
    ~GUI();
    void MyUpdate();
    void prepareGUI();


    sf::RectangleShape getPvBarreRestant();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:


    sf::RectangleShape pvBarreRestant;
    sf::RectangleShape pvBarreMax;
    std::unique_ptr<sf::Text> kills;
    std::shared_ptr<Player> player;


    unsigned int width;
    unsigned int height;

};

