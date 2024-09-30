#include "tower.hpp"
using namespace sf;

Tower::Tower(float x, float y)
{
	size = {50.0f, 50.0f};
	shape.setFillColor(Color::Blue);
	shape.setPosition(x, y);
	shape.setSize(size);
}

void Tower::draw(sf::RenderWindow& window) {
    window.draw(shape);
}