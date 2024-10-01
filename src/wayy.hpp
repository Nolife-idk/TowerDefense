#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Wayy
{
private:
	/* data */
public:
	sf::RectangleShape shape;
	sf::Vector2f size;
	sf::Vector2f pos;
	Wayy(float x, float y, int a, int b);
	void draw(sf::RenderWindow& window);
};

