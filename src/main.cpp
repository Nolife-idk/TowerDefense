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
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Tower Defense");
    
    std::vector<sf::Vector2f> waypoints = {
/////////x////y///////
        {0, 300},//1
        {800, 300},//2
        {800, 800},//3
        {1000, 800},//4
        {1000, 200},//5
        {1600, 200},//6
        {1600, 500},//7
        {1300, 500},//8
        {1300, 700},//9
        {2560, 700}//10
        
    };
    std::vector<sf::Vector2f> cord = {
        {0, 290},//1
        {790, 290},//2
        {790, 790},//3
        {990, 840},//4
        {990, 190},//5
        {1590, 190},//6 good
        {1640, 490},//7
        {1290, 490},//8
        {1290, 690},//9

        
    };
    std::vector<sf::Vector2f> psize = {
        {810, 50},//1
        {50, 510},//2
        {210, 50},//3
        {50, -620},//4
        {610, 50},//5
        {50, 310},//6 good
        {-350, 50},//7 
        {50, 210},//8
        {1260, 50},//9

    };

    Path path(waypoints);
    
    // Enemy enemy(path.getNextWaypoint(0), path);
    bool isPlacingTurret = false;
    sf::RectangleShape turretPreview(sf::Vector2f(100.0f, 100.0f));
    turretPreview.setFillColor(sf::Color(255, 255, 255, 100));
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
             if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) 
            {
                isPlacingTurret = !isPlacingTurret;
                std::cout << (isPlacingTurret ? "enable" : "disable") << std::endl;
            }

            if (isPlacingTurret && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;
                bool canPlaceTower = true;
                float towerWidth = 50.0f;
                float towerHeight = 50.0f;
                float towerWidthb = 100.0f;
                float towerHeightb = 100.0f;
                sf::FloatRect towerBounds(x - towerWidthb / 2.0f, y - towerHeightb / 2.0f, towerWidth, towerHeight);
                for (const Wayy& wayy : ways) 
                {
                if (towerBounds.intersects(wayy.shape.getGlobalBounds())) 
                {
                    canPlaceTower = false;
                    break;
                }
                }
                for (const Tower& tower : towers)  
                {
                    sf::FloatRect existingTowerBounds(tower.shape.getPosition().x, tower.shape.getPosition().y, towerWidth, towerHeight);
                    if (towerBounds.intersects(existingTowerBounds)) 
                    {
                        canPlaceTower = false; 
                        break;
                    }
                }
                if (canPlaceTower == true) 
                {
                    towers.push_back(Tower(x - towerWidth / 2.0f, y - towerHeight / 2.0f));
                }
                else 
                {
                    std::cout << "Can't place tower on the path!" << std::endl;
                }
            }
        }
        if (isPlacingTurret) 
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            turretPreview.setPosition(mousePos.x - turretPreview.getSize().x / 2.0f, mousePos.y - turretPreview.getSize().y / 2.0f);
        }

        if (enemies.size() < 100)
            {
                enemies.push_back(Enemy(path.waypoints[0], path));
            }
        for (int i=0; ways.size() < 9; i++)
        {
            float x1 = cord[i].x;
            float y1 = cord[i].y;

            float a = psize[i].x;
            float b = psize[i].y;

            ways.push_back(Wayy(x1, y1, a, b));

        }
        
        window.clear(sf::Color::Cyan);
        for (Wayy& wayy : ways) {
            
            wayy.draw(window);
            if (isPlacingTurret) 
            {
                sf::RectangleShape pathBorder(wayy.shape.getSize());
                pathBorder.setPosition(wayy.shape.getPosition());
                pathBorder.setFillColor(sf::Color::Transparent);
                pathBorder.setOutlineThickness(2.0f);
                pathBorder.setOutlineColor(sf::Color::Red);
                window.draw(pathBorder);
            }
        }
       
        for (Enemy& enemy : enemies)
        {
            // cout << "tete";
            enemy.move(dt);
            enemy.draw(window); 
        }
        
        for (Tower& tower : towers) {
            tower.draw(window);
            if (isPlacingTurret) 
            {
                sf::RectangleShape towerBorder(sf::Vector2f(100.0f, 100.0f)); // Tower border size
                towerBorder.setPosition(tower.shape.getPosition());
                towerBorder.setFillColor(sf::Color::Transparent);
                towerBorder.setOutlineThickness(2.0f);
                towerBorder.setOutlineColor(sf::Color::Blue); // Blue border for towers
                window.draw(towerBorder);
                window.draw(turretPreview);
            }
        }
        window.display();
    }

    return 0;
}

