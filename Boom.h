//Boom

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace sf;

class Boom
{
private:
	float x;
	float y;
	Image boomImage;
	Texture boomTexture;
    Sprite boomSprite;
    Clock clock;
    float time;
    float CurrentFrame_X = 0;
    float CurrentFrame_Y = 0;
    bool End = true;




public:
	Boom(float x1,float y1);
	bool Get_Status(){return End;}
	bool BoomDraw(sf::RenderTarget* target);

};