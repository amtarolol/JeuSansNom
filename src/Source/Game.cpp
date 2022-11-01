//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {

    // référence de spawn
    spawn = std::make_unique<sf::RectangleShape>(sf::Vector2f(2.f, 2.f));
    spawn->setPosition(width/2, height/2);
    //

}


void Game::initPlayer() {
    player = std::make_shared<Player>(sf::Vector2f (width/2,height/2), systemProj, window);
}


void Game::initWindow() {

    window = std::make_shared<sf::RenderWindow>(sf::VideoMode::getFullscreenModes()[0], "SFML WINDOW", sf::Style::Fullscreen);

    window->setFramerateLimit(60);
}


void Game::initGui() {

    gui = std::make_shared<GUI>(player, width, height);
}


void Game::initSystemEnnemy() {

    systemEnnemy = std::make_shared<SystemEnnemy>(player, gui);

}

void Game::initSystemProj() {

    systemProj = std::make_shared<SystemProjectiles>();
}



void Game::getScreenSize() {

    Display* disp = XOpenDisplay(NULL);
    Screen*  scrn = DefaultScreenOfDisplay(disp);
    height = scrn->height;
    width  = scrn->width;

}

Game::Game() {

    // cela commence à devenir le bordel

    // récupération de la taille de l'écran pour l'affichage, n'a besoin de rien
    getScreenSize();

    // initialisation du système de proj, n'a besoin de rien
    initSystemProj();

    // initialisation de la fenêtre de jeu, besoin de la taille écran
    initWindow();

    // initialisation des petites infos sans rien, besoin de la taille écran
    initVariable();

    // initialisation du joueur, besoin window, taille écran et systemProj
    initPlayer();

    // initialisation du gui pour l'affichage des informations en jeu, besoin taille écran et joueur
    initGui();

    // intialisation du système pour les ennemis, besoin joueur et gui
    initSystemEnnemy();

}

Game::~Game() = default;



int Game::jouer() {

    window->setView(*gui);

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

    player->MyUpdate();
    systemProj->MyUpdate();

    // generation ennemies
    if (compteurfps %60 == 0){
        systemEnnemy->generatorEnnemy();
    }
    //

    systemEnnemy->MyUpdate();
    gui->MyUpdate();
    window->setView(*gui);
}

void Game::show() {

    window->clear();

    window->draw(*spawn); // juste une référence pour savoir le spawn (centre de la map)


    window->draw(*systemProj);
    window->draw(*systemEnnemy);
    window->draw(*player);
    window->draw(*gui);


    window->display();
}


void Game::setLimiteProj(int nouvLimite){


}







