#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include "HealthIndicator.h"
#include "Hero.h"
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class HealthPoints
{
private:
	std::vector<HealthIndicator*> healthPoints;
	sf::Vector2f position;

public:
	HealthPoints();
	HealthPoints(Hero&);
	void updateHeatlhPoints(Hero&);
	void draw(sf::RenderWindow*) const;


};

#endif;

