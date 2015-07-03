#include "Fire.h"

Fire::Fire()
{
    tfire.loadFromFile("shoot.png");
    sfire.setTexture(tfire);
    sfire.setTextureRect(sf::IntRect(996,986,28,28));
    sfire.setPosition(-1,-1);
    sfire.setScale(0.5,0.5);
    sfire.setColor(sf::Color(100,100,100,100));
}

void Fire::upmove()
{
    sfire.move(0,-0.4);
}
