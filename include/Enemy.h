#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    public:
        Enemy();
        void downmove(double speed);
        void rightdownmove(double speed);
        void leftdownmove(double speed);
        sf::Texture tenemy;
        sf::Sprite senemy;
};

#endif // ENEMY_H
