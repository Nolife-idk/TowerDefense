#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Wayy
{
private:
	/* data */
public:
	sf::RectangleShape shape;
	// sf::Vector2f size;
	// sf::Vector2f pos;
	Wayy(float x, float y, int a, int b);

	bool isPointOnWay(float x, float y) const {
        return shape.getGlobalBounds().contains(x, y);
    }
	
	void draw(sf::RenderWindow& window);
};

