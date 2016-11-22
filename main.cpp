// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <math.h>
#include "Hero.h"
#include <vector>
// #include "Asteroid.h"


using namespace sf;


int main()
{
    std::vector<Asteroid *> asteroids;
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Hero hero("./Images/hero.png");
    // Asteroid asteroid("./Images/Big1.png");
    Clock clock;
    float time;
    float Cooldown = 600000;
    
    while (window.isOpen())
    {


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::Q)))) {
            hero.ChangeRotation(-3);

        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::E)))) {
            hero.ChangeRotation(3);


        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            //hero_y=BorderRecordY(hero_x=Search_X(hero_x,alpha));
            hero.Moving_Up();
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            hero.Moving_Down();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            //SOSAT EPTI!
            hero.Shoot();
            // std::cout << "PEW PEW " << std::endl;

        }
        time = clock.getElapsedTime().asMicroseconds();
        // std::cout<<time<<" -- TIME"<<"   Cooldown -- "<<Cooldown<<std::endl;
        if (/*Keyboard::isKeyPressed(Keyboard::L) ||*/ time > Cooldown)
        {
            hero.AsteroidAdd();
            if (Cooldown > 1000)
            {
                   Cooldown = Cooldown - 1000;   /* code */
            }

            clock.restart();
        }


        hero.Moving_Up();
        hero.ObjectNear();
        hero.Set_Pos();
        window.clear();
        // Bullets[0]->BulletDraw(window);
        // Bullets[1]->BulletDraw(window);
        // asteroid.DrawAst(window);


        //UBRAT ASTEROIDI V OTDELNII KLASS !!! VAZNOOOO
        hero.DrawShip(window);
        window.display();
    }

    return 0;
}