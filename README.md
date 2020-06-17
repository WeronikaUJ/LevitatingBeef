Gra Levitating Beef - projekt zaliczeniowy C++

W skrócie:
Mieszkaniec planety Q145KIP8 odwiedził naszą Galaktykę. Jego podróż aż tutaj spowodowana jest chęcią konsumpcji wołowiny (którą gatunek ludzki uwielbia). W momencie wciągania krowy do swego statku promieniem, właz otwierający się zaciął i nie ma możliwości jego naprawy - zatem krowa lewituje w przestrzeni kosmicznej. Naszym zadaniem jest, aby Mućka, żyła jak najdłużej i nie uderzyła w żadną asteroidę.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
I) Elementy:

1) Projekt obiektowy:

=======================================

- klasy: Actor, Asteroid, AsteroidSpawner, Game, Player, Score

=======================================

- konstruktory w każdej klasie:

Actor::Actor();
Asteroid::Asteroid(const float, const sf::Vector2f&, const float);
AsteroidSpawner::AsteroidSpawner();float,float)
Player::Player(float,float);
Score::Score();
Game::Game();

=======================================

- konstruktor kopiujący: Actor.hpp: 
Actor::Actor(const Actor&);

=======================================

- dziedziczenie i polimorfizm :
sf::Drawable -> Actor -> Asteroid
sf::Drawable -> Actor -> AsteroidSpawner
sf::Drawable -> Actor -> Player
sf::Drawable -> Actor -> Score

=======================================

-klasa abstrakcyjna -> jest klasą abstrakcyjną, jeśli ma min. 1 czysto wirtualną metodę: Actor.hpp

virtual void Actor::update() = 0;

-czysto wirtualne metody -> nie mają ciała funkcji zamiast tego oznaczamy je '=0'.

=======================================

2) STL:


- iteratory: Game.cpp:
void Game::updateCollision()

=======================================

- algorytmy: Game.cpp - remove_if
void Game::clear()

=======================================

3) C++

- zakresowa pętla for: Game.cpp:
void Game::update()
void Game::draw()

=======================================

- wyjątki: Game.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
II) Sterowanie:
↑ - przytrzymywanie strzałki skierowanej w górę pozwala na lot w górę ekranu
↓ - strzałka w dół, powoduje obniżanie się statku kosmicznego
→ - strzałka w prawo, lecimy w prawo
← - strzałka w lewo, lecimy w lewo

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
III) Odpalanie
Pobieramy repozytorium na linuksa i uruchamiamy grę za pomocą komendy make play. 
Na repozytorium znajduje się także archiwum .zip, w którym jest zbudowana aplikacja do testowania.
