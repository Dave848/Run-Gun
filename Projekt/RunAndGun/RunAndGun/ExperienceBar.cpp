#include "ExperienceBar.h"

ExperienceBar::ExperienceBar()
{
	font.loadFromFile("open-sans/OpenSans-Regular.ttf");

	emptyBar.setSize(sf::Vector2f(780.f, 15.f));
	emptyBar.setFillColor(sf::Color::Black);
	emptyBar.setOutlineColor(sf::Color::Yellow);
	emptyBar.setOutlineThickness(2.f);
	emptyBar.setPosition(10, 570);

	filledBar.setSize(sf::Vector2f(1.f, 15.f));
	filledBar.setFillColor(sf::Color::Yellow);
	filledBar.setPosition(10, 570);

	expAmount.setFont(font);
	expAmount.setCharacterSize(10);
	expAmount.setFillColor(sf::Color::White);
	expAmount.setOutlineThickness(1.f);
	expAmount.setPosition(sf::Vector2f(365.f, 572.f));
}

void ExperienceBar::updateBar(Hero& hero) {
	if (hero.getExp() > 0) {
		filledBar.setSize(sf::Vector2f(hero.getExp() * (780.f / hero.getMaxExp()), 15.f));
	}
	else {
		filledBar.setSize(sf::Vector2f(1.f, 15.f));
	}
	expAmount.setString("Experience: " + std::to_string(hero.getExp()) + "/" + std::to_string(hero.getMaxExp()));
}

void ExperienceBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(emptyBar, states);
	target.draw(filledBar, states);

	target.draw(expAmount);
}


