#include "carriage.h"

Carriage::Carriage(float width, float height, float x, float y, float speed)
	: defaultWidth(width), height(height), speed(speed), defaultX(x), defaultY(y), width(width), isBallStuck(false)
{
	carriage.setSize(sf::Vector2f(width, height));
	carriage.setPosition(defaultX, defaultY);

	carriage.setFillColor(sf::Color::Blue);
}
void Carriage::draw(sf::RenderWindow& window)
{
	window.draw(carriage);
}
void Carriage::move(float windowWidth)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (carriage.getPosition().x - speed > 0) carriage.move(-speed, 0);
		else carriage.move(-carriage.getPosition().x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (carriage.getPosition().x + width + speed < windowWidth) carriage.move(speed, 0);
		else carriage.move(windowWidth - carriage.getPosition().x - width, 0);
	}
}

void Carriage::loseBall()
{
	width = defaultWidth;
	isBallStuck = false;
	carriage.setPosition(defaultX, defaultY);
}