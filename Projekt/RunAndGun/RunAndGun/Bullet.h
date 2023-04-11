#ifndef BULLET_H
#define BULLET_H

#include "Hero.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum BulletStatus {
	active = 0,
	toDelete = 1
};

class Bullet :public sf::Drawable
{
private:
	sf::RectangleShape bullet;
	float bulletSpeed;
	int direction;
	BulletStatus bulletStatus;

	void initBullet(Hero&);
public:
	Bullet(Hero&);

	sf::Vector2f getPosition();
	int getStatus();
	void setDirection(int);
	void toDelete();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void move();
};


#endif 