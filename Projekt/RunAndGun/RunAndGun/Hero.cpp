#include "Hero.h"

void Hero::initHero()
{
	hero.setTexture(texture);
	hero.setPosition(350.f, 280.f);
	hero.setScale(0.125f, 0.125f);
	hero.setOrigin(hero.getGlobalBounds().width / 2, hero.getGlobalBounds().height / 2);
	size = sf::Vector2f(50.f, 50.f);
	rect = sf::Rect(hero.getPosition(), size);
}

void Hero::initVar()
{
	texture.loadFromFile("hero.png");
	reverseTexture.loadFromFile("hero-reverse.png");
	Xscale = 0.125f;
	Xdirection = true;

	maxExp = 10;
	experience = 0;
	lvl = 0;

	healthPoints = 3;
	speed = 2.f;
	shootingSpeed = 0.75f;

	damage = 10;
}

Hero::Hero()
{
	initVar();
	
	initHero();
}

sf::Vector2f Hero::getPosition()
{
	return hero.getPosition();
}

void Hero::turnHeroAround(bool flip)
{
	if (flip != Xdirection) {
		if (Xdirection) {
			hero.setTexture(reverseTexture);
			Xdirection = false;
		}
		else {
			hero.setTexture(texture);
			Xdirection = true;
		}
	}
}

void Hero::minusHP()
{
	healthPoints--;
}

bool Hero::shotCooldown()
{
	if (clock.getElapsedTime().asSeconds() >= shootingSpeed) {
		clock.restart();
		return false;
	}
	return true;
}

int Hero::getMaxExp()
{
	return maxExp;
}

void Hero::plusExp()
{
	experience++;
}

void Hero::levelUp()
{
	lvl++;

	experience = 0;
	shootingSpeed -= 0.05f;
	speed += 0.05f;

	if (lvl % 5 == 0) 
	{
		healthPoints++;
	}

	maxExp += 10;
}

bool Hero::getDirection() 
{
	return Xdirection;
}

int Hero::getHP()
{
	return healthPoints;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hero, states);
}

void Hero::move(int X, int Y, sf::RenderWindow& window)
{
	float newX = hero.getPosition().x + X * speed;
	float newY = hero.getPosition().y + Y * speed;

	if (!Xdirection) {
		if (newX > (float)window.getSize().x)
			newX = static_cast<float>(window.getSize().x);
		if (newX < 45.f)
			newX = 45.f;
	}

	if (Xdirection) {
		if (newX > (float)window.getSize().x - 45.f) 
			newX = static_cast<float>(window.getSize().x - 45.f); 
		if (newX < 0) 
			newX = 0; 
	}

	if (newY > (float)window.getSize().y - 55.f) { newY = static_cast<float>(window.getSize().y - 55.f); }
	if (newY < 0) { newY = 0; }

	rect = sf::Rect(hero.getPosition(), size);
	hero.setPosition(newX, newY);
}

sf::Rect<float> Hero::getRect()
{
	return rect;
}

int Hero::getExp()
{
	return experience;
}
