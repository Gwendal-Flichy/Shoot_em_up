#include "MilitaryMenu.h"
#include <iostream>
#include <fstream>

MilitaryMenu::MilitaryMenu(sf::RenderWindow& window)
    : window(window)
    , currentMenu(MAIN_MENU)
    , canClick(true)
    , difficultyLevel(0)
    , volumeLevel(0)
{
    
    if (!backgroundTexture.loadFromFile("Texture\\Animation\\water_tileset.png")) {
        std::cerr << "Erreur de chargement de l'image de fond" << std::endl;
        exit(1);
    }

    
    if (!font.loadFromFile("Texture\\Font\\impact.ttf")) {
        std::cerr << "Erreur de chargement de la police Arial" << std::endl;
        exit(1);
    }

    
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;  
        file.close();
    }
    else {
        highScore = 0;  
    }

    highScoreText.setFont(font);
    highScoreText.setString("Meilleur score : " + std::to_string(highScore));
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(window.getSize().x / 2 - highScoreText.getGlobalBounds().width / 2, window.getSize().y / 4 - 50);  // Position en haut du menu principal


    backgroundSprite.setTexture(backgroundTexture);

    float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(backgroundTexture.getSize().x);
    float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(backgroundTexture.getSize().y);

    backgroundSprite.setScale(scaleX, scaleY);
    backgroundSprite.scale(1.5f, 1.5f);
    backgroundSprite.setOrigin(15.f, 15.f);

    title.setFont(font);
    title.setString("MENU PRINCIPAL");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color(255, 165, 0));
    title.setStyle(sf::Text::Bold);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    initButton(startButton, "COMMENCER LA MISSION", window.getSize().y / 4);
    initButton(optionsButton, "OPTIONS", window.getSize().y / 4 + 100);
    initButton(quitButton, "QUITTER", window.getSize().y / 4 + 200);

    initOptionButtons();
    initPauseButtons();
}

MilitaryMenu::~MilitaryMenu() {
    // Pas besoin de g�rer explicitement la musique, car il n'y a plus de musique.
}

void MilitaryMenu::initButton(sf::Text& button, const std::string& text, float positionY) {
    button.setFont(font);
    button.setString(text);
    button.setCharacterSize(30);
    button.setFillColor(sf::Color::Red);
    button.setStyle(sf::Text::Bold);
    button.setPosition(window.getSize().x / 2 - button.getGlobalBounds().width / 2, positionY);
}

void MilitaryMenu::draw() {
    window.clear();
    window.draw(backgroundSprite);

    if (currentMenu == MAIN_MENU) {
        window.draw(title);
        window.draw(startButton);
        window.draw(optionsButton);
        window.draw(quitButton);
    }
    else if (currentMenu == OPTIONS_MENU) {
        window.draw(title);
        window.draw(difficultyButton);
        window.draw(volumeButton);
        window.draw(backButton);
    }
    else if (currentMenu == PAUSE_MENU) {
        window.draw(resumeButton);
        window.draw(quitButton);
    }

    window.display();
}


void MilitaryMenu::checkMouseEvent() {

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    


    
    if (currentMenu == MAIN_MENU) {
        startButton.setFillColor(startButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
        optionsButton.setFillColor(optionsButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
        quitButton.setFillColor(quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
    }
    else if (currentMenu == PAUSE_MENU) {
        resumeButton.setFillColor(resumeButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ?
            sf::Color::Yellow : sf::Color::Red);
        quitButton.setFillColor(quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
    }
    else if (currentMenu == OPTIONS_MENU) {
        difficultyButton.setFillColor(difficultyButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
        volumeButton.setFillColor(volumeButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
        backButton.setFillColor(backButton.getGlobalBounds().contains(mousePos.x, mousePos.y) ? sf::Color::Yellow : sf::Color::Red);
    }
}

std::string MilitaryMenu::getAction() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        canClick = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && canClick) {
        canClick = false;


        if (currentMenu == MAIN_MENU) {
            if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Start";
            if (optionsButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Options";
            if (quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Quit";
        }
        else if (currentMenu == PAUSE_MENU) {
            if (resumeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Resume";
            if (quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Quit";
        }
         else if (currentMenu == OPTIONS_MENU) {
            if (difficultyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Difficulty";
            if (volumeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Volume";
            if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) return "Back";
        }
    }

    return "";
}



void MilitaryMenu::updateDifficulty() {
    difficultyLevel = (difficultyLevel + 1) % 3;
    switch (difficultyLevel) {
    case 0:
        difficultyButton.setString("DIFFICULTE : FACILE");
        break;
    case 1:
        difficultyButton.setString("DIFFICULTE : MOYENNE");
        break;
    case 2:
        difficultyButton.setString("DIFFICULTE : DIFFICILE");
        break;
    }
}

void MilitaryMenu::updateVolume() {
    volumeLevel = (volumeLevel + 1) % 3;
    switch (volumeLevel) {
    case 0:
        volumeButton.setString("Volume : Faible");
        break;
    case 1:
        volumeButton.setString("Volume : Moyen");
        break;
    case 2:
        volumeButton.setString("Volume : Eleve");
        break;
    }
}


void MilitaryMenu::navigateBack() {
    currentMenu = MAIN_MENU;
}

void MilitaryMenu::openOptions() {
    currentMenu = OPTIONS_MENU;
}

void MilitaryMenu::updateHighScore(int newScore) {
    if (newScore > highScore) {
        highScore = newScore;

       
        std::ofstream file("highscore.txt");
        if (file.is_open()) {
            file << highScore;
            file.close();
        }


        highScoreText.setString("Meilleur score : " + std::to_string(highScore));
    }
}

void MilitaryMenu::closePauseMenu() {
    
    currentMenu = MAIN_MENU;  
}



void MilitaryMenu::openPauseMenu() {
    currentMenu = PAUSE_MENU;
}

void MilitaryMenu::initPauseButtons() {
    initButton(resumeButton, "REPRENDRE", window.getSize().y / 4);
    initButton(quitButton, "QUIT", window.getSize().y / 4 + 200);
}

void MilitaryMenu::drawPauseMenu() {
    window.clear(sf::Color(0, 0, 0, 128)); 
    window.draw(backgroundSprite);
    window.draw(resumeButton);
    window.draw(optionsPauseButton);
    window.draw(quitButton);
    window.display();
}


void MilitaryMenu::initOptionButtons() {
    initButton(difficultyButton, "DIFFICULTE : FACILE", window.getSize().y / 4);
    initButton(volumeButton, "VOLUME : FAIBLE", window.getSize().y / 4 + 100);
    initButton(backButton, "RETOUR", window.getSize().y / 4 + 200);
}

