#include "Game.h"
using namespace sf;
Game::Game(std::string name)
{
	startedstring = name;
	std::cout << "HELO WORLD" << std::endl;
	window = new RenderWindow(VideoMode(800, 600), "SFML works!");
	hero = new Hero("./Images/Ship.png", 700 , 500);
	enemy = new Hero("./Images/Small.png", 100, 100);
	Cooldown = 600000;
	bool gameEnd = false;
	// Font font;
	font.loadFromFile("./Images/media/font/trs-million.ttf");
	// life("", font, 20);
	life.setFont(font);
	game_Over.setFont(font);
	// game_Over("", font, 20);
	// text.setColor();
	game_Over.setStyle(sf::Text::Bold);
	game_Over.setPosition(150, 100);
	game_Over.setCharacterSize(60);
	game_Over.setStyle(Text::Bold);
	game_Over.setString("PRESS SPACE OR CTR FOR START");
	life.setCharacterSize(20);
	life.setPosition(0, 0);
	life.setString("Life:" + std::to_string(hero->Lifes()));
	elife.setFont(font);
	elife.setCharacterSize(20);
	elife.setPosition(700, 0);
	elife.setString("Life" + std::to_string(enemy->Lifes()));

	// std::cout << "HELO WORLD" << std::endl;
	music.openFromFile("./Images/media/musics/theme.ogg");
	shootBuffer.loadFromFile("./Images/media/sounds/laser1.ogg");
	shoot.setBuffer(shootBuffer);
	// Init();
}
void Game::Init()
{
	music.play();
	while (window->isOpen())
	{


		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			enemy->ChangeRotation(-3);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			enemy->ChangeRotation(3);

		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			//hero_y=BorderRecordY(hero_x=Search_X(hero_x,alpha));
			enemy->Moving_Up();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			enemy->Moving_Down();
		}
		if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			//SOSAT EPTI!
			if (enemy->GameEnd())
			{
				game_Restart = true;
			}
			EShoot();
			// std::cout << "PEW PEW " << std::endl;

		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			hero->ChangeRotation(-3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			hero->ChangeRotation(3);

		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			//hero_y=BorderRecordY(hero_x=Search_X(hero_x,alpha));
			hero->Moving_Up();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			hero->Moving_Down();
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			//SOSAT EPTI!
			if (hero->GameEnd())
			{
				game_Restart = true;
			}
			Shoot();
			// std::cout << "PEW PEW " << std::endl;

		}

		time = clock.getElapsedTime().asMicroseconds();
		// std::cout<<time<<" -- TIME"<<"   Cooldown -- "<<Cooldown<<std::endl;
		if ( time > Cooldown)
		{
			AsteroidAdd();
			if (Cooldown > 1000)
			{
					Cooldown = Cooldown - 1000;   /* code */
			}

			clock.restart();
		}

		if (!hero->GameEnd())
		{
			hero->Moving_Up();
			enemy->Moving_Up();
			ObjectNear();
			hero->Set_Pos();
			enemy->Set_Pos();
		}
		window->clear();

		if (hero->GameEnd() || enemy->GameEnd())
		{
			if (hero->GameEnd())
			{
				game_Over.setString(("GAME OVER\n! SAUCER WIN !\nPRESS SPACE\n TO RESTART"));
				/* code */
			}
			if (enemy->GameEnd())
			{
				game_Over.setString(("GAME OVER\n! PlAYER WIN !\nPRESS SPACE\n TO RESTART"));
				/* code */
			}
			window->draw(game_Over);
			Game_Restart();
		}
		if (!hero->GameEnd() && !enemy->GameEnd())
		{
			game_Over.setString(("GAME OVER\nYOUR SCORE:" + std::to_string(asteroidScore) + "\nPRESS SPACE\n TO RESTART"));
			elife.setString("Life:" + std::to_string(enemy->Lifes()));
			life.setString("Life:" + std::to_string(hero->Lifes()));
			Game_draw();
			window->draw(life);
			window->draw(elife);
		}
		//UBRAT ASTEROIDI V OTDELNII KLASS !!! VAZNOOOO
		window->display();
	}
}
bool Game::Complete_check()
{
	if (asteroidScore >= Next_lvl)
	{
		return true;
	}
	return false;
}

void Game::Game_draw()
{
	hero->Draw(window);
	enemy->Draw(window);

	for (int i = 0; i < EBullets.size(); ++i)
	{
		// std::cout<<"TUTA"<<std::endl;
		EBullets[i]->BulletDraw(window);  /* code */
		// std::cout<<"PEWPEW--"<<i<<std::endl;
		// std::cout<<"SIZE --"<<Bullets.size()<<std::endl;
	}

	for (int i = 0; i < Bullets.size(); ++i)
	{
		// std::cout<<"TUTA"<<std::endl;
		Bullets[i]->BulletDraw(window);  /* code */
		// std::cout<<"PEWPEW--"<<i<<std::endl;
		// std::cout<<"SIZE --"<<Bullets.size()<<std::endl;
	}

	for (int i = 0; i < asteroids.size(); ++i)
	{
		asteroids[i]->DrawAst(window);
	}
	for (int i = 0; i < Booms.size(); ++i)
	{
		// std::cout << " Booms cicle : " << Booms[i]->Get_Status() << std::endl;
		if (Booms[i]->Get_Status())
		{
			Booms[i]->BoomDraw(window);
		} else
		{
			Booms.erase (Booms.begin() + i);
			Booms.shrink_to_fit();

		}
	}

	hero->Draw(window);
}


