#include "Actor.hpp"

Actor::Actor() : erase(false)
{
}

Actor::Actor(const Actor& source)
	:tag(source.tag), erase(source.erase), sprite(source.sprite)
{
}

