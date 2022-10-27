//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {

    player = std::make_unique<Player>(sf::Vector2f (10,10));
    system = new SystemProjectiles();

    player->setSystemProjectile(system);
    //proj = std::make_unique<Projectiles>(sf::Vector2f(100,100), sf::Vector2i(110,110), sf::seconds(2.f));
    //projs = projs();
    int limiteProj = 5;
}

void Game::initThread() {

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(500,300), "SFML WINDOW");
    window->setFramerateLimit(60);
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
    sf::Vector2f mouse = sf::Vector2f (sf::Mouse::getPosition(*window));
    player->mouvement(mouse);

    float fps = 1.f/60.f;
    system->update(fps);

}

void Game::show() {

    window->clear();

    // draw
    /*for (int i = 0; i!= system->getProjectiles().size(); ++i){
        window->draw(system->getProjectiles()[i].getProjectile());
    }*/
    //window->draw(proj->getProjectile());

    window->draw(*system);
    window->draw(player->getPlayer());

    window->display();
}


void Game::setLimiteProj(int nouvLimite){


}

Game::~Game() {
}




