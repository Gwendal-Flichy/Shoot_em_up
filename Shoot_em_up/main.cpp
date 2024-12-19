#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
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

    Game game;
    game.run();

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