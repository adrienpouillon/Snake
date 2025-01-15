#pragma once
#include <SFML/Graphics.hpp>
#include "InputStockage.h"
class Input
{
protected:
	sf::RenderWindow* window;
public:
	Input(sf::RenderWindow* window);

	InputStockage Update();


};

