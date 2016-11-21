//aster.cpp
#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(std::string name)
{
	// std::cout<<"ETO KRUTO"<<Images[0]<<"<----IMAGES     nameIMage----->"<<nameImage<<std::endl;
	asteroid_x = rand()%800;
	asteroid_y = rand()%600;
	alpha = rand()%360;
	nameImages.push_back("Images/media/Meteor/Big1.png");
	nameImages.push_back("Images/media/Meteor/Big2.png");
	nameImages.push_back("Images/media/Meteor/Big3.png");
	nameImages.push_back("Images/media/Meteor/Big4.png");
	nameImages.push_back("Images/media/Meteor/Medium2.png");
	nameImages.push_back("Images/media/Meteor/Medium1.png");
	nameImages.push_back("Images/media/Meteor/Small1.png");
	nameImages.push_back("Images/media/Meteor/Small2.png");
	nameImages.push_back("Images/media/Meteor/Small3.png");
	nameImages.push_back("Images/media/Meteor/Small4.png");


	nameImage=nameImages[rand()%10];
	// std::cout<<"ETO KRUTO"<<Images[0]<<"<----IMAGES     nameIMage----->"<<nameImage<<std::endl;

	asteroidImage.loadFromFile(nameImage);
	asteroidTexture.loadFromImage(asteroidImage);
	asteroidSprite.setTexture(asteroidTexture);
	asteroidSprite.setPosition(asteroid_x, asteroid_y);
	asteroidSprite.setRotation(alpha);
	Pixels = asteroidImage.getSize(); 	

	asteroidSprite.setOrigin(Vector2f(Pixels.x/2,Pixels.y/2));
	std::cout<<Pixels.x<<"-X "<<Pixels.y<<"-Y   \n"<<"--ASTEROID_X Y"<<asteroid_x<<"   "<<asteroid_y<<std::endl;
}


void Asteroid::DrawAst(sf::RenderTarget& target)
{
	BorderRecord_Y();
	BorderRecord_X();
	asteroid_y=asteroid_y+Search_Y(alpha);
	asteroid_x=asteroid_x+Search_X(alpha);

	 asteroidSprite.setPosition(asteroid_x, asteroid_y);
	 target.draw(asteroidSprite);
}


float Asteroid::Search_X(float  alpha)
{
    float x=1;
    x = x*cos(alpha*3.14/180);
    // std::cout<<"X-"<<x<<std::endl;
    return x;
}

float Asteroid::Search_Y(float  alpha)
{
    float y=1;
    y = y*sin(alpha*3.14/180);
    return y;
}


void Asteroid::BorderRecord_X()
{
    if(asteroid_x >= 799){alpha=180 - alpha;}
    if(asteroid_x <= 0){alpha = alpha - 90 ;}
    // std::cout<<hero_x<<"-X"<<std::endl;
}
    
void Asteroid::BorderRecord_Y()
{
    // std::cout<<hero_x<<"-YBegin"<<std::endl;
    if(asteroid_y >= 599){alpha =alpha - 90;}
    if(asteroid_y <= 0){alpha = alpha - 90;}
    // std::cout<<hero_x<<"-Y"<<std::endl;
}