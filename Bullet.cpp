#include "Bullet.h"
using namespace sf;
Bullet::Bullet(float x, float y, float alpha)
{
	bullet_x = x;
	bullet_y = y;
	delta = alpha;
	heroImage.loadFromFile(nameImage);
	heroTexture.loadFromImage(heroImage);
	heroSprite.setTexture(heroTexture);
	heroSprite.setPosition(bullet_x, bullet_y);
	heroSprite.setRotation(delta);
	dx = 3 * cos(delta * 3.14 / 180);
	dy = 3 * sin(delta * 3.14 / 180);
}


void Bullet::BulletDraw(sf::RenderTarget& target)
{
	bullet_x = bullet_x + dx;
	bullet_y = bullet_y + dy;
	heroSprite.setPosition(bullet_x, bullet_y);
	target.draw(heroSprite);
}
