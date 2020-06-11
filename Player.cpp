#include "Player.hpp"
#include "Game.hpp"
Player::Player(float p, float sp)
	:power(p),speed(sp), curSpeed(0.f)
{

}
void Player::update()
{
	float deltaTime = Game::Instance().getDeltaTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(curSpeed > - speed)
		curSpeed -= power * deltaTime;
	}
	else {
		if (curSpeed < speed)
		curSpeed += power  * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite.move(-speed * deltaTime, 0.f);
		sprite.setRotation(-45);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite.move(speed * deltaTime, 0.f);
		sprite.setRotation(45);
	}
	else sprite.setRotation(0);
	sprite.move(0,curSpeed * deltaTime);

}

