

#include "Bullet.h"

void Bullet::initBullet(Hero& hero)
{
	bullet.setSize(sf::Vector2f(5.f, 5.f));
	bullet.setFillColor(sf::Color::Red);

	if (hero.getDirection()) {
		bullet.setPosition(hero.getPosition().x + 40, hero.getPosition().y + 30);
	}
	else {
		bullet.setPosition(hero.getPosition().x + 5, hero.getPosition().y + 30);
	}

	bulletSpeed = 5;
	direction = -1;
	bulletStatus = BulletStatus::active;
}

Bullet::Bullet(Hero& hero)
{
	initBullet(hero);
}


void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bullet, states);
}

void Bullet::move()
{
	if (direction) {
		bullet.move(bulletSpeed, 0);
	}
	else {
		bullet.move(-bulletSpeed, 0);
	}
	
}

void Bullet::setDirection(int dir)
{
	direction = dir;
}

void Bullet::toDelete()
{
	bulletStatus = BulletStatus::toDelete;
}

sf::Vector2f Bullet::getPosition()
{
	return bullet.getPosition();
}

int Bullet::getStatus()
{
	return bulletStatus;
}




