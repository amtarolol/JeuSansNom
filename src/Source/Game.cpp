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


void Game::initSystemColli() {

    systemCollision = std::make_unique<SystemCollision>(player, systemProj, systemEnnemy);
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

    // initialisation du système pour les collisions, besoin joueur, systemEnnemi et systemProj
    initSystemColli();
}

Game::~Game() = default;




void Game::events() {

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Game::update() {

    events();


    if (player->getPv() <= 0){
        window->close();
        std::cout << "perdu !";
    }

    player->MyUpdate();
    systemProj->MyUpdate();

    // generation ennemies
    if (compteurfps %60 == 0){
        systemEnnemy->generatorEnnemy();
    }
    //

    systemEnnemy->MyUpdate();
    systemCollision->MyUpdate();
    gui->MyUpdate();
    window->setView(*gui);
}

void Game::show(){

    window->clear();



    // text pour les kills
    sf::Font font;
    if (!font.loadFromFile("/home/amtarolol/Bureau/C++/rss/Fresco_Stamp.ttf"))
    {
        std::error_code();
    }

    sf::Text kills;
    kills.setFont(font);

    std::string text = "Kills : " + std::to_string(player->getKills());
    kills.setString(text);

    kills.setCharacterSize(20);
    kills.setStyle(sf::Text::Regular);

    sf::Vector2f textScale(kills.getScale());
    kills.setOrigin(textScale.x / 2, textScale.y / 2);

    sf::Vector2f textPos(gui->getPvBarreRestant().getPosition());
    textPos.x += 20; textPos.y -= 20;
    kills.setPosition(textPos);

    window->draw(*spawn); // juste une référence pour savoir le spawn (centre de la map)


    window->draw(*systemProj);
    window->draw(*systemEnnemy);
    window->draw(*player);
    window->draw(*gui);

    window->draw(*gui);
    window->draw(kills);

    window->display();

}


int Game::jouer() {

    window->setView(*gui);

    // main loop
    while (window->isOpen()) {
        // update the game
        update();

        // affichage
        show();
        compteurfps++;
    }
    return 0;
}



void Game::setLimiteProj(int nouvLimite){


}








