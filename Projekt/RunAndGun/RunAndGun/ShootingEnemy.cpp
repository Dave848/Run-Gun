#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy()
{
	texture.loadFromFile("shooting-enemy.png");
	speed = 2;
	enemy.setTexture(texture);
	enemy.setScale(0.075f, 0.075f);
}

