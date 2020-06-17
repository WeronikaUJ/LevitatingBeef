#include "Game.hpp"

#include "Player.hpp"
#include "AsteroidSpawner.hpp"
#include "Score.hpp"

#include <iostream>

Game::Game() : deltaTime(1 / 60.f)
{
	window = new sf::RenderWindow(sf::VideoMode(1366, 768),"LevitatingBeef");
	window->setFramerateLimit(60);
	score = new Score();

	score->getText().setCharacterSize(20);
	score->getText().setPosition(20.f, 20.f);
}



void Game::updateCollision()
{
	for (auto it1 = actorVector.begin(); it1 != actorVector.end(); ++it1)
	{
		for (auto it2 = it1; it2 != actorVector.end(); ++it2)
		{
			if (it1 == it2)
				continue;
			auto c1 = (*it1)->getSprite().getGlobalBounds();
			auto c2 = (*it2)->getSprite().getGlobalBounds();
			if (c1.intersects(c2))
			{
				(*it1)->onCollision(*it2);
				(*it2)->onCollision(*it1);
			}
		}
	}
}


void Game::init()
{
	Player* p = new Player();
	p->getSprite().setPosition(300, 200);
	playerTex.loadFromFile("Assets/ship.png");
	p->getSprite().setTexture(playerTex);
	p->getSprite().setOrigin(static_cast<sf::Vector2f>(p->getSprite().getTexture()->getSize()) / 2.f);
	p->getSprite().setScale(0.8, 0.8);
	actorVector.push_back(p);

	AsteroidSpawner* spawner = new AsteroidSpawner(1, 3);
	actorVector.push_back(spawner);
}


void Game::clear()
{
	if (!actorVector.empty())
	{
		auto iterator = std::remove_if(actorVector.begin(), actorVector.end(), [](Actor* actor)->bool {
			return actor->shouldBeErase();
			});
		if (iterator != actorVector.end())
		{
			auto cpIterator = iterator;
			++cpIterator;
			for (; cpIterator != actorVector.end(); ++cpIterator)
			{
				delete (*cpIterator);
			}
			actorVector.erase(iterator, actorVector.end());
		}
	}
}

void Game::freezeScreen()
{
	sf::Text text;
	sf::Font font;
	font.loadFromFile("Assets/1.ttf");
	text.setFont(font);
	text.setString("Przezyles " + std::to_string(score->getScore()) + " sekund");
	text.setCharacterSize(30);
	text.setPosition(static_cast<sf::Vector2f>(window->getSize()) / 2.f);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyReleased)
			{
				actorVector.clear();
				init();
				freeze = false;
				score->reset();
				return;
			}
		}
		window->clear();

		window->draw(text);

		window->display();
	}
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
		if (!queue.empty())
		{
			for (auto k : queue) {
				actorVector.push_back(k);
			}
			queue.clear();
		}
		updateCollision();
		update();
		clear();
		window->clear();
		draw();
		window->display();
		deltaTime = clock.getElapsedTime().asSeconds() - frameTimeStart;

		if (freeze)
			freezeScreen();
	}
}
void Game::update()
{
		try {
		for (auto& k : actorVector)
		{
			k->update();
		}
		score->update();
	}
	catch (...)
	{
		freezeScreen();
	}
}


void Game::draw()
{
	for (auto& k : actorVector)
	{
		window->draw(*k);
	}
	window->draw(*score);
}
