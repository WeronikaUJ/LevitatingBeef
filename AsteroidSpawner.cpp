#include "AsteroidSpawner.hpp"
#include <random>
#include "Game.hpp"
#include "Asteroid.hpp"
AsteroidSpawner::AsteroidSpawner(float delay, float max)
	:minDelay(delay), maxDelay(max), curTime(0), delay(0)
{
	asteroidTexture.loadFromFile("Assets/asteroid.png");
}

void AsteroidSpawner::update()
{
	curTime += Game::Instance().getDeltaTime();

	if (curTime > delay)
	{
		curTime = 0.f;
		std::random_device mch;
		std::default_random_engine generator(mch());
		std::uniform_int_distribution<int> rollDelay(minDelay, maxDelay);
		delay = rollDelay(generator);
		std::uniform_int_distribution<int> rollPosition(20, Game::Instance().getWindowSize().x);
		int posX = rollPosition(generator);
		std::uniform_int_distribution<int> rollSpeed(20, 150);
		int speed = rollSpeed(generator);
		std::uniform_int_distribution<int> rollRotation(0, 6);
		int rotation = rollRotation(generator);

		std::uniform_int_distribution<int> rollScale(30,60);
		int scale = rollScale(generator);



		Asteroid* asteroid;
		asteroid = new Asteroid(rotation, { 0,-1 }, speed);
		
		asteroid->getSprite().setTexture(asteroidTexture);
		asteroid->getSprite().setPosition(posX,Game::Instance().getWindowSize().y);
		asteroid->getSprite().setOrigin(static_cast<sf::Vector2f>(asteroid->getSprite().getTexture()->getSize()) / 2.f);
		asteroid->getSprite().setScale(scale/100.f, scale / 100.f);

		Game::Instance().addObject(asteroid);
	}
}
