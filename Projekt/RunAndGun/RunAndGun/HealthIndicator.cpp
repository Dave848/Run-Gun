#include "HealthIndicator.h"

HealthIndicator::HealthIndicator()
{
	fullHeart.loadFromFile("heart.png");
	heart.setTexture(fullHeart);
	heart.setScale(0.05f,0.05f);
}

void HealthIndicator::setPosition(sf::Vector2f pos)
{
	heart.setPosition(pos);
}

void HealthIndicator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(heart, states);
}
