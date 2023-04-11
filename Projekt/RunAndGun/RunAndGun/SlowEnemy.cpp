#include "SlowEnemy.h"

SlowEnemy::SlowEnemy()
{
	texture.loadFromFile("slow-enemy.png");
	speed = 1;
	enemy.setTexture(texture);
	enemy.setScale(0.075f, 0.075f);
}
