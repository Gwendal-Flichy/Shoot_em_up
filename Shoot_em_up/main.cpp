#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include "MilitaryMenu.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Militaire");

    // Créer l'instance du menu
    MilitaryMenu menu(window);

    // Boucle principale du menu
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
            Game game(window, menu);  // Créer une instance de votre jeu
            game.run();  // Exécuter le jeu
            gameStarted = true;

            int currentScore = 150;  // Exemple de score atteint à la fin de la mission
            menu.updateHighScore(currentScore);
            menu.navigateBack();  // Retour au menu principal
        }
        if (action == "Options") {
            menu.openOptions();
        }
    

        // Mettre à jour la difficulté
        if (action == "Difficulty") {
            menu.updateDifficulty();
        }

        // Mettre à jour le volume
        if (action == "Volume") {
            menu.updateVolume();
        }

        // Revenir en arrière dans le menu des options
        if (action == "Back") {
            menu.navigateBack();
        }
    }


    return 0;
}
//
//
// 
// 
// 
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Militaire");
//
//    // Créer l'instance du menu
//    MilitaryMenu menu(window);
//
//    // Boucle principale du menu
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // Vérification des événements de souris et dessin
//        menu.checkMouseEvent();
//        menu.draw();
//
//        // Récupération de l'action
//        std::string action = menu.getAction();
//        if (action == "Quit") {
//            // Afficher le message "Vous avez quitté"
//            window.close();  // Fermer la fenêtre
//            break;  // Sortir de la boucle
//        }
//        if (action == "Start") {
//            std::cout << "Mission commencee !" << std::endl;
//            Game game(window, menu);  // Créer une instance de votre jeu
//            game.run();  // Exécuter le jeu
//
//            int currentScore = 150;  // Par exemple, un score atteint à la fin de la mission
//            menu.updateHighScore(currentScore);
//
//            break;  // Sortie de la boucle pour commencer la mission
//        }
//        if (action == "Options") {
//            menu.openOptions();
//        }
//
//        if (action == "Difficulty") {
//            menu.updateDifficulty();
//        }
//        if (action == "Volume") {
//            menu.updateVolume();
//        }
//        if (action == "Back") {
//            menu.navigateBack();
//        }
//    }
//
//
//    return 0;
//}
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

//Pour la detection de collision on utilise un design pattern strategy
// Pour surcharger un operator += le faire dans la fonction membre avec
// friend class
//throw std::runtime_error("Try to remove non existing");
// faire une fonction destroy
//impl�menter les types des objets(ennemi, perso etc...)
//impl�menter un take dammage et initialiser les points de vies
//impl�menter 2 classe EnnemyFireball et PlayerFireball pour r�gler les probl�mes de collisions de l'entit� et la fireball