#include "HealthPoints.h"

HealthPoints::HealthPoints()
{
	position = { 5, 5 };
}

HealthPoints::HealthPoints(Hero& hero)
{
	position = { 5, 5 };
	for (int i = 0; i < hero.getHP(); i++) {
		HealthIndicator* newHeart = new HealthIndicator;
		newHeart->setPosition(position);
		healthPoints.push_back(newHeart);
		position.x += 30;
	}
}

void HealthPoints::updateHeatlhPoints(Hero& hero)
{
	position = { 5, 5 };
	if (hero.getHP() != healthPoints.size()) {
		for (unsigned int i = 0; i < healthPoints.size(); i++) {
			delete healthPoints[i];
			healthPoints.erase(healthPoints.begin() + i);
		}

		for (int i = 0; i < hero.getHP(); i++) {
			HealthIndicator* newHeart = new HealthIndicator;
			newHeart->setPosition(position);
			healthPoints.push_back(newHeart);
			position.x += 30;
		}
	}
}

void HealthPoints::draw(sf::RenderWindow* window) const
{
	for (auto heart : healthPoints) 
	{
		window->draw(*heart);
	}
}


