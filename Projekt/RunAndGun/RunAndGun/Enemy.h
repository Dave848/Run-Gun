#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>
#include <iostream>
#include "Hero.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum EnemyStatus {
	activeEnemy = 0,
	toDeleteEnemy = 1
};

class Enemy : public sf::Drawable
{
protected:
	sf::Sprite enemy;
	sf::Texture texture;
	sf::Rect<float> rect;
	sf::Vector2f size;

	float speed;
	EnemyStatus status;

public:
	Enemy();
	void move(Hero&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	void setPosition(sf::Vector2f pos);

	sf::Vector2f getPosition();
	sf::Rect<float> getRect();
	int getStatus();
	void toDelete();
};
#endif