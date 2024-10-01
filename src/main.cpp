#include <iostream>
#include <vector>
#include "conf.hpp"
#include "tower.hpp"
#include "enemy.hpp"
#include "path.hpp"
#include "wayy.hpp"

using namespace std;
int main() 
{
    
    std::vector<Tower> towers;
    std::vector<Wayy> ways;
    std::vector<Enemy> enemies;
    
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
    
    std::vector<sf::Vector2f> waypoints = {
        {100, 300},
        {300, 300},
        {300, 500},
        {600, 500}
    };
    std::vector<sf::Vector2f> trail1 = {
        {100, 300},
        {300, 300},
        {300, 500},
        {600, 500}
    };
    std::vector<sf::Vector2f> trail2 = {
        {100, 300},
        {300, 300},
        {300, 500},
        {600, 500}
    };
    Path path(waypoints);
    
    // Enemy enemy(path.getNextWaypoint(0), path);
    

    sf::Clock deltaClock;

    // Main game loop
    while (window.isOpen()) {
        sf::Time dt_time = deltaClock.restart();
        const float dt = dt_time.asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;
                towers.push_back(Tower(x, y));
            }
            
            
            
        }

        if (enemies.size() < 10)
            {
                enemies.push_back(Enemy(path.waypoints[0], path));
            }
        for (int i=0; ways.size() < 10000; i++)
        {
            ways.push_back(Wayy(i, i, 5, i));
        }
        
        window.clear(sf::Color::Cyan);
        
        for (Enemy& enemy : enemies)
        {
            // cout << "tete";
            enemy.move(dt);
            enemy.draw(window); 
        }
        
        for (Tower& tower : towers) {
            tower.draw(window);
        }
        for (Wayy& wayy : ways) {
            
            wayy.draw(window);
        }
        window.display();
    }

    return 0;
}

