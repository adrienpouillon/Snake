#pragma once
#include <SFML/Graphics.hpp>

class ShapeRenderer
{
	sf::RectangleShape shape;
	sf::RenderWindow& window;

public:
	ShapeRenderer(sf::RenderWindow& _window);
	void Update(const sf::Vector2f& _position, const sf::Color& _color);
	void Draw() const;
};

