//
// Created by amtarolol on 29/10/22.
//

#include <iostream>
#include "../Header/GUI.h"
#include <mutex>


GUI::GUI(std::shared_ptr<Player> player, unsigned int width, unsigned int height, std::shared_ptr<sf::Font> style) {

    this->player = player;
    this->width = width;
    this->height = height;

    font = style;

    // taille de notre view pour avoir la fen^tre et faire le gui en conséquence
    setSize(this->width/2, this->height/2);
    setCenter(player->getPosition());


    prepareGUI();

}


void GUI::MyUpdate() {

    sf::Vector2f playerPos(player->getPosition());
    setCenter(playerPos);

    prepareGUI();


}

void GUI::prepareGUI() {


    // barre des pv du joueurs

    sf::Vector2f viewSize = getSize();

    float hpPourcent = player->getPv() / player->getPvMax();
    float widthBarre = viewSize.x / 3;
    float heightBarre = 10;


    pvBarreMax.setSize(sf::Vector2f(widthBarre, heightBarre));
    pvBarreMax.setOrigin(widthBarre / 2, heightBarre / 2);

    pvBarreRestant.setSize(sf::Vector2f(widthBarre * hpPourcent, heightBarre));
    pvBarreRestant.setOrigin(widthBarre / 2, heightBarre / 2);

    sf::Vector2f viewPosition = getCenter();
    pvBarreMax.setPosition(viewPosition.x, viewPosition.y + viewSize.y / 2 - heightBarre);
    pvBarreRestant.setPosition(viewPosition.x, viewPosition.y + viewSize.y / 2 - heightBarre);

    pvBarreMax.setFillColor(sf::Color::Black);
    pvBarreRestant.setFillColor(sf::Color::Red);


    pvBarreMax.setOutlineThickness(3.f);
    // - vers foncé pour le contour
    sf::Color color(0,128,0, 75);
    pvBarreMax.setOutlineColor(color);
    // fin barre des pv du joueur



    // text pour les kills

    kills.setFont(*font);

    std::string text = "Kills : " + std::to_string(player->getKills());
    kills.setString(text);

    kills.setCharacterSize(20);
    kills.setStyle(sf::Text::Regular);


    sf::Vector2f textScale(kills.getScale());
    sf::FloatRect killsBox = kills.getLocalBounds();
    kills.setOrigin(killsBox.width /2 , killsBox.height/2);


    sf::Vector2f textPos(pvBarreRestant.getPosition());
    textPos.x += widthBarre/3 * 2;
    textPos.y -= heightBarre/2;
    kills.setPosition(textPos);


}

void GUI::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.texture = NULL;

    target.draw(pvBarreMax);
    target.draw(pvBarreRestant);
    target.draw(kills);
}

sf::RectangleShape GUI::getPvBarreRestant() {
    return pvBarreRestant;
}


GUI::~GUI() = default;


