#include "Timer.h"

Timer::Timer()
{
	font.loadFromFile("open-sans/OpenSans-Regular.ttf");

	timer.setFont(font);
	timer.setCharacterSize(25);
	timer.setPosition(sf::Vector2f(730.f, 5.f));
	timer.setFillColor(sf::Color::White);
	seconds = 0;
	minutes = 0;
}

void Timer::updateTimer()
{
	seconds = (int)clock.getElapsedTime().asSeconds();
	if (seconds >= 60) {
		minutes++;
		clock.restart();
	}

	if (seconds < 10) {
		timer.setString(std::to_string(minutes) + ":0" + std::to_string(seconds));
		return;
	}
	timer.setString(std::to_string(minutes) + ":" + std::to_string(seconds));
}

void Timer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(timer, states);
}

int Timer::getMinutes()
{
	return minutes;
}
