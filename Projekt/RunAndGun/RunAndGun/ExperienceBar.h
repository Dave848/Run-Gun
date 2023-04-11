#ifndef EXPERIENCEBAR_H
#define EXPERIENCEBAR_H

#include "Hero.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class ExperienceBar: public sf::Drawable
{
private:
	sf::RectangleShape emptyBar;
	sf::RectangleShape filledBar;
	sf::Text expAmount;
	sf::Font font;

public:
	ExperienceBar();
	void updateBar(Hero&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	

};

#endif

