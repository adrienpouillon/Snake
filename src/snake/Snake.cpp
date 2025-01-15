#include "Snake.h"
#include "GameManager.h"

Snake::Snake(sf::Vector2f pos, sf::Vector2f size, float& time_between_move, float& current_timer_between_move, GameManager* g): Entity(time_between_move, current_timer_between_move, g)
{
	shape = new sf::RectangleShape (size);

	snakeBody.push_back(pos);
	snakeDirection = sf::Vector2f(0, 0);
}

void Snake::Action()
{
	Move();
	SetSpeed((float)snakeBody.size());
}

void Snake::Move()
{
	if (snakeDirection.x != 0 || snakeDirection.y != 0)
	{
		sf::Vector2f nextPosition = snakeBody[0] + snakeDirection;
		if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end())
		{
			CollideFood(nextPosition);
			for (int i = snakeBody.size() - 1; i > 0; --i) {
				snakeBody[i] = snakeBody[i - 1];
			}
			snakeBody[0] = nextPosition;
		}
		else
		{
			GetGameManager()->SetGameover(true);
		}

	}
}

void Snake::CollideFood(sf::Vector2f nextPosition)
{
	std::vector<Food*> mFood = GetGameManager()->GetFood();
	for (Food* food : mFood)
	{
		sf::Vector2f foodPosition = food->GetFoodPosition();
		if (nextPosition == foodPosition)
		{
			SizePlusPlus(food);
		}
	}
}

void Snake::SizePlusPlus(Food* food)
{
	food->SeachPlace();
	snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
}

void Snake::Show()
{
	for (sf::Vector2f p : snakeBody)
	{
		ShowWindow(p, sf::Color::Green);
	}
}


Snake::~Snake()
{
	delete shape;
}

std::vector<sf::Vector2f> Snake::GetSnakeBody()
{
	return snakeBody;
}
