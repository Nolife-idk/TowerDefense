#include "tower.hpp"
#include <cmath>
#include <iostream>
using namespace sf;

// float range;
// float firerate;
// float lastfire;
Tower::Tower(float x, float y)
{
	size = {50.0f, 50.0f};
	shape.setFillColor(Color::Blue);
	shape.setPosition(x, y);
	shape.setOrigin(-25, -25);
	shape.setSize(size);
	range = 200.0f;
	firerate = 1.0f;
	lastfire = 0.0f;
}
void Tower::shoot(std::vector<Enemy>& enemies, float dt)
{
	lastfire += dt;
        if (lastfire >= 1.0f / firerate) {
            Enemy* target = getTarget(enemies);
            if (target != nullptr) {
                target->health -= 25.0f;
                std::cout << "Tower shoots! Target health: " << target->health << std::endl;
                lastfire = 0.0f;
            }
        }
}
Enemy* Tower::getTarget(std::vector<Enemy>& enemies)
{
	for (Enemy& enemy : enemies) {
            float distance = sqrt(pow(enemy.shape.getPosition().x - shape.getPosition().x, 2) + pow(enemy.shape.getPosition().y - shape.getPosition().y, 2));
            if (distance <= range) {
                return &enemy; 
            }
    }
    return nullptr;
}
void Tower::draw(sf::RenderWindow& window) {
    window.draw(shape);
	sf::CircleShape rangeCircle(range);
    rangeCircle.setFillColor(sf::Color(0, 255, 0, 50));
    rangeCircle.setOrigin(range, range); 
    rangeCircle.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + shape.getSize().y / 2);
    window.draw(rangeCircle);
}