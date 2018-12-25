#include <SFML/Graphics.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

using namespace sf;
using namespace std;

double clowdsSpeed = 0.3;

const int gameWidth = 1280;
const int gameHeight = 720; 

const int clowd1Hight = 70;
const int clowd2Hight = 150;
const int clowd3Hight = 300;
const int clowd4Hight = 500;
//const int clowd5Hight
bool clowd1Right = true;
bool clowd2Right = false;
bool clowd3Right = true;
bool clowd4Right = false;

double clowd1Position = 1.0;
double clowd2Position = 1200.0;
double clowd3Position = 600.0;
double clowd4Position = 200.0;
//int clowd5Position = 1200;

Texture backgroundTexture;
Texture clowdTexture;

Sprite background;
Sprite clowd1;
Sprite clowd2;
Sprite clowd3;
Sprite clowd4;

void backgroundPaint(RenderWindow *w)
{
    w->draw(background);

    if (clowd1Position>1280) clowd1Position=-250;
    if (clowd2Position<-200) clowd2Position=1281;
    if (clowd3Position>1280) clowd3Position=-250;
    if (clowd4Position<-200) clowd4Position=1281;

    clowd1.setPosition(clowd1Position, clowd1Hight);
    clowd2.setPosition(clowd2Position, clowd2Hight);
    clowd3.setPosition(clowd3Position, clowd3Hight);
    clowd4.setPosition(clowd4Position, clowd4Hight);

    clowd1Position = clowd1Position + clowdsSpeed; 
    clowd2Position = clowd2Position - clowdsSpeed; 
    clowd3Position = clowd3Position + clowdsSpeed; 
    clowd4Position = clowd4Position - clowdsSpeed; 

    w->draw(clowd1);
    w->draw(clowd2);
    w->draw(clowd3);
    w->draw(clowd4);
    

    std::cout<<clowd1Position<<endl;
}

void init()
{
    //  load Texture

    backgroundTexture.loadFromFile("background.png");
    background.setTexture(backgroundTexture);
    background.setPosition(0,0);

    clowdTexture.loadFromFile("clowd.png");
    clowd1.setTexture(clowdTexture);
    clowd2.setTexture(clowdTexture);
    clowd3.setTexture(clowdTexture);
    clowd4.setTexture(clowdTexture);
}
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    RenderWindow *window = new RenderWindow(VideoMode(gameWidth, gameHeight, 32), "BonyBoy!");
    window->setVerticalSyncEnabled(true);

    init();


    //Font font;
    //if (!font.loadFromFile("sansation.ttf"))
    //    return EXIT_FAILURE;
//
  //
    //// Define the paddles properties
    //sf::Clock AITimer;
    //const sf::Time AITime   = sf::seconds(0.1f);
    // 
    //sf::Clock clock;
    //bool isPlaying = false;
    while (window->isOpen())
    {
        backgroundPaint(window);
      
        sf::Event event;
        while (window->pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window->close();
                break;
            }

            // Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                //if (!isPlaying)
                //{
                //    
                //}
            }

            
        }
        window->display();
        window->clear();

    }

}