// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <math.h>
#include "Hero.h"


using namespace sf;

// float AlphaRecord(float alpha)
// {
//     if(alpha < 0){alpha=358;}
//     if(alpha > 360){alpha=0;}
//         return alpha;
// }

// float BorderRecordX(float hero_x)
// {
//     if(hero_x >= 799){hero_x=5;}
//     if(hero_x <= 0){hero_x=770;}
//     // std::cout<<hero_x<<"-X"<<std::endl;
//     return hero_x;
// }
    
// float BorderRecordY(float hero_x)
// {
//     std::cout<<hero_x<<"-YBegin"<<std::endl;
//     if(hero_x >= 599){hero_x=5;}
//     if(hero_x <= 0){hero_x=570;}
//     std::cout<<hero_x<<"-Y"<<std::endl;
//     return hero_x;
// }
// float Search_X(float  alpha)
// {
//     float x=1;
//     x = x*cos(alpha*3.14/180);
//     std::cout<<"X-"<<x<<std::endl;
//     return x;
// }

// float Search_Y(float  alpha)
// {
//     float y=1;
//     y = y*sin(alpha*3.14/180);
//     return y;
// }



int main()
{
 // // 28#52
 //    float hero_y = 500.0;
 //    float hero_x = 400.0;
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Hero hero("./Images/hero.png");

 //    Image heroimage;
 //    heroimage.loadFromFile("./Images/hero.png");

 //    Texture herotexture;
 //    herotexture.loadFromImage(heroimage);

 //    Sprite herosprite;
 //    herosprite.setTexture(herotexture);
 //    // herosprite.setTextureRect(IntRect());
 //    herosprite.setPosition(hero_x, hero_y);
 //    float alpha = 90.0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){ 
            hero.ChangeRotation(-1);
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){ 
            hero.ChangeRotation(1); 


        }
        if (Keyboard::isKeyPressed(Keyboard::Up)){ 
            //hero_y=BorderRecordY(hero_x=Search_X(hero_x,alpha));
            hero.Moving_Up();
         }
        if (Keyboard::isKeyPressed(Keyboard::Down)){ 
            hero.Moving_Down();
        }

        hero.Set_Pos();        
        window.clear();
        window.draw(hero.RetSprite());
        window.display();
    }

    return 0;
}