#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>

#include "Hero.h"
#include "Bullet.h"
#include "ExperienceBar.h"
#include "HealthPoints.h"
#include "Timer.h"

#include "Enemy.h"
#include "SlowEnemy.h"
#include "FastEnemy.h"
#include "ShootingEnemy.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//Enum used to change x and y value of main character
enum Movement {
	LeftUp= -1,
	Neutral = 0,
	RightDown = 1
};

class App
{
private:
	//Window execution
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Hero and bullets
	Hero hero;
	std::vector<Bullet*> bullets;

	//Variables used to move hero
	Movement changeY;
	Movement changeX;

	//Enemies
	std::vector<Enemy*> enemies;
	unsigned int maxEnemies;
	int spawnTimer;
	int maxSpawnTimer;
	
	//Game info
	ExperienceBar expBar;
	HealthPoints healthPoints;
	Timer timer;

	//Initializing stuff
	void initWindow();
	void initVariables();


public:
	//Constructor and destructor
	App();
	~App();
	
	//Functions
	bool running();
	void pollEvent();
	void checkEnd();
	void checkLvlUp();

	//Update
	void update();
	void updateMainChar();
	void updateMainCharBullets();
	void updateEnemies();
	void updateGameInfo();

	void removeObjects();

	//Render
	void render();
	void renderMainChar();
	void renderMainCharBullets();
	void renderGameInfo();
	void renderEnemies();

	//Enemies
	void spawnEnemy();

};


#endif