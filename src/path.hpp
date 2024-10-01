#pragma once

#ifndef PATH_HPP
#define PATH_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Path
{
private:
	/* data */
public:
	std::vector<sf::Vector2f> waypoints;
	Path() = default;
	Path(const std::vector<sf::Vector2f>& points) : waypoints(points) {};

	sf::Vector2f getNextWaypoint(std::size_t currentWaypoint) const {
		if (currentWaypoint < waypoints.size())
		{
			return waypoints[currentWaypoint];
		}
		
		return waypoints.back();
	}
};



#endif // PATH_HPP
