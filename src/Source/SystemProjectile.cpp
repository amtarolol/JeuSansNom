//
// Created by amtarolol on 22/10/22.
//

/*#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "../Header/Projectiles.h"

using namespace sf;
using namespace std;


class SystemProjectile : public sf::Drawable{

public:
    SystemProjectile(int limite)
    {
        this->limite = limite;
    }

    void addProjectile(sf::Vector2f origine, sf::Vector2i mouseLocation){

        if (projectiles.size() < limite) {
            projectiles.push_back(Projectile(origine, mouseLocation, sf::seconds(3.f)));
        }
    }

    void update(sf::Time clock){

        for (size_t i = 0; i < projectiles.size(); ++i)
        {
            Projectile& p = projectiles[i];
            if (p.mouvement(clock) != 0){
                projectiles.erase(projectiles.begin()+i);
            }
        }
    }

private:

    virtual void draw(RenderTarget& target, RenderStates states) const
    {

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        for (int i = 0; i!= projectiles.size(); ++i){
            target.draw(projectiles[i], states);
        }
    }


    vector<Projectile> projectiles;
    int limite;

};



*/