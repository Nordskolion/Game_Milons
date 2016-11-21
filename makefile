all: main.o Hero.o Bullet.o Asteroid.o
	clear
	g++ main.o Hero.o Bullet.o Asteroid.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o 

main.o: ./main.cpp
	g++ -c -std=c++11 ./main.cpp -o main.o

Hero.o: ./Hero.cpp
	g++ -c -std=c++11 ./Hero.cpp -o Hero.o

Bullet.o: ./Bullet.cpp
	g++ -c -std=c++11 ./Bullet.cpp -o Bullet.o

Asteroid.o: ./Asteroid.cpp
	g++ -c -std=c++11 ./Asteroid.cpp -o Asteroid.o