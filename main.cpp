#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct point
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(300, 433), "Doodle Jump");
    app.setFramerateLimit(60);

    Texture backgroung,platform,player;
    background.loadFromFile("images/background.png");
    platform.loadFromFile("images/platform.png");
    player.loadFromFile("images/doodle.png");

    Sprite sBackground(background), sPlat(platform), sPers(player);

    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%300;
       plat[i].y=rand()%433;
      }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    dy+=0.2;
    y+=dy;
    if (y>400)  dy=-10;

    if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>433) {plat[i].y=0; plat[i].x=rand()%400;}
    }

    for (int i=0;i<10;i++)
     if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
      && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

    sPers.setPosition(x,y);

    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }

    app.display();
}

    return 0;
}
