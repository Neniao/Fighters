#include "Sky.h"

Sky::Sky()
{
    tbackground.loadFromFile("background.png");
    pbackground.setTexture(tbackground);
    bbackground.loadFromFile("game_music.ogg");
    mbackground.setBuffer(bbackground);
    bboom.loadFromFile("enemy1_down.ogg");
    mboom.setBuffer(bboom);
    tgameover.loadFromFile("gameover.png");
    sgameover.setTexture(tgameover);
}
