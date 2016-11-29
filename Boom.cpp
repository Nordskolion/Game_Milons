#include "Boom.h"

using namespace sf;
Boom::Boom(float x1, float y1)
{
	x = x1;
	y = y1;
	std::string name = "./Images/VFX.png";
	boomImage.loadFromFile(name);
	boomImage.createMaskFromColor(Color(0, 72, 109));
	// Image boomImage.loadFromFile("./Images/explode.png");
	boomTexture.loadFromImage(boomImage);
	boomSprite.setTexture(boomTexture);
	boomSprite.setTextureRect(IntRect(0, 0, 96, 87));
	boomSprite.setOrigin(Vector2f(boomImage.getSize().x/2,boomImage.getSize().y/2));
	boomSprite.setPosition(x , y);
}
bool Boom::BoomDraw(sf::RenderTarget* target)
{
	time = clock.getElapsedTime().asMicroseconds();
	time = time / 800;
	clock.restart();
	CurrentFrame_X += 0.005 * time;
	if (CurrentFrame_X > 8)
	{
		CurrentFrame_Y = CurrentFrame_Y + 1;
		CurrentFrame_X = 0;
	}
	// std::cout << "CurrentFrame_Y" << CurrentFrame_Y << "     End" << End << std::endl;
	boomSprite.setTextureRect(IntRect(256 * int(CurrentFrame_X),  256	* int(CurrentFrame_Y), 256, 256));
	if (CurrentFrame_X >= 8 || CurrentFrame_Y >= 4) {End = false;}
	target->draw(boomSprite);
	return End;
}





//(8)256*256(4);;;;