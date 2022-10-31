//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {

    // référence de spawn
    spawn = std::make_unique<sf::RectangleShape>(sf::Vector2f(2.f, 2.f));
    spawn->setPosition(width/2, height/2);
    //

    player = std::make_shared<Player>(sf::Vector2f (width/2,height/2));
    systemProj = std::make_shared<SystemProjectiles>();

    player->setSystemProjectile(systemProj);

}



void Game::initWindow() {

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getFullscreenModes()[0], "SFML WINDOW", sf::Style::Fullscreen);

    window->setFramerateLimit(60);
    window->setView(*gui);
}


void Game::initGui() {

    gui = std::make_shared<GUI>(player, width, height);
}


void Game::initSystemEnnemy() {

    systemEnnemy = std::make_shared<SystemEnnemy>(player, gui);

}



void Game::getScreenSize() {

    Display* disp = XOpenDisplay(NULL);
    Screen*  scrn = DefaultScreenOfDisplay(disp);
    height = scrn->height;
    width  = scrn->width;

}

Game::Game() {

    // cela commence à devenir le bordel


    // récupération de la taille de l'écran pour l'affichage
    getScreenSize();

    // initialisation de toutes les variables sauf pour le window
    initVariable();

    // initialisation du gui pour l'affichage des informations en jeu
    initGui();

    // intialisation du système pour les ennemis
    initSystemEnnemy();

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

    // juste pour avoir la position en pixel de la souris, qu'importe ce qu'il se passe sur l'écran pour les view et window
    sf::Vector2i pixel = sf::Mouse::getPosition(*window);
    sf::Vector2f mouse(window->mapPixelToCoords(pixel));
    player->mouvement(mouse);
    //

    float fps = 1.f/60.f;
    systemProj->update(fps);


    if (compteurfps %60 == 0){
        //entites.push_back(std::make_unique<Zombies>(sf::Vector2f(width - 200, height / 2), player));
        systemEnnemy->generatorEnnemy();
    }

    /*for (auto & entite : entites){
        entite->mouvement();
    }*/

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

    // ennemies
    for (auto &creature : entites){
        window->draw(*creature);
    }

    window->draw(*gui);

    window->display();
}


void Game::setLimiteProj(int nouvLimite){


}






