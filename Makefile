#ELEMENTY KOMPILACJI
CC = g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

#INSTRUKCJE
all:
	$(CC) -c "Actor.cpp" -o Actor.o
	$(CC) -c "Asteroid.cpp" -o Asteroid.o
	$(CC) -c "AsteroidSpawner.cpp" -o AsteroidSpawner.o
	$(CC) -c "Game.cpp" -o Game.o
	$(CC) -c "Player.cpp" -o Player.o
	$(CC) -c "Score.cpp" -o Score.o
	$(CC) -c "main.cpp" -o main.o
	$(CC) -o MojaGraWeronika Actor.o Asteroid.o 

AsteroidSpawner.o Game.o Player.o Score.o main.o 
	$(LIBS)
  
