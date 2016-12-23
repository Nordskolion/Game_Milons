//
#include "Hero.h"
using namespace sf;

class Game
{
private:
	Font font;
	Text life;
	Text game_Over;
	Text elife;


	Clock clock;
	Clock asteroidsClock;
	Clock shootClock;
	Clock eshootClock;
	Clock elifeClock;
	Clock lifeCloack;

	Hero *hero;
	Hero *enemy;
	RenderWindow *window;

	SoundBuffer shootBuffer;
	Music music;
	Sound shoot;
	int Next_lvl = 20;

	float lifeCD;
	float elifeCD;
	float time;
	float asteroidCD;
	float shootCD;
	float eshootCD;
	float Cooldown;
	int asteroidScore = 0;


	bool game_Restart = false;
	bool gameEnd = false;

	std::string startedstring;
	std::vector<Bullet *> Bullets;
	std::vector<Asteroid *> asteroids;
	std::vector<Bullet *> EBullets;
	std::vector<Boom *> Booms;



public:
	Game(std::string name);
	void Game_draw();
	void Init();
	bool Complete_check();
	void AsteroidAdd();
	void ObjectNear();
	void Shoot();
	void Game_Restart();
	void EShoot();
};