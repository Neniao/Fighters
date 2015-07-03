#include "Hero.h"

Hero::Hero()
{
    thero.loadFromFile("shoot.png");
    shero.setTexture(thero);
    shero.setTextureRect(sf::IntRect(0,100,100,100));
    shero.setPosition(190,580);
    shero.setScale(0.5,0.5);
    shero.setColor(sf::Color(255,255,255,170));
}

void Hero::controlmove(int x,int y)
{
    int nx,ny;
    nx=shero.getPosition().x;
    ny=shero.getPosition().y;
    if ((nx+x>430)||(nx+x<0)) return;
    if ((ny+y>630)||(ny+y<0)) return;
    shero.move(x,y);
}

