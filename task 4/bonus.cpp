#include "bonus.h"

Bonus::Bonus(float x, float y, float radius, float speed) :
	radius(radius), bonus(radius), speed(speed)
{
	bonus.setFillColor(sf::Color::Blue);
	bonus.setPosition(x, y);
}

void Bonus::draw(sf::RenderWindow& window)
{
	window.draw(bonus);
}

bool Bonus::bonusFall(Carriage& carriage, Ball& ball, float windowHeight)
{
	float x = bonus.getPosition().x;
	float y = bonus.getPosition().y;
	float carriageX = carriage.getX();
	float carriageY = carriage.getY();

	if (carriageX <= x && x <= carriageX + carriage.getWidth()
		&& carriageY <= y + 2 * radius && y <= carriageY + carriage.getHeight())
	{
		effect(carriage, ball);
		return true;
	}
	else if (y > windowHeight) return true;

	bonus.move(0, speed);
	return false;

}

IncreaseSizeCarriageBonus::IncreaseSizeCarriageBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Green);
}

void IncreaseSizeCarriageBonus::effect(Carriage& carriage, Ball& ball)
{
	carriage.setWidth(carriage.getWidth() + DELTA_CARRIAGE_WIDTH);
}

DecreaseSizeCarriageBonus::DecreaseSizeCarriageBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Red);
}

void DecreaseSizeCarriageBonus::effect(Carriage& carriage, Ball& ball)
{
	carriage.setWidth(carriage.getWidth() - DELTA_CARRIAGE_WIDTH);
}

IncreaseBallSpeedBonus::IncreaseBallSpeedBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Red);
}

void IncreaseBallSpeedBonus::effect(Carriage& carriage, Ball& ball)
{
	ball.changeSpeed(1 + COEFF_SPEED_CHANGE);
}

DecreaseBallSpeedBonus::DecreaseBallSpeedBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Green);
}

void DecreaseBallSpeedBonus::effect(Carriage& carriage, Ball& ball)
{
	ball.changeSpeed(1 - COEFF_SPEED_CHANGE);
}

StickyCarriageBonus::StickyCarriageBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Cyan);
}

void StickyCarriageBonus::effect(Carriage& carriage, Ball& ball)
{
	carriage.setIsBallStuck(true);
}

SafeBonus::SafeBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Magenta);
}

void SafeBonus::effect(Carriage& carriage, Ball& ball)
{
	ball.setIsSafe(true);
}

RandomTrajectoryBonus::RandomTrajectoryBonus(float x, float y, float radius, float speed) :
	Bonus(x, y, radius, speed)
{
	bonus.setFillColor(sf::Color::Black);
}

void RandomTrajectoryBonus::effect(Carriage& carriage, Ball& ball)
{
	ball.randomChangeTrajectory();
}