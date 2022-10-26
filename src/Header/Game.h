//
// Created by amtarolol on 24/10/22.
//

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../Source/SystemProjectile.cpp"

#ifndef C___GAME_H
#define C___GAME_H


class Game {

public:
    Game();
    ~Game();

    int jouer();
    void setLimiteProj(int nouvLimite);

private:

    void events();
    void update();
    void show();

    void initVariable();
    void initThread();



    sf::RenderWindow* window;
    Player* player;
    //SystemProjectile* projs;
    int limiteProj;

};


#endif //C___GAME_H
