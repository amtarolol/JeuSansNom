//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {

    player = std::make_shared<Player>(sf::Vector2f (width/2,height/2));
    system = std::make_shared<SystemProjectiles>();

    player->setSystemProjectile(system);

}



void Game::initWindow() {

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "SFML WINDOW");

    window->setFramerateLimit(60);
}


void Game::initGui() {





}



void Game::getScreenSize() {

    Display* disp = XOpenDisplay(NULL);
    Screen*  scrn = DefaultScreenOfDisplay(disp);
    height = scrn->height;
    width  = scrn->width;

}

Game::Game() {

    // récupération de la taille de l'écran pour l'affichage
    getScreenSize();

    // initialisation de toutes les variables sauf pour le window
    initVariable();

    // initialisation de la fenêtre de jeu
    initWindow();
}

Game::~Game() = default;



int Game::jouer() {

    // main loop
    while (window->isOpen()) {
        // update the game
        update();

        // show the actual game
        show();
        compteurfps++;
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
    sf::Vector2f mouse(sf::Mouse::getPosition(*window));
    player->mouvement(mouse);

    float fps = 1.f/60.f;
    system->update(fps);


    if (compteurfps %60 == 0){
        entites.push_back(std::make_unique<Ennemy>(sf::Vector2f(width-200, height/2), player));
    }

    for (auto & entite : entites){
        entite->mouvement();
    }

}

void Game::show() {

    window->clear();

    // draw
    /*for (int i = 0; i!= system->getProjectiles().size(); ++i){
        window->draw(system->getProjectiles()[i].getProjectile());
    }*/
    //window->draw(proj->getProjectile());

    window->draw(*system);
    window->draw(*player);


    // ennemies
    for (auto &creature : entites){
        window->draw(*creature);
    }

    window->display();
}


void Game::setLimiteProj(int nouvLimite){


}





