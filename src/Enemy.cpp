#include "Enemy.h"

Enemy::Enemy()
{
    tenemy.loadFromFile("shoot.png");
    senemy.setTexture(tenemy);
    senemy.setTextureRect(sf::IntRect(0,0,69,90));
    senemy.setScale(0.5,0.5);
    senemy.setPosition(rand()%430,rand()%300);
}

void Enemy::downmove(double speed)
{
    senemy.move(0,0.1*speed);
}

void Enemy::leftdownmove(double speed)
{
    senemy.move(0,0.1*speed);
    if (senemy.getPosition().y>200) senemy.move(-0.2,0);
}

void Enemy::rightdownmove(double speed)
{
    senemy.move(0,0.1*speed);
    if (senemy.getPosition().y>200) senemy.move(0.2,0);
}
