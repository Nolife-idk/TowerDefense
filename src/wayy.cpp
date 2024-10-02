#include "wayy.hpp"
using namespace sf;

Wayy::Wayy(float x, float y, int a, int b)
{
	// size = {a, b};
	shape.setFillColor(Color::Green);
	shape.setPosition(x, y);
	shape.setSize(Vector2f(a, b));
}

void Wayy::draw(sf::RenderWindow& window) {
    window.draw(shape);
}