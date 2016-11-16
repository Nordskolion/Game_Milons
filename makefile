all: main.o Hero.o
	clear
	g++ main.o Hero.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o 

main.o: ./main.cpp
	g++ -c -std=c++11 ./main.cpp -o main.o


Hero.o: ./Hero.cpp
	g++ -c -std=c++11 ./Hero.cpp -o Hero.o