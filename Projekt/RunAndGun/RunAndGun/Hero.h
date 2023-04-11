#ifndef HERO_H
#define HERO_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Hero : public sf::Drawable
{
private:
	sf::Sprite hero;
	sf::Texture texture;
	sf::Texture reverseTexture;

	sf::Rect<float> rect;
	sf::Vector2f size;
	float Xscale;
	bool Xdirection;

	// Different stats
	int experience;
	int maxExp;

	int lvl;
	int healthPoints;
	
	float speed;
	int damage;

	sf::Clock clock;
	float shootingSpeed;

	//Initialize variables and character
	void initHero();
	void initVar();
public:
	//Constructor
	Hero();

	int getHP();
	int getMaxExp();
	int getExp();
	bool getDirection();
	sf::Vector2f getPosition();
	sf::Rect<float> getRect();
	
	void levelUp();
	void plusExp();
	void minusHP();
	bool shotCooldown();
	void turnHeroAround(bool);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void move(int, int, sf::RenderWindow&);

};

#endif

