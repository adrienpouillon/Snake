#include "Entity.h"
#include "GameManager.h"

Entity::Entity(float& time_between_move, float& current_timer_between_move, GameManager* g):time_between_move(time_between_move), current_timer_between_move(current_timer_between_move), g(g)
{
	speed = 1;
}

void Entity::Update(float deltaTime)
{
	if (current_timer_between_move <= 0)
	{
		Action();
		current_timer_between_move += (time_between_move - 0.01f * speed < 0.06f) ? 0.06f : (time_between_move - 0.01f * speed);
	}
	else
	{
		current_timer_between_move -= deltaTime;
	}
}

void Entity::ShowWindow(sf::Vector2f pos, sf::Color)
{
	shape->setPosition(pos * shape->getSize().x);
	shape->setFillColor(sf::Color::Red);
	g->GetWindow()->draw(*shape);
}

GameManager* Entity::GetGameManager()
{
	return g;
}

void Entity::SetSpeed(float newSpeed)
{
	speed = newSpeed;
}
