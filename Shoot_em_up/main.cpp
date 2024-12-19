#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include "MilitaryMenu.h"



int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Militaire");
    
    MilitaryMenu menu(window);

    
    bool gameStarted = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        menu.checkMouseEvent();
        menu.draw();

        std::string action = menu.getAction();

        if (action == "Quit") {
            window.close();
            break;
        }

        if (action == "Start" && !gameStarted) {
            std::cout << "Mission commencee !" << std::endl;
            Game game(window, menu);  
            game.run();  
            gameStarted = true;

            int currentScore = 150;  
            menu.updateHighScore(currentScore);
            menu.navigateBack();  
        }
        if (action == "Options") {
            menu.openOptions();
        }


        
        if (action == "Difficulty") {
            menu.updateDifficulty();
        }

        
        if (action == "Volume") {
            menu.updateVolume();
        }

        
        if (action == "Back") {
            menu.navigateBack();
        }
    }


    return 0;
}
