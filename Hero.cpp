#include "Hero.h"
using namespace sf;
Hero::Hero(std::string name)
{
    nameImage = name;
    heroImage.loadFromFile(nameImage);
    heroTexture.loadFromImage(heroImage);
    heroSprite.setTexture(heroTexture);
    heroSprite.setPosition(hero_x, hero_y);
    heroSprite.setRotation(alpha);
    heroSprite.setOrigin(Vector2f(26, 14));
    music.openFromFile("./Images/media/musics/theme.ogg");
    music.play();
    shootBuffer.loadFromFile("./Images/media/sounds/laser1.ogg");
    shoot.setBuffer(shootBuffer);
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

    // std::cout << " X " << hero_x << " Y " << hero_y << std::endl;
    hero_y = hero_y + Search_Y(alpha);
    hero_x = hero_x + Search_X(alpha);
    // std::cout << "Search_Y" << Search_Y(alpha) << std::endl;
    // std::cout << "Alpha" << alpha << std::endl;
}

void Hero::Moving_Down()
{
    hero_y = hero_y - Search_Y(alpha);
    hero_x = hero_x - Search_X(alpha);
}



void Hero::Shoot()
{

    // std::cout<<"TIME"<<time<<std::endl;
    shootCD = clockShoot.getElapsedTime().asMicroseconds();
    if (shootCD > 500000)
    {
        clockShoot.restart();
        shoot.play();
        Bullets.push_back(new Bullet(hero_x, hero_y, alpha));
    }
}
void Hero::DrawShip(sf::RenderTarget* target)
{



    for (int i = 0; i < Bullets.size(); ++i)
    {
        Bullets[i]->BulletDraw(target);  /* code */
        // std::cout<<"PEWPEW--"<<i<<std::endl;
        // std::cout<<"SIZE --"<<Bullets.size()<<std::endl;
    }

    for (int i = 0; i < asteroids.size(); ++i)
    {
        asteroids[i]->DrawAst(target);
    }
    for (int i = 0; i < Booms.size(); ++i)
    {
        // std::cout << " Booms cicle : " << Booms[i]->Get_Status() << std::endl;
        if (Booms[i]->Get_Status())
        {
            Booms[i]->BoomDraw(target);
        } else
        {
            Booms.erase (Booms.begin() + i);
            Booms.shrink_to_fit();

        }
    }
    
    if (life > 0)
    {
        target->draw(heroSprite);  /* code */
        // target.draw(text);
    }
}

void Hero::AsteroidAdd()
{

    // std::cout << "TIME" << time << std::endl;
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    if (time > 40000)
    {

        asteroids.push_back(new Asteroid(10, 0));
    }
}

void Hero::ObjectNear()
{
    bool ifCollision = false;
    lifetime = lifecloack.getElapsedTime().asMicroseconds();


    for (int j = 0; j < asteroids.size(); ++j)
    {

        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (abs(asteroids[i]->Get_x() - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2 + asteroids[i]->GetSizeX() / 2) {
                if (abs(asteroids[i]->Get_y() - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 + asteroids[i]->GetSizeY() / 2) {
                    asteroids[i]->AsteroidBoom();
                    asteroids[j]->AsteroidBoom();

                }

            }
            /* code */
        }




        if (abs(hero_x - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2) {
            if (abs(hero_y - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 ) {
                if (lifetime > 1000000)
                {
                    lifecloack.restart();
                    life = life - 1;    /* code */
                    // text.setString("Life:" + std::to_string(life));

                }


            }
        }


        for (int i = 0; i < Bullets.size(); ++i)
        {
            // std::cout<<"GETSIZEX"<< asteroids[j]->GetSizeX()<<std::endl;
            if (abs(Bullets[i]->Get_x() - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2 ) {
                // std::cout<<"POPCHTI"<<std::endl;
                if (abs(Bullets[i]->Get_y() - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 ) {
                    // delete asteroids[j];
                    if (asteroids[j]->GetImage() == 'B')
                    {
                        asteroids.push_back(new Asteroid(2, 4));
                    }

                    // Booms.push_back(new Boom(asteroids[j]->Get_x(), asteroids[j]->Get_y()));
                    asteroids.erase (asteroids.begin() + j);
                    asteroidScore ++;
                    asteroids.shrink_to_fit();
                    Bullets.erase (Bullets.begin() + i);
                    Bullets.shrink_to_fit();
                    ifCollision = true;
                    break;
                }
            }
            /* code */
        }
        if (ifCollision) break;
    }
}

bool Hero::GameEnd()
{
    if (life == 0)
    {
        return true;
    }
    return false;
}














float Hero::AlphaRecord(float alpha)
{
    if (alpha < 0) {alpha = 358;}
    if (alpha > 360) {alpha = 0;}
    return alpha;
}

float Hero::BorderRecord_X(float hero_x)
{
    if (hero_x >= 799) {hero_x = 5;}
    if (hero_x <= 0) {hero_x = 770;}
    // std::cout<<hero_x<<"-X"<<std::endl;
    return hero_x;
}

float Hero::BorderRecord_Y(float hero_x)
{
    std::cout << hero_x << "-YBegin" << std::endl;
    if (hero_x >= 599) {hero_x = 5;}
    if (hero_x <= 0) {hero_x = 570;}
    std::cout << hero_x << "-Y" << std::endl;
    return hero_x;
}
float Hero::Search_X(float  alpha)
{
    float x = 2;
    x = x * cos(alpha * 3.14 / 180);
    // std::cout<<"X-"<<x<<std::endl;
    return x;
}

float Hero::Search_Y(float  alpha)
{
    float y = 2;
    y = y * sin(alpha * 3.14 / 180);
    return y;
}


// bool Hero::TouchedAsteroids(int x,int y, asteroids*)