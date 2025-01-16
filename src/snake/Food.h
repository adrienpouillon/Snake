#pragma once
#include <SFML/Graphics.hpp>
#include "InputStockage.h"
#include "Entity.h"
class Food : public Entity
{
protected:
	sf::Vector2f foodPosition;
public:

	Food(sf::Vector2f v2, float& time_between_move, float& current_timer_between_move, GameManager* g);

	void SeachPlace();

	virtual void Action();

	virtual void Show();

	sf::Vector2f GetFoodPosition();
};

