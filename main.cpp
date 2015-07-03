#include <cstdio>
#include <windows.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Enemy.h"
#include "Hero.h"
#include "Sky.h"
#include "Fire.h"
#include "Disenemy.h"
#include "Enfire.h"
sf::RenderWindow window(sf::VideoMode(480, 680), "Fighters");
Disenemy disenemy;
Enemy enemy[10];
Hero hero;
Fire fire[20];
Sky sky;
Enfire enfire[200];
SYSTEMTIME sys;
int timecnt;
int score;
double speed;
void distroy(Enemy &a,Fire &b)
{
    disenemy.setPos(a.senemy.getPosition().x,a.senemy.getPosition().y);
    b.sfire.setPosition(-1,-1);
    a.senemy.setPosition(0,700);
    sky.mboom.play();
    score+=5;
    if (score>100)
    {
        speed+=0.5;
        for (int i=0;i<10;i++)
        enemy[i].senemy.setPosition(0,800);
        score=0;
    }
}

void gameover()
{
    hero.shero.setPosition(-1000,-1000);
    sky.sgameover.setPosition(0,0);
}

void colltest()
{
    double ex,ey;
    double fx,fy;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<20;j++)
        {
            ex=enemy[i].senemy.getPosition().x;
            ey=enemy[i].senemy.getPosition().y;
            fx=fire[j].sfire.getPosition().x;
            fy=fire[j].sfire.getPosition().y;
            if ((fx-ex<=30)&&(fy-ey<=40)&&(fx-ex>=-5)&&(fy-ey>=-5))
            distroy(enemy[i],fire[j]);
        }
    }
    for (int i=0;i<10;i++)
    {
        ex=enemy[i].senemy.getPosition().x;
        ey=enemy[i].senemy.getPosition().y;
        fx=hero.shero.getPosition().x;
        fy=hero.shero.getPosition().y;
        if ((fx-ex<=20)&&(fy-ey<=30)&&(fx-ex>=-40)&&(fy-ey>=-40))
        gameover();
    }
    for (int i=0;i<200;i++)
    {
        ex=enfire[i].senfire.getPosition().x;
        ey=enfire[i].senfire.getPosition().y;
        fx=hero.shero.getPosition().x;
        fy=hero.shero.getPosition().y;
        if ((fx-ex<=10)&&(fy-ey<=15)&&(fx-ex>=-40)&&(fy-ey>=-40))
        gameover();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    sky.sgameover.setPosition(0,1000);
    sky.mbackground.play();
    timecnt=0;
    score=0;
    speed=1;
    while (window.isOpen())
    {
        sf::Event event;
        for (int i=0;i<10;i++)
        {
            if (enemy[i].senemy.getPosition().y>680)
            enemy[i].senemy.setPosition(rand()%430,0);
        }
        for (int i=0;i<3;i++) enemy[i].downmove(speed);
        for (int i=3;i<6;i++) enemy[i].leftdownmove(speed);
        for (int i=6;i<10;i++) enemy[i].rightdownmove(speed);
        for (int i=0;i<20;i++) fire[i].upmove();
        for (int i=0;i<200;i++) enfire[i].downmove(speed);
        GetLocalTime(&sys);
        //printf("%d %d\n",timecnt,sys.wSecond);
        if ((sys.wSecond-timecnt+60)%60>=4)
        {
            timecnt=sys.wSecond;
            for (int i=0;i<10;i++)
            {
                for (int j=0;j<200;j++)
                {
                    if (enfire[j].senfire.getPosition().y>700)
                    {
                        enfire[j].senfire.setPosition(enemy[i].senemy.getPosition().x+17,enemy[i].senemy.getPosition().y+45);
                        break;
                    }
                }
            }
        }
        colltest();
        if (event.key.code == sf::Keyboard::Escape)
        window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        hero.controlmove(-1,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        hero.controlmove(0,1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        hero.controlmove(0,-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        hero.controlmove(1,0);
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        while (window.pollEvent(event))
        {
            disenemy.sdis1.setPosition(-100,-100);
            if (event.key.code == sf::Keyboard::Space)
            for (int i=0;i<20;i++)
            {
                if (fire[i].sfire.getPosition().y<0)
                {
                    fire[i].sfire.setPosition(hero.shero.getPosition().x+20,hero.shero.getPosition().y);
                    break;
                }
            }
        }

        window.clear();

        window.draw(sky.pbackground);
        window.draw(hero.shero);
        window.draw(disenemy.sdis1);
        for (int i=0;i<10;i++) window.draw(enemy[i].senemy);
        for (int i=0;i<20;i++) window.draw(fire[i].sfire);
        for (int i=0;i<200;i++) window.draw(enfire[i].senfire);
        window.draw(sky.sgameover);
        window.display();
    }

    return 0;
}
