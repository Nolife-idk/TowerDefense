#include <iostream>
#include <vector>
#include "conf.hpp"
#include "tower.hpp"

int main() 
{
    
    std::vector<Tower> towers;
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
    
    // Main game loop
    while (window.isOpen()) {
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


        window.clear(sf::Color::Cyan);
        for (Tower& tower : towers) {
            tower.draw(window);
        }
        window.display();
    }

    return 0;
}

