#pragma once
#include <SFML/Graphics.hpp>
#include "InputStockage.h"
#include "Entity.h"
#include "Food.h"
class Snake: Entity
{
protected:
	std::vector<sf::Vector2f> snakeBody;
	sf::Vector2f snakeDirection;

public:

	Snake(sf::Vector2f pos, sf::Vector2f size, float& time_between_move, float& current_timer_between_move, GameManager* g);

	void Action();

	void Move();

	void CollideFood(sf::Vector2f nextPosition);

	void SizePlusPlus(Food* food);

	virtual void Show();

	~Snake();

	std::vector<sf::Vector2f> GetSnakeBody();
};

