#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Hud
{
private:

public:
	sf::RectangleShape shape;
	sf::Text moneyt;
	sf::Text pauset;
	sf::Font font;
	int towersel;
	Hud();
	void draw(sf::RenderWindow& window, int money, bool pause);
	void updatesel(int towersel);
};