#ifndef FIRE_H
#define FIRE_H

#include <SFML/Graphics.hpp>
class Fire
{
    public:
        Fire();
        void upmove();
        sf::Texture tfire;
        sf::Sprite sfire;
};

#endif // FIRE_H
