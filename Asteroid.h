//Asteroids
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace sf;
class Asteroid
{
private:
	float asteroid_x = 100;
	float asteroid_y = 100;
	float alpha = 0;	
	Sprite asteroidSprite;
	Image asteroidImage;
	Texture asteroidTexture;
	std::string nameImage;
	Clock clock;
	float time;
	// std::vector<std::string> Images;
	Vector2<unsigned int> Pixels;
	std::vector<std::string> nameImages;
public:
	Asteroid(int Percent,int Plused);
	void DrawAst(sf::RenderTarget*);
	float Get_x(){return asteroid_x;}
	float Get_y(){return asteroid_y;}
	float Search_X(float);
	float Search_Y(float);
	void  BorderRecord_Y();
	void  BorderRecord_X();
	unsigned int GetSizeY(){return Pixels.y;}
	unsigned int GetSizeX(){return Pixels.x;}
	char GetImage(){return nameImage[20];}
	void AsteroidBoom();
};