#include "block.h"

Block::Block(int health, float width, float height, float x, float y, sf::Color color, bool isBlockAccelerate) :
	health(health), width(width), height(height), block(sf::Vector2f(width, height)), isBlockAccelerate(isBlockAccelerate)
{
	block.setPosition(x, y);
	block.setFillColor(color);
}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Block::takeDamage()
{
	if (health > 0) health--;
}

void Block::setColor(sf::Color color)
{
	block.setFillColor(color);
}