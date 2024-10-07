#pragma once

#include <SFML/Graphics.hpp>
#include "enemy.hpp"

#ifndef TOWER_HPP
#define TOWER_HPP

class Tower
{
private:
	 
public:
	float range;
	float firerate;
	float lastfire;
	sf::Vector2f size;
	sf::RectangleShape  shape;
	Tower(float x, float y);
	void shoot(std::vector<Enemy>& enemies, float dt);

	Enemy* getTarget(std::vector<Enemy>& enemies);

	void draw(sf::RenderWindow& window);
};

#endif // TOWER_HPP