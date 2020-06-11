#pragma once
#include "Actor.hpp"
class Player : public Actor
{
public:
	Player(float p = 50.f,float sp = 100.f);
	virtual void update();

protected:
	float speed;
	float power;
	float curSpeed;
};

