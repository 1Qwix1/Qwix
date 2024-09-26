#include "field.h"

Field::Field(float width, float height, int blocksInWide, int blocksInHeight, float spaceBlock) :
	width(width), height(height), blocksInWide(blocksInWide), blocksInHeight(blocksInHeight), spaceBlock(spaceBlock)
{
	generateBlocks();
}



void Field::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		Block* block = blocks.at(i);
		if (block->getHealth() == -1) block->setColor(colors.at(0));
		else block->setColor(colors.at(block->getHealth()));
		block->draw(window);
	}
}

void Field::generateBlocks()
{
	float blockWidth = width / blocksInWide - spaceBlock;
	float blockHeight = height / blocksInHeight - spaceBlock;
	float x, y;
	int blockHealth;
	sf::Color blockColor;
	for (int i = 0; i < blocksInHeight; i++)
	{
		for (int j = 0; j < blocksInWide; j++)
		{
			x = (blockWidth + spaceBlock) * j + spaceBlock / 2.0;
			y = (blockHeight + spaceBlock) * i + spaceBlock / 2.0;
			selectBlockType(blockColor, blockHealth);
			bool isBlockAccelerate = rand() % 100 < CHANCE_ACCELERATE_BLOCK ? true : false;
			blocks.push_back(new Block(blockHealth, blockWidth, blockHeight, x, y, blockColor, isBlockAccelerate));
		}
	}
}

void Field::deleteBlock(int index)
{
	delete blocks.at(index);
	blocks.erase(blocks.begin() + index);
}

void Field::selectBlockType(sf::Color& blockColor, int& blockHealth)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);
	int blockType = dis(gen);
	switch (blockType)
	{
	case 1:
		blockColor = colors.at(0);
		blockHealth = -1;
		break;

	case 2:
		blockColor = colors.at(2);
		blockHealth = 2;
		break;

	default:
		blockColor = colors.at(1);
		blockHealth = 1;
		break;
	}
}

bool Field::isGameEnd()
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks.at(i)->getHealth() > 0) return false;
	}
	return true;
}