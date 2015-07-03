#ifndef DISENEMY_H
#define DISENEMY_H

#include <SFML/Graphics.hpp>
class Disenemy
{
    public:
        Disenemy();
        void setPos(double x,double y);
        sf::Texture tdis;
        sf::Sprite sdis1;
        sf::Sprite sdis2;
        sf::Sprite sdis3;
};

#endif // DISENEMY_H
