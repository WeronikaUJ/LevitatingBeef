#include "Score.hpp"

#include "Game.hpp"
Score::Score() : score(0)
{
	font.loadFromFile("Assets/1.ttf");
	text.setFont(font);
}

void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text, states);
}

void Score::update()
{
	score += Game::Instance().getDeltaTime();
	text.setString(std::to_string(int(score)));
}

sf::Text& Score::getText()
{
	return text;
}
