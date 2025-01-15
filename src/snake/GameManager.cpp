#include "GameManager.h"
#include "Entity.h"
#include "Food.h"
#include "Snake.h"

GameManager::GameManager()
{
	spriteSize = sf::Vector2f(32.f, 32.f);
	
	gen.seed(time(nullptr));

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Snake");

	//Time
	time_between_move = 0.5f;
	current_timer_between_move = 0.f;

	//Snake
	InstanceCreat(new Snake(sf::Vector2f(0.f,0.f), spriteSize, time_between_move, current_timer_between_move, this));
	//Food
	InstanceCreat(new Food(spriteSize, time_between_move, current_timer_between_move, this));
	//Input
	input = new Input(window);

	v = window->getDefaultView();
	v.setCenter(0, 0);

	window->setView(v);

	gameover = false;
}

void GameManager::Run()
{
	// run the program as long as the window is open
	while (window->isOpen())
	{
		//Time
		float deltaTime = c.restart().asSeconds();

		//Input
		InputStockage stokage = input->Update();

		window->clear(sf::Color::Black);
		if (!gameover)
		{
			Update(deltaTime);
		}

		window->display();
	}
}

void GameManager::InstanceCreat(Entity* entity)
{
	//ajouter une instance a mEntities
	mEntities.push_back(entity);
	if (Snake* s = (Snake*)dynamic_cast<Snake*>(entity))
	{
		mSnake.push_back(s);
	}
	if (Food* f = (Food*)dynamic_cast<Food*>(entity))
	{
		mFood.push_back(f);
	}
}

bool GameManager::InstanceDestroy(Entity* entity)
{
	//methode iterator
	//supprimer une instance de mEntities
	bool execution = false;
	for (auto it = mEntities.begin(); it != mEntities.end();)
	{
		if (entity == (*it))
		{
			delete* it;
			it = mEntities.erase(it);
		}
		else
		{
			++it;
		}
	}
	return execution;
}

void GameManager::Update(float deltaTime)
{
	for (Entity* i : mEntities)
	{
		//Update
		i->Update(deltaTime);
	}

	for (Entity* i : mEntities)
	{
		//afficher
		i->Show();
	}
}

GameManager::~GameManager()
{
	delete window;
	delete input;

	//detruire le tableau
	for (Entity* i : mEntities)
	{
		//afficher
		delete i;
	}
	
}

void GameManager::SetGameover(bool gameOver)
{
	gameover = gameOver;
}

std::mt19937 GameManager::GetGen()
{
	return gen;
}

std::vector<Snake*> GameManager::GetSnake()
{
	return mSnake;
}

std::vector<Food*> GameManager::GetFood()
{
	return mFood;
}

std::vector <Entity*> GameManager::GetEntities()
{
	return mEntities;
}

sf::RenderWindow* GameManager::GetWindow()
{
	return window;
}
