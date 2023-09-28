#include "ball.h"

Ball::Ball(float x, float y, float radius, float speed) :
	radius(radius), speedX(0), speedY(0), speed(speed), defaultX(x), defaultY(y), relative—arriageX(0), isSafe(false)
{
	ball.setRadius(radius); 
	ball.setOrigin(radius, radius);
	ball.setPosition(defaultX, defaultY);
	ball.setFillColor(sf::Color::Red); 
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

void Ball::move(Carriage& carriage)
{
	if (speedX == 0 && speedY == 0) moveOnCarriage(carriage);
	else ball.move(speedX, speedY);
}

void Ball::moveOnCarriage(Carriage& carriage)
{
	if (!carriage.getIsBallStuck())
	{
		ball.setPosition(carriage.getX() + carriage.getWidth() / 2 - radius, carriage.getY() - 2 * radius);
	}
	else
	{
		ball.setPosition(carriage.getX() + relative—arriageX, carriage.getY() - 2 * radius);
	}
	startMove();
}

void Ball::startMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		speedX = rand() % 2 ? -speed / sqrtf(2) : speed / sqrtf(2);
		speedY = -speed / sqrtf(2);
	}
}

bool Ball::collideWithBlock(float blockWidth, float blockHeight, float blockX, float blockY, bool isCollisionSticky)
{
	bool result = false;

	float x = ball.getPosition().x;
	float y = ball.getPosition().y;

	float leftBound = blockX;
	float rightBound = blockX + blockWidth;
	float upperBound = blockY;
	float lowerBound = blockY + blockHeight;

	bool isLeftBoundCrossed = leftBound <= (x + 2 * radius) && (x + 2 * radius) <= leftBound + speedX;
	bool isRightBoundCrossed = rightBound + speedX <= x && x <= rightBound;
	bool isUpperBoundCrossed = upperBound <= (y + 2 * radius) && (y + 2 * radius) <= upperBound + speedY;
	bool isLowerBoundCrossed = lowerBound + speedY <= y && y <= lowerBound;

	if (leftBound < (x + 2 * radius) && x < rightBound && upperBound < (y + 2 * radius) && y < lowerBound)
	{
		if (isCollisionSticky)
		{
			speedX = speedY = 0;
			relative—arriageX = x - blockX;
		}
		if (isLeftBoundCrossed || isRightBoundCrossed) speedX *= -1;
		if (isUpperBoundCrossed || isLowerBoundCrossed) speedY *= -1;
		result = true;
	}

	return result;
}

void Ball::collideWithWindow(float windowWidth, float windowHeight)
{
	if (ball.getPosition().x < 0 || ball.getPosition().x >(windowWidth - 2 * radius)) speedX *= -1;
	if (ball.getPosition().y < 0) speedY *= -1;
}

int Ball::loseBall(float windowHeight, float windowWidth, Carriage& carriage)
{
	if (ball.getPosition().y + 2 * radius > windowHeight)
	{
		if (isSafe) safeBall();
		else
		{
			ball.setPosition(defaultX, defaultY);
			speedX = 0;
			speedY = 0;
			carriage.loseBall();
			return LOSE_COST;
		}
	}
	return 0;
}

void Ball::changeSpeed(float changeCoefficient)
{
	speedX *= changeCoefficient;
	speedY *= changeCoefficient;
}

void Ball::safeBall()
{
	speedY *= -1;
	isSafe = false;
}

void Ball::randomChangeTrajectory()
{
	switch (rand() % 3)
	{
	case 0:
		speedY *= -1;
		break;
	case 1:
		speedX *= -1;
		break;
	case 2:
		speedY *= -1;
		speedX *= -1;
		break;
	}
}