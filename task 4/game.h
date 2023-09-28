#pragma once
#include <SFML/Graphics.hpp>
#include "parameters.h"
#include "field.h"
#include "carriage.h"
#include "ball.h"
#include "bonus.h"

class Game
{
private:
	sf::RenderWindow window;
	Field field;
	Carriage carriage;
	Ball ball;
	std::vector <Bonus*> bonuses;

	int score;
public:
	Game();
	void run();
	void drawGame();
	void move();
	void handleCollisions();
	void collideBallWithCarriage();
	void collideBallWithBlocks();
	void showScore();
	void gameEnd();
	void createBonus(float blockWidth, float blockHeight, float blockX, float blockY);
	void handleBonuses();
};
