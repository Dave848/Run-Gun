#ifndef TIMER_H
#define TIMER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Timer :public sf::Drawable
{
private:
	sf::Text timer;
	sf::Clock clock;
	sf::Font font;
	int minutes;
	int seconds;
public:
	Timer();
	void updateTimer();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int getMinutes();

};

#endif