#pragma once
#include <SFML/Graphics.hpp>

#pragma once
#include <SFML/Graphics.hpp>

class Carriage
{
private:
	float speed;
	float width, height;
	float defaultWidth;
	float defaultX;
	float defaultY;
	sf::RectangleShape carriage; 
	bool isBallStuck;

public:
	Carriage(float width, float height, float x, float y, float speed);

	float getX() { return carriage.getPosition().x; }
	float getY() { return carriage.getPosition().y; }
	float getWidth() { return width; }
	float getHeight() { return height; }
	bool getIsBallStuck() { return isBallStuck; } 

	void setIsBallStuck(bool isBallStuck) { this->isBallStuck = isBallStuck; }
	void setWidth(float width) { this->width = width; }

	void draw(sf::RenderWindow& window);
	void move(float windowWidth);

	void loseBall();
};
