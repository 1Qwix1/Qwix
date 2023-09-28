#pragma once
#include <SFML/Graphics.hpp>
#include "parameters.h"

class Block
{
protected:
	int health;
	float width, height;
	sf::RectangleShape block;
	bool isBlockAccelerate;
public:
	Block(int health, float width, float height, float x, float y, sf::Color color, bool isBlockAccelerate);
	void draw(sf::RenderWindow& window);

	float getX() { return block.getPosition().x; }
	float getY() { return block.getPosition().y; }
	float getWidth() { return width; }
	float getHeight() { return height; }
	int getHealth() { return health; }
	bool getIsBlockAccelerate() { return isBlockAccelerate; }

	void setColor(sf::Color color);

	void takeDamage();
};
