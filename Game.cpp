#include "Game.hpp"

#include "Player.hpp"

Game::Game() : deltaTime(1 / 60.f)
{
	window = new sf::RenderWindow(sf::VideoMode(1366, 768),"space");
	window->setFramerateLimit(60);
}


void Game::init()
{
	Player* p = new Player;
	p->getSprite().setPosition(300, 200);
	playerTex.loadFromFile("Assets/ship.png");
	p->getSprite().setTexture(playerTex);
	p->getSprite().setOrigin(static_cast<sf::Vector2f>(p->getSprite().getTexture()->getSize()) / 2.f);
	p->getSprite().setScale(0.8, 0.8);
	actorVector.push_back(p);
}


void Game::run()
{
	init();
	sf::Clock clock;
	float frameTimeStart;
	while (window->isOpen())
	{
		frameTimeStart = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		updateCollision();
		update();
		window->clear();

		draw();
		window->display();
		deltaTime = clock.getElapsedTime().asSeconds() - frameTimeStart;
	}
}

void Game::update()
{
	for (auto& k : actorVector)
	{
		k->update();
	}
	score->update();
}

void Game::draw()
{
	for (auto& k : actorVector)
	{
		window->draw(*k);
	}
	window->draw(*score);
}
