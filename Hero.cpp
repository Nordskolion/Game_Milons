#include "Class_hero.h"
using namespace sf;
Hero::Hero(string name)
{
	nameImage = name;
	heroImage.loadFromFile(nameImage);
	heroTexture.loadFromImage(heroimage);
	heroSprite.setTexture(herotexture);
	heroSprite.setPosition(hero_x, hero_y);
	heroSprite.setRotation(alpha);

}
void Hero::Set_Pos()
{
	heroSprite.setPosition(hero_x, hero_y);
	heroSprite.setRotation(alpha);
}
void Hero::ChangeRotation(float delta)
{
	alpha = AlphaRecord(alpha + delta);
	// heroSprite.setRotation(alpha);
}
void Hero::Moving_Up()
{
	    hero_y=hero_y+Search_Y(alpha);
        hero_x=hero_x+Search_X(alpha);
}

void Hero::Moving_Down()
{
	    hero_y=hero_y-Search_Y(alpha);
        hero_x=hero_x-Search_X(alpha);
}
























float Hero::AlphaRecord(float alpha)
{
	if(alpha < 0){alpha=358;}
    if(alpha > 360){alpha=0;}
        return alpha;
}

float Hero::BorderRecordX(float hero_x)
{
    if(hero_x >= 799){hero_x=5;}
    if(hero_x <= 0){hero_x=770;}
    // std::cout<<hero_x<<"-X"<<std::endl;
    return hero_x;
}
    
float Hero::BorderRecordY(float hero_x)
{
    std::cout<<hero_x<<"-YBegin"<<std::endl;
    if(hero_x >= 599){hero_x=5;}
    if(hero_x <= 0){hero_x=570;}
    std::cout<<hero_x<<"-Y"<<std::endl;
    return hero_x;
}
float Hero::Search_X(float  alpha)
{
    float x=1;
    x = x*cos(alpha*3.14/180);
    std::cout<<"X-"<<x<<std::endl;
    return x;
}

float Hero::Search_Y(float  alpha)
{
    float y=1;
    y = y*sin(alpha*3.14/180);
    return y;
}