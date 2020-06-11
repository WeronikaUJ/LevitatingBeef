#pragma once
#include "Actor.hpp"
class Asteroid : public Actor
{
public:
	Asteroid(const float rot = 3.f, const sf::Vector2f& dir = { 0,-1 }, const float speed = 60.f);

	virtual void update();
protected:
	float speed;
	sf::Vector2f direction;
	float rotateSpeed;
};

