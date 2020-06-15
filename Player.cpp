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

	if (sprite.getPosition().y < 0)
		Game::Instance().endGame();
	if (sprite.getPosition().y > Game::Instance().getWindowSize().y)
		Game::Instance().endGame();
	if (sprite.getPosition().x < 0)
		Game::Instance().endGame();
	if (sprite.getPosition().x > Game::Instance().getWindowSize().x)
		Game::Instance().endGame();


}

void Player::onCollision(Actor* collider)
{
	if (collider->getTag() == "asteroid")
	{
		Delete();
		Game::Instance().endGame();
	}
}

