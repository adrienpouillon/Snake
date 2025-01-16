#include "ShapeRenderer.h"

ShapeRenderer::ShapeRenderer(sf::RenderWindow& _window) : shape(sf::Vector2f(32, 32)), window(_window)
{
}

void ShapeRenderer::Update(const sf::Vector2f& _position, const sf::Color& _color)
{
	shape.setPosition(_position);
	shape.setFillColor(_color);
}

void ShapeRenderer::Draw() const
{
	window.draw(shape);
}

