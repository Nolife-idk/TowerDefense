#include "enemy.hpp"
#include <cmath>
#include <iostream>

using namespace sf;

Enemy::Enemy(const sf::Vector2f& startPos, const Path& path):
path(path)
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

		if (distance > 0.1f)
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
	window.draw(shape);
}