void Game::AsteroidAdd()
{

	// std::cout << "TIME" << time << std::endl;
	asteroidCD = asteroidsClock.getElapsedTime().asMicroseconds();
	clock.restart();
	if (asteroidCD > 40000)
	{

		asteroids.push_back(new Asteroid(10, 0));
	}
}

void Game::Shoot()
{

	// std::cout<<"TIME"<<time<<std::endl;
	eshootCD = eshootClock.getElapsedTime().asMicroseconds();
	if (eshootCD > 500000)
	{
		eshootClock.restart();
		shoot.play();
		Bullets.push_back(new Bullet(hero->Hero_x(), hero->Hero_y(), hero->Hero_A(), "./Images/Player.png"));
	}
}


void Game::EShoot()
{

	// std::cout<<"TIME"<<time<<std::endl;
	shootCD = shootClock.getElapsedTime().asMicroseconds();
	if (shootCD > 500000)
	{
		shootClock.restart();
		shoot.play();
		EBullets.push_back(new Bullet(enemy->Hero_x(), enemy->Hero_y(), enemy->Hero_A(), "./Images/Saucer.png"));
	}
}









void Game::ObjectNear()
{
	bool ifCollision = false;
	lifeCD = lifeCloack.getElapsedTime().asMicroseconds();
	elifeCD = elifeClock.getElapsedTime().asMicroseconds();

	for (int j = 0; j < EBullets.size(); ++j)
	{
		if (abs(hero->Hero_x() - EBullets[j]->Get_x()) < float(hero->GetSizeX()) / 4) {
			if (abs(hero->Hero_y() - EBullets[j]->Get_y()) < float(hero->GetSizeY()) / 4 ) {
				if (lifeCD > 1000000) {
					lifeCloack.restart();
					hero->life = hero->life - 1;
					EBullets.erase (EBullets.begin() + j);
					EBullets.shrink_to_fit();    /* code */
				}
			}
		}

		/* code */
	}

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

		if (abs(hero->Hero_x() - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2) {
			if (abs(hero->Hero_y() - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 ) {
				if (lifeCD > 1000000)
				{
					lifeCloack.restart();
					hero->life = hero->life - 1;    /* code */
					// text.setString("Life:" + std::to_string(life));

				}
			}
		}
		if (abs(enemy->Hero_x() - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2) {
			if (abs(enemy->Hero_y() - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 ) {
				if (elifeCD > 1000000)
				{
					elifeClock.restart();
					enemy->life = enemy->life - 1;    /* code */
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
			if (abs(enemy->Hero_x() - Bullets[i]->Get_x()) < float(enemy->GetSizeX()) / 4) {
				if (abs(enemy->Hero_y() - Bullets[i]->Get_y()) < float(enemy->GetSizeY()) / 4 ) {
					if (elifeCD > 1000000)
					{
						elifeClock.restart();
						enemy->life = enemy->life - 1;
						Bullets.erase (Bullets.begin() + i);
						Bullets.shrink_to_fit();    /* code */
						// text.setString("Life:" + std::to_string(life));

					}
				}
			}
		}

		for (int i = 0; i < EBullets.size(); ++i)
		{
			// std::cout<<"GETSIZEX"<< asteroids[j]->GetSizeX()<<std::endl;
			if (abs(EBullets[i]->Get_x() - asteroids[j]->Get_x()) < float(asteroids[j]->GetSizeX()) / 2 ) {
				// std::cout<<"POPCHTI"<<std::endl;
				if (abs(EBullets[i]->Get_y() - asteroids[j]->Get_y()) < float(asteroids[j]->GetSizeY()) / 2 ) {
					// delete asteroids[j];
					if (asteroids[j]->GetImage() == 'B')
					{
						asteroids.push_back(new Asteroid(2, 4));
					}

					// Booms.push_back(new Boom(asteroids[j]->Get_x(), asteroids[j]->Get_y()));
					asteroids.erase (asteroids.begin() + j);
					asteroidScore ++;
					asteroids.shrink_to_fit();
					EBullets.erase (EBullets.begin() + i);
					EBullets.shrink_to_fit();
					ifCollision = true;
					break;
				}
			}
			/* code */
		}
		if (ifCollision) break;
	}
}

void Game::Game_Restart()
{
	if (game_Restart)
	{
		asteroidScore = 0;
		game_Restart = false;
		hero = new Hero("./Images/Ship.png", 700, 500);
		enemy = new Hero("./Images/Small.png", 100, 100);
		asteroids.clear();
		Bullets.clear();
		EBullets.clear();
	}

}