#include "Enfire.h"

Enfire::Enfire()
{
    tenfire.loadFromFile("shoot.png");
    senfire.setTexture(tenfire);
    senfire.setTextureRect(sf::IntRect(69,75,10,22));
    senfire.setScale(0.5,0.5);
    senfire.setPosition(0,700);
}

void Enfire::downmove(double speed)
{
    senfire.move(0,0.2*speed);
}

