#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.hpp"
class Game
{
public:
	static Game& Instance() {
		static Game instance;
		return instance;
	}

	void run();

	void update();
	
	void draw();

	virtual float getDeltaTime() const {
		return deltaTime;
	};

	const sf::Vector2u getWindowSize() const {
		return window->getSize();
	}

private:
	Game();
    
	void init();

	std::vector<Actor*> actorVector;
	float deltaTime;
	sf::RenderWindow *window;
	sf::Texture playerTex;
};

