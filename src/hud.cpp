#include "hud.hpp"
#include <iostream>

Hud::Hud() : towersel(0)
{
	moneyt.setFont(font);
	moneyt.setCharacterSize(200);
	moneyt.setFillColor(sf::Color::White);
	moneyt.setPosition(10, 10);

	pauset.setFont(font);
	pauset.setString("Paused");
	pauset.setCharacterSize(200);
	pauset.setFillColor(sf::Color::White);
	pauset.setPosition(10, 40);

	shape.setSize(sf::Vector2f(2560, 100));
	shape.setFillColor(sf::Color::Black);
	shape.setPosition(0, 1340);
}

void Hud::draw(sf::RenderWindow &window, int money, bool pause)
{
	moneyt.setString("Money: 20 " + std::to_string(money));
	window.draw(shape);
	window.draw(moneyt);
	if (pause)
	{
		window.draw(pauset);
	}
}

void Hud::updatesel(int towersel)
{
	this->towersel = towersel;
}