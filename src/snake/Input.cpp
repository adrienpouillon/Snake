#include "Input.h"

Input::Input(sf::RenderWindow* window) : window(window)
{

}

InputStockage Input::Update()
{
	InputStockage stokage;
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (event.type == sf::Event::KeyPressed) 
		{
			if (event.key.scancode == sf::Keyboard::Scancode::Left)
			{
				stokage.snakeDirection = sf::Vector2f(-1, 0);
			}
			if (event.key.scancode == sf::Keyboard::Scancode::Right)
			{
				stokage.snakeDirection = sf::Vector2f(1, 0);
			}
			if (event.key.scancode == sf::Keyboard::Scancode::Up)
			{
				stokage.snakeDirection = sf::Vector2f(0, -1);
			}
			if (event.key.scancode == sf::Keyboard::Scancode::Down)
			{
				stokage.snakeDirection = sf::Vector2f(0, 1);
			}
		}
	}
	return stokage;
}