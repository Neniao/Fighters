#include "Disenemy.h"

Disenemy::Disenemy()
{
    tdis.loadFromFile("shoot.png");
    sdis1.setTexture(tdis);
    sdis1.setTextureRect(sf::IntRect(536,653,69,90));
    sdis1.setScale(0.5,0.5);
    sdis2.setTexture(tdis);
    sdis2.setTextureRect(sf::IntRect(605,653,69,90));
    sdis2.setScale(0.5,0.5);
    sdis3.setTexture(tdis);
    sdis3.setTextureRect(sf::IntRect(674,653,69,90));
    sdis3.setScale(0.5,0.5);
}

void Disenemy::setPos(double x,double y)
{
    sdis1.setPosition(x,y);
    sdis2.setPosition(x,y);
    sdis3.setPosition(x,y);
}
