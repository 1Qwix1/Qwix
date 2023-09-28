#include "Game.h"

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid"),
field(FIELD_WIDTH, FIELD_HEIGHT, BLOCKS_IN_WIDE, BLOCKS_IN_HEIGHT, SPACE_BLOCK),
carriage(CARRIAGE_WIDTH, CARRIAGE_HEIGHT, CARRIAGE_X, CARRIAGE_Y, CARRIAGE_SPEED),
ball(BALL_X, BALL_Y, BALL_RADIUS, BALL_SPEED), score(0)
{
    window.setFramerateLimit(60); 
}


void Game::run()
{
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) window.close(); 
        }

        window.clear(sf::Color::White);
        move();                          
        drawGame();                      
        handleCollisions();              
        handleBonuses();                 
        window.display();         
        gameEnd();                       
    }
}


void Game::drawGame()
{
    field.draw(window);    
    carriage.draw(window); 
    ball.draw(window);     
    showScore();           
}


void Game::move()
{
    carriage.move(WINDOW_WIDTH); 
    ball.move(carriage);         
}


void Game::handleCollisions()
{
    ball.collideWithWindow(WINDOW_WIDTH, WINDOW_HEIGHT);           
    collideBallWithCarriage();  
    collideBallWithBlocks();   
}

// Обработка бонусов
void Game::handleBonuses()
{
    for (int i = 0; i < bonuses.size(); i++) 
    {
        bonuses.at(i)->draw(window);     
        if (bonuses.at(i)->bonusFall(carriage, ball, WINDOW_HEIGHT)) 
        {
            delete bonuses.at(i);         
            bonuses.erase(bonuses.begin() + i); 
        }
    }
}

void Game::collideBallWithCarriage()
{
    ball.collideWithBlock(carriage.getWidth(), carriage.getHeight(), carriage.getX(), carriage.getY(), carriage.getIsBallStuck());
}

void Game::collideBallWithBlocks()
{
    std::vector<Block*> blocks = field.getBlocks(); 

    for (int i = 0; i < blocks.size(); i++) 
    {
        float blockWidth = blocks.at(i)->getWidth();
        float blockHeight = blocks.at(i)->getHeight();
        float blockX = blocks.at(i)->getX();
        float blockY = blocks.at(i)->getY();
        if (ball.collideWithBlock(blockWidth, blockHeight, blockX, blockY)) 
        {
            if (blocks.at(i)->getIsBlockAccelerate()) ball.changeSpeed(1 + COEFF_SPEED_CHANGE); 
            blocks.at(i)->takeDamage(); 
            if (blocks.at(i)->getHealth() == 0)
            {
                field.deleteBlock(i); 
                score += 1;   
                if (rand() % 100 < BONUS_CHANCE) createBonus(blockWidth, blockHeight, blockX, blockY); 
            }
        }
    }
}


void Game::createBonus(float blockWidth, float blockHeight, float blockX, float blockY)
{
    switch (rand() % BONUS_VALUE) 
    {
    case 0:
        bonuses.push_back(new IncreaseSizeCarriageBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 1:
        bonuses.push_back(new DecreaseSizeCarriageBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 2:
        bonuses.push_back(new IncreaseBallSpeedBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 3:
        bonuses.push_back(new DecreaseBallSpeedBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 4:
        bonuses.push_back(new StickyCarriageBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 5:
        bonuses.push_back(new SafeBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    case 6:
        bonuses.push_back(new RandomTrajectoryBonus(blockX + 0.5 * blockWidth,
            blockY + 0.5 * blockHeight, BONUS_RADIUS, BONUS_SPEED));
        break;
    }
}

// Отображение счета
void Game::showScore()
{
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(FONT_SIZE);
    text.setPosition(TEXT_X, TEXT_Y);
    text.setString(std::to_string(score));
    text.setFillColor(sf::Color::Black);
    window.draw(text);
}

// Завершение игры
void Game::gameEnd()
{
    if (score < 0 || field.isGameEnd()) 
    {
        sf::Font font;
        font.loadFromFile("font.ttf");

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(FONT_SIZE * 2);
        text.setFillColor(sf::Color::Black);

        if (score < 0) text.setString("Defeat");
        if (field.isGameEnd()) text.setString("Victory");

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
        text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        window.clear(sf::Color::White);
        window.draw(text);
        window.display();

        sf::Clock timer;
        while (timer.getElapsedTime().asSeconds() < 3); 
        window.close(); 
    }
}