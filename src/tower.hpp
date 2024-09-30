#pragma once

#include <SFML/Graphics.hpp>

#ifndef TOWER_HPP
#define TOWER_HPP

class Tower
{
private:
	
public:

	sf::Vector2f size;
	sf::RectangleShape  shape;
	Tower(float x, float y);
	void draw(sf::RenderWindow& window);
};

#endif // TOWER_HPP