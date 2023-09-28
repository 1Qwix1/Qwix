#pragma once
#include <SFML/Graphics.hpp>
#include "carriage.h"
#include "ball.h"
#include "parameters.h"

class Bonus
{
protected:
	float radius;
	float speed;
	sf::CircleShape bonus;
public:
	Bonus(float x, float y, float radius, float speed);
	bool bonusFall(Carriage& carriage, Ball& ball, float windowHeight);
	void draw(sf::RenderWindow& window);
	virtual void effect(Carriage& carriage, Ball& ball) = 0;
};

class IncreaseSizeCarriageBonus : public Bonus
{
public:
	IncreaseSizeCarriageBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class DecreaseSizeCarriageBonus : public Bonus
{
public:
	DecreaseSizeCarriageBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class IncreaseBallSpeedBonus :public Bonus
{
public:
	IncreaseBallSpeedBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class DecreaseBallSpeedBonus :public Bonus
{
public:
	DecreaseBallSpeedBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class StickyCarriageBonus : public Bonus
{
public:
	StickyCarriageBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class SafeBonus : public Bonus
{
public:
	SafeBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};

class RandomTrajectoryBonus : public Bonus
{
public:
	RandomTrajectoryBonus(float x, float y, float radius, float speed);
	void effect(Carriage& carriage, Ball& ball) override;
};