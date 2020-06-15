#pragma once
#include "Actor.hpp"
class AsteroidSpawner : public Actor
{
public:
	AsteroidSpawner(float delay = 1.f,float max = 4.f);

	virtual void update();
protected:
	float minDelay;
	float maxDelay;
	float curTime;
	float delay;
	sf::Texture asteroidTexture;
};

