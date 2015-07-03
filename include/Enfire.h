#ifndef ENFIRE_H
#define ENFIRE_H

#include <SFML/Graphics.hpp>
class Enfire
{
    public:
        Enfire();
        void downmove(double speed);
        sf::Texture tenfire;
        sf::Sprite senfire;
};

#endif // ENFIRE_H
