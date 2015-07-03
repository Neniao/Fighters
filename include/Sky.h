#ifndef SKY_H
#define SKY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Sky
{
    public:
        Sky();
        sf::Texture tbackground;
        sf::Sprite pbackground;
        sf::SoundBuffer bbackground;
        sf::Sound mbackground;
        sf::SoundBuffer bboom;
        sf::Sound mboom;
        sf::Texture tgameover;
        sf::Sprite sgameover;
};

#endif // SKY_H
