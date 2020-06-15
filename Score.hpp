#pragma once
#include "Actor.hpp"
class Score : public Actor
{
public:
	Score();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void update();

	virtual void reset() {
		score = 0.f;
	}

	virtual float getScore() const {
		return score;
	}

	virtual sf::Text& getText();
protected:
	sf::Text text;
	float score;
	sf::Font font;
};

