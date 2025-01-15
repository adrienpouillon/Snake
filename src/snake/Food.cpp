#include "Food.h"
#include "GameManager.h"


Food::Food(sf::Vector2f v2, float& time_between_move, float& current_timer_between_move, GameManager* g) : Entity(time_between_move, current_timer_between_move, g)
{
	shape = new sf::RectangleShape(v2);
	SeachPlace();
}

void Food::SeachPlace()
{
	std::vector<Snake*> mSnake = GetGameManager()->GetSnake();
	for (Snake* snake : mSnake)
	{
		std::vector<sf::Vector2f> snakeBody = snake->GetSnakeBody();
		std::mt19937 gen = GetGameManager()->GetGen();
		bool found;
		do
		{
			found = false;
			sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
			if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end())
			{
				found = true;
			}
			foodPosition = tmpPosition;
		} while (found);
	}
}

void Food::Action()
{

}

void Food::Show()
{
	ShowWindow(foodPosition, sf::Color::Red);
}

sf::Vector2f Food::GetFoodPosition()
{
	return foodPosition;
}
