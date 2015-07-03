#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
class Hero
{
    public:
        Hero();
        void controlmove(int x,int y);
        sf::Texture thero;
        sf::Sprite shero;
};

#endif // HERO_H
