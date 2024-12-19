#ifndef MILITARY_MENU_H
#define MILITARY_MENU_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <string>

class MilitaryMenu {
public:
    enum MenuState {
        MAIN_MENU,
        OPTIONS_MENU,
        PAUSE_MENU 
    };

    MenuState currentMenu; 
    MilitaryMenu(sf::RenderWindow& window);
    ~MilitaryMenu();
    void draw();
    void checkMouseEvent();
    std::string getAction();
    void updateDifficulty();
    void updateVolume();
    void navigateBack();
    void openOptions();
    void openPauseMenu();
    void closePauseMenu();
    void updateHighScore(int newScore);
    void drawPauseMenu();
private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text title;
    sf::Text startButton;
    sf::Text optionsButton;
    sf::Text quitButton;
    sf::Text difficultyButton;
    sf::Text volumeButton;
    sf::Text backButton;
    sf::Text highScoreText;

   
    sf::Text optionsPauseButton;
    sf::Text quitToMenuButton;

    sf::Text resumeButton;  
    sf::Text quitPauseButton; 




    int highScore;
    int difficultyLevel;
    int volumeLevel;
    bool canClick;

    void initButton(sf::Text& button, const std::string& text, float positionY);
    void initOptionButtons();
    void initPauseButtons();


 
};

#endif // MILITARY_MENU_H