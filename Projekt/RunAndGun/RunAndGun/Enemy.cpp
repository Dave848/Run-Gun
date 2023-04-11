#include "Enemy.h"

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(enemy, state);
}

Enemy::Enemy()
{
	speed = 0;
	size = sf::Vector2f(28.f, 40.f);
	status = EnemyStatus::activeEnemy;
	rect = sf::Rect<float>(enemy.getPosition(), size);
}

sf::Vector2f Enemy::getPosition()
{
	return enemy.getPosition();
}

void Enemy::toDelete()
{
	status = EnemyStatus::toDeleteEnemy;
}

sf::Rect<float> Enemy::getRect()
{
	return rect;
}

void Enemy::setPosition(sf::Vector2f pos)
{
	enemy.setPosition(pos);
}

int Enemy::getStatus()
{
	return status;
}

float getAngle(Enemy enemy, Hero& hero) {
	float x, y;
	x = abs(enemy.getPosition().x - hero.getPosition().x);
	y = abs(enemy.getPosition().y - hero.getPosition().y);
	return atan(y / x);
}

void Enemy::move(Hero& hero)
{
	//new coordinates
	float x = 0, y = 0;
	rect = sf::Rect<float>(enemy.getPosition(), size);

	float angle = getAngle(*this, hero);

	if (hero.getPosition().x < enemy.getPosition().x) {
		x = -speed;
	}
	if (hero.getPosition().x > enemy.getPosition().x) {
		x = speed;
	}
	
	if (hero.getPosition().y < enemy.getPosition().y) {
		y = -speed;
	}
	if (hero.getPosition().y > enemy.getPosition().y) {
		y = speed;
	}
	
	enemy.move(sf::Vector2f(x*cos(angle), y*sin(angle)));
}

