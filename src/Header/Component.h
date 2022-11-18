//
// Created by amtarolol on 18/11/22.
//

#include "SFML/Graphics.hpp"

#pragma once

// Super classe pour toutes les classes qui ont besoin d'afficher quelque chose
class Component : public sf::Drawable {
public:

    // chaque classe possèdera un méthode MyUpdate pour faire une maj pour l'afficher
    virtual void MyUpdate();

};
