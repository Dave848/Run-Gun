#ifndef HEALTHINDICATOR_H
#define HEALTHINDICATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class HealthIndicator: public sf::Drawable
{
private:
	sf::Sprite heart;
	sf::Texture fullHeart;

public:
	HealthIndicator();
	void setPosition(sf::Vector2f);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif

