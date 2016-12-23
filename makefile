all: main.o Hero.o Bullet.o Asteroid.o Boom.o Game.o
	clear
	g++ main.o Hero.o Bullet.o Game.o Asteroid.o Boom.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	rm *.o

main.o: ./main.cpp
	g++ -c -std=c++11 ./main.cpp -o main.o

Hero.o: ./Hero.cpp
	g++ -c -std=c++11 ./Hero.cpp -o Hero.o 

Bullet.o: ./Bullet.cpp
	g++ -c -std=c++11 ./Bullet.cpp -o Bullet.o

Asteroid.o: ./Asteroid.cpp
	g++ -c -std=c++11 ./Asteroid.cpp -o Asteroid.o

Boom.o: ./Boom.cpp
	g++ -c -std=c++11 ./Boom.cpp -o Boom.o

Game.o: ./Game.cpp
	g++ -c -std=c++11 ./Game.cpp -o Game.o
	

clean: *.o
	rm *.o

