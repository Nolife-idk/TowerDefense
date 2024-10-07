#include "enemy.hpp"
#include <cmath>
#include <iostream>

using namespace sf;

Enemy::Enemy(const sf::Vector2f& startPos, const Path& path): path(path), speed(100.0f), health(100.0f), ded(false)
{
	
	shape.setSize(sf::Vector2f(30, 30));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(startPos);
}

void Enemy::move(float dt)
{
	//  std::cout << "Current Waypoint: " << currentWaypoint << std::endl;
	if (currentWaypoint < path.waypoints.size())
	{
		sf::Vector2f target = path.getNextWaypoint(currentWaypoint);
		sf::Vector2f position = shape.getPosition();
		sf::Vector2f direction = target - position;
		float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (health <= 0)
		{
			ded = true;
		}
		
		else if (distance > 0.1f)
		{
			sf::Vector2f movement = direction /distance * speed *dt;
			shape.move(movement);
		
		} else
		{
			currentWaypoint++;
		}
		
	}
	
}

void Enemy::draw(sf::RenderWindow& window)
{
	if (ded == false)
	{
		window.draw(shape);
	}
	
	
}