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

	void clear();

	virtual float getDeltaTime() const {
		return deltaTime;
	};

	void addObject(Actor* actor) {
		queue.push_back(actor);
	}

	const sf::Vector2u getWindowSize() const {
		return window->getSize();
	}

	void updateCollision();


private:
	Game();
    
	void init();

	std::vector<Actor*> actorVector;
	std::vector<Actor*> queue;
	float deltaTime;
	sf::RenderWindow *window;
	Score* score;

	sf::Texture playerTex;
};

