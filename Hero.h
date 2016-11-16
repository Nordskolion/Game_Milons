#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace sf;


Class Hero
{
private:
float hero_x = 500.0;
float hero_y = 400.0;
float alpha = 90.0;
Image heroImage;
Texture heroTexture;
Sprite heroSprite;
string nameImage;

float AlphaRecord(float );
float BorderRecord_X(float );
float BorderRecord_Y(float );
float Search_X(float);
float Search_Y(float);


public:
	Hero(string);
	float Hero_x(){return hero_x;}
	float Hero_y(){return hero_y;}
	Sprite RetSprite(){return heroSprite;}
	void Moving_Up();
	void Moving_Down();
	void Set_Pos();
	void ChangeRotation(float);


}