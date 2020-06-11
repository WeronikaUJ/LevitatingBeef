#include "Asteroid.hpp"
#include "Game.hpp"
Asteroid::Asteroid(const float rot, const sf::Vector2f& dir,const float s)
	:rotateSpeed(rot),direction(dir),speed(s)
{
	tag = "asteroid";
}

void Asteroid::update()
{
	float delta = Game::Instance().getDeltaTime();
	sprite.move(speed * delta * direction.x, speed * delta * direction.y);
	sprite.rotate(rotateSpeed);
	if (sprite.getPosition().y < 0)
		Delete();
}
