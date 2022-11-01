#include <ctgmath>
#include "Header/Game.h"
#include "SFML/Graphics.hpp"

int main()
{

    /*sf::RenderWindow window(sf::VideoMode(500,300), "TEST");
    window.setFramerateLimit(60);

    sf::Vector2f origin(500/2, 300/2);


    sf::Font font;
    if (!font.loadFromFile("/home/amtarolol/Bureau/C++/rss/Fresco_Stamp.ttf")){
        return 1;
    }

    sf::Text text;
    text.setFont(font);

    text.setString("test");



    sf::Vertex point = sf::Vertex(sf::Vector2f(500/2,300/2));
    sf::Vector2f mouse = sf::Vector2f (1,1);

    sf::Vertex line[] =
            {
                    sf::Vertex(origin),
                    sf::Vertex(sf::Vector2f(0,0))
            };

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            mouse = sf::Vector2f(sf::Mouse::getPosition(window));
        }


        sf::Vector2f pointPos = point.position;
        sf::Vector2f distance(mouse.x - pointPos.x, mouse.y - pointPos.y);
        float norme = std::sqrt(distance.x * distance.x + distance.y * distance.y);
        sf::Vector2f direction(distance/norme);

        point.position += sf::Vector2f (direction * 2.f);

        //line[1] = sf::Vertex(*mouse);

        window.clear();

        window.draw(text);

        //draw
        //window.draw(line, 2, sf::Lines);
        //window.draw(&point, 1, sf::Points);

        window.display();
    }



    return 0;*/



    Game game;
    return game.jouer();


}


