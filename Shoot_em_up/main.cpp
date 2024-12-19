#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include "MilitaryMenu.h"

    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    window.clear();
    //    window.draw(shape);
    //    window.display();
    //}


    int main() 
    {
        // Créer la fenêtre SFML
        sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Militaire");

        // Créer l'instance du menu
        MilitaryMenu menu(window);

        // Boucle principale du menu
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Vérification des événements de souris et dessin
            menu.checkMouseEvent();
            menu.draw();

            // Récupération de l'action
            std::string action = menu.getAction();
            if (action == "Start") {
                std::cout << "Mission commencee !" << std::endl;
                break;  // Sortie de la boucle pour commencer la mission
            }
            if (action == "Options") {
                menu.openOptions();
            }
            if (action == "Quit") {
                std::cout << "Vous avez quitte !" << std::endl;
                window.close();
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

        // Lancer le jeu
        Game game;  // Créer une instance de votre jeu
        game.run();  // Exécuter le jeu

        // Exemple de mise à jour du score à la fin de la mission
        int currentScore = 150;  // Par exemple, un score atteint à la fin de la mission
        menu.updateHighScore(currentScore);  // Mettre à jour le meilleur score sur l'objet menu

        return 0;
    }
//Pour la detection de collision on utilise un design pattern strategy
// Pour surcharger un operator += le faire dans la fonction membre avec
// friend class
//throw std::runtime_error("Try to remove non existing");
// faire une fonction destroy
//impl�menter les types des objets(ennemi, perso etc...)
//impl�menter un take dammage et initialiser les points de vies
//impl�menter 2 classe EnnemyFireball et PlayerFireball pour r�gler les probl�mes de collisions de l'entit� et la fireball