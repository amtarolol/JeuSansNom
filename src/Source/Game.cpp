//
// Created by amtarolol on 24/10/22.
//

#include "../Header/Game.h"

void Game::initVariable() {


    // style d'écriture pour les textes
    font = std::make_shared<sf::Font>();
    if (!font->loadFromFile("/home/amtarolol/Bureau/C++/rss/Fresco_Stamp.ttf"))
    {
        std::cout << "erreur lors récupération font";
    }
    //

    // référence de spawn
    spawn = std::make_unique<sf::RectangleShape>(sf::Vector2f(2.f, 2.f));
    spawn->setPosition(width/2, height/2);
    textSpawn = std::make_unique<sf::Text>();

    textSpawn->setFont(*font);
    std::string text = "Z : Move Up \nQ : Move Left \nD : Move Right \nS : move Down \nSpace : Use your weapon";

    textSpawn->setString(text);
    textSpawn->setCharacterSize(12);
    textSpawn->setStyle(sf::Text::Regular);

    sf::FloatRect killsBox = textSpawn->getLocalBounds();
    textSpawn->setOrigin(killsBox.width /2 , killsBox.height/2);

    sf::Vector2f spawnPos = spawn->getPosition();
    textSpawn->setPosition(spawnPos.x , spawnPos.y - killsBox.height/1.5f);

    // musique
    music.openFromFile("/home/amtarolol/Bureau/C++/rss/The Toxic Avenger - My Only Chance (from Furi original soundtrack).wav");
    music.setVolume(10.f);
    music.setLoop(true);

}


void Game::initPlayer() {
    player = std::make_shared<Player>(sf::Vector2f (width/2,height/2), window);
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



void Game::initSystemColli() {


    systemCollision = std::make_unique<SystemCollision>(player, systemEnnemy);
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


    // initialisation de la fenêtre de jeu, besoin de la taille écran
    initWindow();

    // initialisation des petites infos sans rien, besoin de la taille écran
    initVariable();

    // initialisation du joueur, besoin window, taille écran et armementJoueur
    initPlayer();

    // initialisation du gui pour l'affichage des informations en jeu, besoin taille écran, joueur et font
    initGui();

    // intialisation du système pour les ennemis, besoin joueur et gui
    initSystemEnnemy();

    // initialisation du système pour les collisions, besoin joueur, systemEnnemi et armementJoueur
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

    // generation ennemies
    if (compteurfps %5 == 0){
        systemEnnemy->generatorEnnemy();
    }

    // play music
    if (compteurfps % 240 == 0 and music.getStatus() == sf::Music::Stopped) {
        music.play();
    }
    //

    systemEnnemy->MyUpdate();
    systemCollision->MyUpdate();
    gui->MyUpdate();
    window->setView(*gui);
}

void Game::show(){

    window->clear();


    window->draw(*spawn); // juste une référence pour savoir le spawn (centre de la map)
    window->draw(*textSpawn);


    window->draw(*systemEnnemy);
    window->draw(*player);
    //window->draw(*gui);

    window->draw(*gui);

    window->display();

}


int Game::jouer() {

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








