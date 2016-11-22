#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string.h>
#include "Bullet.h"
#include <vector>
#include "Asteroid.h"
#include "Boom.h"
#include <SFML/Audio.hpp>

using namespace sf;

class Hero
{
private:

SoundBuffer shootBuffer;
Music music;
Sound shoot;

float hero_x = 100.0;
float hero_y = 400.0;
float alpha = 90.0;
int life = 3;
int asteroidScore = 0;
Sprite heroSprite;
Image heroImage;
Texture heroTexture;
std::string nameImage;
Bullet *BULL;
Clock clock;
Clock clockShoot;
float shootCD;
Clock lifecloack;
Clock score;
float timeScore;
float lifetime;
float time;
std::vector<Bullet *> Bullets;
std::vector<Asteroid *> asteroids;
std::vector<Boom *> Booms;



float AlphaRecord(float );
float BorderRecord_X(float );
float BorderRecord_Y(float );
float Search_X(float);
float Search_Y(float);



public:
	Hero(std::string);
	float Hero_x(){return hero_x;}
	float Hero_y(){return hero_y;}
	Sprite RetSprite(){return heroSprite;}
	void Moving_Up();
	void Moving_Down();
	void Set_Pos();
	void ChangeRotation(float);
	void Shoot();
	void AsteroidAdd();
	void DrawShip(sf::RenderTarget& target);
	void ObjectNear();

};