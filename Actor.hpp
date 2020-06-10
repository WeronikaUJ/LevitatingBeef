#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Actor : public sf::Drawable
{
public:
	Actor();
	Actor(const Actor&) = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(sprite, states);
	}
	virtual sf::Sprite& getSprite() {
		return sprite;
	}
	virtual void Delete()  {
		erase = true;
	}

	virtual void update() = 0;

	virtual bool shouldBeErase() const {
		return erase;
	}

	virtual void onCollision(Actor* collider) {};

	virtual void setTag(const std::string& t) {
		tag = t;
	}
	virtual const std::string& getTag() const {
		return tag;
	}
protected:
	std::string tag;
	bool erase;
	sf::Sprite sprite;
};

