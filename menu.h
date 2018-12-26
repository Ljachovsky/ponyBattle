#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace sf;

#define ISMENU       0   
#define GAME         1
#define SETTING      2

class Menu
{
public:
Menu()
{
    //font = new Font();
    font.loadFromFile("ponyFont.ttf");
}
void SetMenuState(int i)
{
    state = i;
}
int GetMenuState()
{
    if (state==ISMENU || state==SETTING)
        return 0;
    else
        return 1;
    
}
void drawMenu(RenderWindow* w)
{
    if (state==ISMENU)
    {
        Text game;
        game.setFont(font);
        game.setString("GAME");
        game.setColor(sf::Color::Black);
        game.setPosition(560, 150);
        w->draw(game);

        Text setting;
        setting.setFont(font);
        setting.setString("setting");
        setting.setColor(sf::Color::Black);
        setting.setPosition(568, 270);
        w->draw(setting);

        Text exit;
        exit.setFont(font);
        exit.setString("exit");
        exit.setColor(sf::Color::Black);
        exit.setPosition(600, 390);
        w->draw(exit);
    } 
    else if (state==SETTING)
    {

    }
    else 
    {
        // ниче не рисуем, со следующим тактом игра запуститься
    }
}

private:
int state = 0;

Font font;
};