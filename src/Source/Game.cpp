//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {

    player = new Player(sf::Vector2f (10,10));
    //projs = projs();
    int limiteProj = 5;
    window = nullptr;
}

void Game::initThread() {

    window = new sf::RenderWindow(sf::VideoMode(500,300), "SFML WINDOW");
    window->setFramerateLimit(120);
}

Game::Game() {
    initVariable();
    initThread();
}

int Game::jouer() {

    // main loop
    while (window->isOpen()) {
        // update the game
        update();

        // show the actual game
        show();
    }
    return 0;
}


void Game::events() {

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Game::update() {

    events();
    player->mouvement();

}

void Game::show() {

    window->clear();

    // draw
    window->draw(player->getPlayer());


    window->display();

}


void Game::setLimiteProj(int nouvLimite){

    limiteProj = nouvLimite;
}

Game::~Game() {
    delete this->window;
}




