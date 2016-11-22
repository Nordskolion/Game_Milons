#include <string.h>
#include <SFML/Graphics.hpp>
using namespace sf;
class Bullet
{
private:
	float bullet_x;
	float bullet_y;
	float delta;
	float dx;
	float dy;
	std::string nameImage = "./Images/Player.png";
	Sprite heroSprite;
	Image heroImage;
	Texture heroTexture;
	float Search_X(float);
	float Search_Y(float);
public:
	Bullet(float x, float y, float alpha);
	void BulletDraw(sf::RenderTarget& target);
	float Get_x() {return bullet_x;}
	float Get_y() {return bullet_y;}

};

