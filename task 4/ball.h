#pragma once
#include <SFML/Graphics.hpp>
#include "carriage.h"
#include "block.h"

#define LOSE_COST 5

class Ball
{
private:
	float radius;
	float speedX, speedY;
	float speed;
	float defaultX, defaultY;
	float relativeÑarriageX;
	sf::CircleShape ball; // Èçìåíåíî: Sprite íà CircleShape
	bool isSafe;
public:
	Ball(float x, float y, float radius, float speed);
	void draw(sf::RenderWindow& window);

	void move(Carriage& carriage);
	void moveOnCarriage(Carriage& carriage);
	void startMove();
	void changeSpeed(float changeCoefficient);
	void randomChangeTrajectory();

	void setIsSafe(bool isSafe) { this->isSafe = isSafe; }

	void collideWithWindow(float windowWidth, float windowHeight);
	bool collideWithBlock(float blockWidth, float blockHeight, float blockX, float blockY, bool isCollisionSticky = 0);

	int loseBall(float windowHeight, float windowWidth, Carriage& carriage);
	void safeBall();
};
