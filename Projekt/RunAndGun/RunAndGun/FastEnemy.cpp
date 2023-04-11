#include "FastEnemy.h"

FastEnemy::FastEnemy()
{
	texture.loadFromFile("fast-enemy.png");
	speed = 3;
	enemy.setTexture(texture);
	enemy.setScale(0.075f, 0.075f);
}
