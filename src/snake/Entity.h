#pragma once
#include <SFML/Graphics.hpp>
class GameManager;

class Entity
{
protected:
	sf::RectangleShape* shape;
	float& time_between_move;
	float& current_timer_between_move;
	float speed;
	GameManager* g;
public:
	Entity(float& time_between_move, float& current_timer_between_move, GameManager* g);
	void Update(float deltaTime);
	virtual void Action() = 0;
	virtual void Show() = 0;
	virtual void ShowWindow(sf::Vector2f pos, sf::Color);

	GameManager* GetGameManager();
	void SetSpeed(float newSpeed);
};

