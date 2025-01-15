#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "InputStockage.h"
#include "Food.h"
#include "Snake.h"
#include "Input.h"

class GameManager
{
protected:
	//constante
	std::mt19937 gen;
	sf::RenderWindow* window;
	sf::Vector2f spriteSize;
	sf::View v;
	sf::Clock c;

	//time
	float time_between_move = 0.5f;
	float current_timer_between_move = 0.f;

	//fin
	bool gameover;

	//entity
	std::vector<Snake*> mSnake;
	std::vector<Food*> mFood;
	std::vector<Entity*> mEntities;
	Input* input;

	
public:
	GameManager();
	void Run();
	void InstanceCreat(Entity* entity);
	bool InstanceDestroy(Entity* entity);
	void Update(float deltaTime);
	~GameManager();


	void SetGameover(bool gameOver);
	std::mt19937 GetGen();

	std::vector<Snake*> GetSnake();
	std::vector<Food*> GetFood();
	std::vector<Entity*> GetEntities();
	sf::RenderWindow* GetWindow();
};

