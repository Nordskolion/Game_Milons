// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <math.h>
// #include "Hero.h"
#include <vector>
#include "Game.h"
// #include <Text.hpp>
// #include "Asteroid.h"


using namespace sf;


int main()
{
    std::cout << "HELO WORLD" << std::endl;
    Game game("WUT");
    while (true)
    {
        game.Init();
    }
    
    return 0;
}