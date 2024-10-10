#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <SFML/Graphics.hpp>
#include "path.hpp"

class Enemy
{		
private:

public:
	sf::RectangleShape shape;
	// sf::Vector2f size;
	const Path* path;
	std::size_t currentWaypoint = 0;
	float speed;
	float health;
	bool ded; 
	Enemy(const sf::Vector2f& startPos, const Path* path);

	void move(float dt);
	void draw(sf::RenderWindow& window);
	
};

#endif // ENEMY_HPP