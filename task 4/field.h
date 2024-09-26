#pragma once
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "block.h"
#include "parameters.h"

class Field
{
private:

	float width, height;
	int blocksInWide, blocksInHeight;
	float spaceBlock;
	std::vector <Block*> blocks;
	std::vector <sf::Color> colors{ sf::Color::Black, sf::Color{0xffa500ff}, sf::Color::Yellow };

public:
	Field(float width, float height, int blocksWide, int blocksHeight, float spaceBlock);

	std::vector <Block*>& getBlocks() { return blocks; }

	void draw(sf::RenderWindow& window);
	void generateBlocks();
	void selectBlockType(sf::Color& blockColor, int& blockHealth);
	void deleteBlock(int index);
	bool isGameEnd();
};