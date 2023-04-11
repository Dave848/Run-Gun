#include "App.h"
#include <stdlib.h>
#include <time.h>

void App::initWindow()
{
	window = new sf::RenderWindow(videoMode, "Run&Gun");
	window->setFramerateLimit(60);
}

void App::initVariables()
{
	srand((unsigned int)time(NULL));

	videoMode.width = 800;
	videoMode.height = 600;

	healthPoints = HealthPoints(hero);

	maxEnemies = 20;
	maxSpawnTimer = 60;
	spawnTimer = maxSpawnTimer;
}

//Constructor and destructor
App::App()
{
	initVariables();
	initWindow();
}

App::~App()
{
	delete window;
}


//Methods
bool App::running()
{
	return window->isOpen();
}

//Update Game engine
void App::update()
{
	pollEvent();

	//Game objects
	updateMainChar();
	updateMainCharBullets();
	updateEnemies();

	checkEnd();
	checkLvlUp();

	updateGameInfo();

	removeObjects();
}

void App::updateMainChar()
{
	hero.move(changeX, changeY, *window);
}

void App::updateMainCharBullets()
{
	float posX, posY;
	for (auto bullet : bullets)
	{
		posX = bullet->getPosition().x;
		posY = bullet->getPosition().y;
		if (posX > (float)window->getSize().x || posX < 0 || posY > (float)window->getSize().y || posY < 0)
		{
			bullet->toDelete();
		}
		
		bullet->move();
	}
}

void App::updateEnemies()
{
	// Increase spawn rate
	maxSpawnTimer = 60 - (timer.getMinutes()*2.5);

	// Spawn enemy
	if (!(enemies.size() >= maxEnemies)) {
		if (spawnTimer >= maxSpawnTimer){
			spawnEnemy();
			spawnTimer = 0;
		}
		else {
			spawnTimer += 1;
		}
	}

	// Move/Delete enemy
	for(auto enemy : enemies)
	{
		enemy->move(hero);

		if (enemy->getRect().intersects(hero.getRect())) {
			enemy->toDelete();
			hero.minusHP();
		}

		for (auto bullet : bullets) {
			if (enemy->getRect().contains(bullet->getPosition())) {
				enemy->toDelete();
				bullet->toDelete();
				
				hero.plusExp();
			}	
		}
	}
}

void App::updateGameInfo()
{
	expBar.updateBar(hero);

	timer.updateTimer();

	healthPoints.updateHeatlhPoints(hero);
}

void App::removeObjects()
{
	//Remove bullets
	for(unsigned int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->getStatus()) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}

	//Remove Enemies
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->getStatus()) {
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}
	}
}

void App::pollEvent()
{
	//Event polling
	while (window->pollEvent(ev))
	{
		Bullet* bullet = new Bullet(hero);
		switch (ev.type)
		{
		//Pressed X on titlebar
		case sf::Event::Closed:
			window->close();
			break;

		//Pressed keyboard key
		case sf::Event::KeyPressed:
			switch (ev.key.code)
			{
			//Leave program on "escape"
			case sf::Keyboard::Escape:	 window->close(); break;

			//Switching flags to move character
			case sf::Keyboard::W:	
				changeY = Movement::LeftUp; 
				break;

			case sf::Keyboard::S:
				changeY = Movement::RightDown;
				break;

			case sf::Keyboard::A:		
				hero.turnHeroAround(false);
				changeX = Movement::LeftUp;
				break;

			case sf::Keyboard::D:		
				hero.turnHeroAround(true);
				changeX = Movement::RightDown; 
				break;

			//New bullets
			case sf::Keyboard::Left:

				//Check shot cooldown
				if (hero.shotCooldown()) { break; }
				
				//Making sure that hero is not shooting from his back
				hero.turnHeroAround(false);
				

				//New bullet to left
				bullet->setDirection(0);
				bullets.push_back(bullet);
				break;

			case sf::Keyboard::Right:
				
				//Check shot cooldown
				if (hero.shotCooldown()) { break; }

				//Making sure that hero is not shooting from his back
				hero.turnHeroAround(true);

				//New bullet to right
				bullet->setDirection(1);
				bullets.push_back(bullet);
				break;

			default: break;
			}
			break;

		//Released keyboard key
		case sf::Event::KeyReleased:
			switch (ev.key.code)
			{
			//Switching flags to move character
			case sf::Keyboard::W:		changeY = Movement::Neutral; break;
			case sf::Keyboard::S:		changeY = Movement::Neutral; break;
			case sf::Keyboard::A:		changeX = Movement::Neutral; break;
			case sf::Keyboard::D:		changeX = Movement::Neutral; break;
			default: break;
			}
			break;

		default:
			break;
		}
	}
}

void App::checkEnd()
{
	if (hero.getHP() <= 0) {
		window->close();
	}
}

void App::checkLvlUp()
{
	if (hero.getExp() >= hero.getMaxExp()) {
		hero.levelUp();
	}
}

//Updating window (interface)
void App::render()
{
	window->clear(sf::Color::Black);

	renderEnemies();

	renderMainChar();

	renderMainCharBullets();

	renderGameInfo();

	window->display();
}

void App::renderMainChar()
{
	window->draw(hero);
}

void App::renderMainCharBullets()
{
	for (auto bullet : bullets) 
	{
		window->draw(*bullet);
	}
}

void App::renderGameInfo()
{
	window->draw(expBar);
	window->draw(timer);
	healthPoints.draw(window);
}

void App::renderEnemies()
{
	for(auto enemy:enemies)
	{
		window->draw(*enemy);
	}
}

void App::spawnEnemy()
{
	Enemy* newEnemy = new SlowEnemy;
	switch ((rand() % 3)) {
	case 0:
		newEnemy = new SlowEnemy;
		break;
	case 1:
		newEnemy = new FastEnemy;
		break;
	case 2:
		newEnemy = new ShootingEnemy;
		break;
	}
	float x, y;

	if (rand() % 11 > 5) {
		x = static_cast<float>(rand() % 30 + 840);
	}
	else {
		x = static_cast<float>(-(rand() % 30) - 40);
	}

	y = static_cast<float>((rand() % 500) + 50);

	newEnemy->setPosition(sf::Vector2f(x, y));
	enemies.push_back(newEnemy);
}
